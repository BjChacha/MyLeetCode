
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

QUERY_PROBLEM_INFO = 'query questionData($titleSlug: String!) {\n    question(titleSlug: $titleSlug) {\n        questionFrontendId\n        title\n        difficulty\n        categoryTitle\n        topicTags {\n            name\n            slug\n            translatedName\n            __typename\n        }\n        stats\n        __typename\n    }\n}'
QUERY_DIFFICULTY_NUMBER = '\n    query userSessionProgress($username: String!) {\n  allQuestionsCount {\n    difficulty\n    count\n  }\n  matchedUser(username: $username) {\n    submitStats {\n      acSubmissionNum {\n        difficulty\n        count\n        submissions\n      }\n      totalSubmissionNum {\n        difficulty\n        count\n        submissions\n      }\n    }\n  }\n}\n    '

DIR_LEETCODE_PROBLEM = 'LeetCode/Problems'
DIR_LCOF = 'LeetCode/StudyPlan/剑指Offer'
DIR_ACWING_PROBLEM = 'AcWing/Problems'

DIRS = {
    1: DIR_LEETCODE_PROBLEM,
    2: DIR_LCOF,
    3: DIR_ACWING_PROBLEM,
}

URL_GRAPHQL_LEETCODE = 'https://leetcode.com/graphql/'
URL_GRAPHQL_LEETCODECN = 'https://leetcode-cn.com/graphql/'

HEADER =  {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.60 Safari/537.36 Edg/100.0.1185.29',
}
