

import requests
from bs4 import BeautifulSoup as bs


def main():
    url_leetcode_graphql = 'https://leetcode.com/graphql/'
    header = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.60 Safari/537.36 Edg/100.0.1185.29',
    }
    data = None
    problem_name = None
    
    while True:
        try:
            url_leetcode_problem = input("Enter url of leetcode problem: ")
            if url_leetcode_problem == 'q':
                break
            problem_name = url_leetcode_problem.strip().strip('/').split('/')[-1]
            data = {
        "operationName": "questionData",
        "variables": {
            "titleSlug": f"{problem_name}"
            },
        "query": '''query questionData($titleSlug: String!) {
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
    }
            
            my_request = requests.post(url_leetcode_graphql, headers=header, json=data)
            content = my_request.json()
            topics = [t['name'] for t in content['data']['question']['topicTags']]
            print("="*50)
            print(f"Problem name:       {content['data']['question']['title'] : >40}")
            print(f"Problem no:         {content['data']['question']['questionFrontendId'] : >40}")
            print(f"Problem difficulty: {content['data']['question']['difficulty'] : >40}")
            print("Problem tags:")
            for t in topics:
                print(f"\t{t}")
            print("="*50)
        except:
            print("Not a supported url, try again.")

if __name__ == '__main__' :
    main()