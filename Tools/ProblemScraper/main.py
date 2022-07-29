from asyncio.windows_events import NULL
from lib2to3.pytree import convert
import sys
sys.path.append('Tools')
sys.path.append('..')
from const import *
import requests
from bs4 import BeautifulSoup as bs
import os
import re

def get_problem_info(url, flag):
    res = None
    if flag == 1 or flag == 2:
        res = convertLeetCodeData(get_problem_info_LeetCode(url), flag)
    elif flag == 3:
        res = get_problem_info_AcWing(url)
    res['url'] = url
    res['flag'] = flag
    return res

def get_problem_info_LeetCode(url):
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

def get_problem_info_AcWing(url):
    try:
        page = requests.get(url)
        soup = bs(page.text, 'lxml')
        data = {}

        data['id'], data['title'] = soup.find('div', {'class': 'problem-content-title'}).text.strip().split('.')
        data['title'] = data['title'].strip()
        data['difficulty'] = soup.find('table', {'class': 'table-striped'}).tbody.td.span.text
        data['tags'] = re.findall(r'keywords = \".*\"', soup.find('table', {'class': 'table-responsive'}).script.text)[0].split('=')[1].strip(' "').split(',')

        return data
    except:
        print('Get AcWing problem failed.')

def convertLeetCodeData(data, flag):
    converted = {}
    converted['title'] = data['data']['question']['title'].replace('?', '')
    if flag == 2:
        converted['title'] = converted['title'].split()[0]
    converted['id'] = data['data']['question']['questionFrontendId']
    converted['difficulty'] = data['data']['question']['difficulty']
    converted['tags'] = [t['name'] for t in data['data']['question']['topicTags']]

    return converted

def build_template(data):
    problem_title = data['title']
    # problem_title = problem_title.replace('?', '')
    # if data['flag'] == 2:
    #     problem_title = problem_title.split()[0]
    problem_no = data['id']
    problem_difficulty = data['difficulty']
    problem_tags = f"[{', '.join(data['tags'])}]"
    
    source = 'LeetCode'
    if data['flag'] == 3:
        source = 'AcWing'
    
    folder_name = f"{DIRS[data['flag']]}/{problem_no}. {problem_title}"
    file_name = '/'.join([folder_name, 'README.md'])

    if os.path.isdir(folder_name):
        print(f'Folder {folder_name} is existed.')
    else:
        os.makedirs(folder_name)

    if os.path.isfile(file_name):
        print(f'File {file_name} is existed.')
    else:
        content = FRONT_MATTER_TEMPLATE.format(
            title=problem_title,
            no=problem_no,
            difficulty=problem_difficulty,
            tags=problem_tags,
            url=data['url'],
            source=source,
            )
        with open(file_name, 'w', encoding='utf-8') as f:
            f.writelines(content)

def url_preprocesser(url):
    if url.endswith('submissions/'):
        url = url[:-12]

    # TODO: 自适应识别url种类    
    # t = ''
    # if 'leetcode' in url.lower():
    #     t = 'leetcode'
    # elif 'acwing' in url.lower():
    #     t = 'acwing'
    return url

def main():
    while True:
        try:
            flag = input("Enter problem type:\n\t[q]: Exit\n\t[1]: LeetCode Problem\n\t[2]: LeetCode-CN 剑指 Offer\n\t[3]: AcWing\n") or '0'
            if flag == 'q':
                break
            flag = int(flag)
            if flag not in [1, 2, 3]:
                raise ValueError

            url = input("Enter LeetCode problem url: ")
            url = url_preprocesser(url)
            data = get_problem_info(url, flag)
            build_template(data)

        except ValueError:
            print("Invalid type.")

if __name__ == '__main__':
    main()
