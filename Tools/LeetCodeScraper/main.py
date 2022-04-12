import difflib
import requests
import os

FRONT_MATTER_TEMPLATE = '''---
title: {title}
no: {no}
difficulty: {difficulty}
tags: {tags}
url: {url}
---

# {no}. {title}

[Leetcode]({url})

'''

QUERY_PROBLEM = '''
query questionData($titleSlug: String!) {
    question(titleSlug: $titleSlug) {
        questionId
        questionFrontendId
        boundTopicId
        title
        titleSlug
        content
        translatedTitle
        translatedContent
        isPaidOnly
        difficulty
        likes
        dislikes
        isLiked
        similarQuestions
        exampleTestcases
        categoryTitle
        contributors {
            username
            profileUrl
            avatarUrl
            __typename
        }
        topicTags {
            name
            slug
            translatedName
            __typename
        }
        companyTagStats
        codeSnippets {
            lang
            langSlug
            code
            __typename
        }
        stats
        hints
        solution {
            id
            canSeeDetail
            paidOnly
            hasVideoSolution
            paidOnlyVideo
            __typename
        }
        status
        sampleTestCase
        metaData
        judgerAvailable
        judgeType
        mysqlSchemas
        enableRunCode
        enableTestMode
        enableDebugger
        envInfo
        libraryUrl
        adminUrl
        challengeQuestion {
            id
            date
            incompleteChallengeCount
            streakCount
            type
            __typename
        }
        __typename
    }
}'''

QUERY_PROBLEM_CN = '''
query questionData($titleSlug: String!) {
    question(titleSlug: $titleSlug) {
    questionId
    questionFrontendId
    categoryTitle
    boundTopicId
    title
    titleSlug
    content
    translatedTitle
    translatedContent
    isPaidOnly
    difficulty
    likes
    dislikes
    isLiked
    similarQuestions
    contributors {
        username
        profileUrl
        avatarUrl
        __typename
    }
    langToValidPlayground
    topicTags {
        name
        slug
        translatedName
        __typename
    }
    companyTagStats
    codeSnippets {
        lang
        langSlug
        code
        __typename
    }
    stats
    hints
    solution {
        id
        canSeeDetail
        __typename
    }
    status
    sampleTestCase
    metaData
    judgerAvailable
    judgeType
    mysqlSchemas
    enableRunCode
    envInfo
    book {
        id
        bookName
        pressName
        source
        shortDescription
        fullDescription
        bookImgUrl
        pressImgUrl
        productUrl
        __typename
    }
    isSubscribed
    isDailyQuestion
    dailyRecordStatus
    editorType
    ugcQuestionId
    style
    exampleTestcases
    __typename
    }
}
'''

DIR_PROBLEM = "Problems"
DIR_LCOF = "StudyPlan/剑指Offer"

DIRS = {
    1: DIR_PROBLEM,
    2: DIR_LCOF
}

URL_GRAPHQL_LEETCODE = 'https://leetcode.com/graphql/'
URL_GRAPHQL_LEETCODECN = 'https://leetcode-cn.com/graphql/'

def get_problem_info(url, flag):
    if url.endswith('submissions/'):
        url = url[-12:]
    url_leetcode_problem = url
    items = url_leetcode_problem.strip().strip('/').split('/')
    problem_name = items[4]

    url_leetcode_graphql = URL_GRAPHQL_LEETCODE if flag == 1 else URL_GRAPHQL_LEETCODECN
    
    header = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.60 Safari/537.36 Edg/100.0.1185.29',
    }
    data = {
        "operationName": "questionData",
        "variables": {
            "titleSlug": f"{problem_name}"
        },
        "query": QUERY_PROBLEM if flag == 1 else QUERY_PROBLEM_CN,
    }

    my_request = requests.post(url_leetcode_graphql, headers=header, json=data)
    content = my_request.json()

    return content


def build_template(data, url, flag):
    problem_title = data['data']['question']['title']
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
            data = get_problem_info(url, flag)
            build_template(data, url, flag)

        except ValueError:
            print("Invalid type.")

if __name__ == '__main__':
    main()
