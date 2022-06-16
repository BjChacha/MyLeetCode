import sys
sys.path.append('Tools')
sys.path.append('..')
from var import *
import requests
import os

def get_problem_info(url, flag):
    url_leetcode_problem = url
    items = url_leetcode_problem.strip().strip('/').split('/')
    problem_name = items[4]

    url_leetcode_graphql = URL_GRAPHQL_LEETCODECN if '-cn' in url else URL_GRAPHQL_LEETCODE
    header = HEADER
    q = QUERY_PROBLEM_INFO

    data = {
        "operationName": "questionData",
        "variables": {
            "titleSlug": f"{problem_name}"
        },
        "query": q,
    }

    my_request = requests.post(url_leetcode_graphql, headers=header, json=data)
    content = my_request.json()

    return content


def build_template(data, url, flag):
    problem_title = data['data']['question']['title']
    problem_title = problem_title.replace('?', '')
    if flag == 2:
        problem_title = problem_title.split()[0]
    problem_no = data['data']['question']['questionFrontendId']
    problem_difficulty = data['data']['question']['difficulty']
    problem_tags = f"[{', '.join(t['name'] for t in data['data']['question']['topicTags'])}]"
    
    folder_name = f"{DIRS[flag]}/{problem_no}. {problem_title}"
    file_name = '/'.join([folder_name, 'README.md'])

    if os.path.isdir(folder_name):
        print(f'Folder {folder_name} is existed.')
    else:
        os.mkdir(folder_name)

    if os.path.isfile(file_name):
        print(f'File {file_name} is existed.')
    else:
        content = FRONT_MATTER_TEMPLATE.format(
            title=problem_title,
            no=problem_no,
            difficulty=problem_difficulty,
            tags=problem_tags,
            url=url)
        with open(file_name, 'w', encoding='utf-8') as f:
            f.writelines(content)

def url_preprocesser(url):
    if url.endswith('submissions/'):
        url = url[:-12]
    return url

def main():
    while True:
        try:
            flag = input("Enter problem type:\n\t[q]: Exit\n\t[1]: LeetCode Problem\n\t[2]: LeetCode-CN 剑指 Offer\n") or '0'
            if flag == 'q':
                break
            flag = int(flag)
            if flag not in [1, 2]:
                raise ValueError

            url = input("Enter LeetCode problem url: ")
            url = url_preprocesser(url)
            data = get_problem_info(url, flag)
            build_template(data, url, flag)

        except ValueError:
            print("Invalid type.")

if __name__ == '__main__':
    main()
