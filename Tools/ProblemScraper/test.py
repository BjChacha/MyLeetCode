# {
#   "question_id": "198",
#   "data_input": "[1,2,3,1]",
#   "lang": "javascript",
#   "typed_code": "/**\n * @param {number[]} nums\n * @return {number}\n */\nvar rob = function(nums) {\n    const n = nums.length;\n    if (n < 2) return Math.max(...nums);\n    let first = nums[0], second = Math.max(nums[0], nums[1]);\n    for (let i = 2; i < n; ++i) [first, second] = [second, Math.max(first + nums[i], second)];\n    return second;\n};",
#   "judge_type": "large"
# }

# {
#     "operationName": "globalData",
#     "variables": {},
#     "query": "query globalData {\n  feature {\n    questionTranslation\n    subscription\n    signUp\n    discuss\n    mockInterview\n    contest\n    store\n    chinaProblemDiscuss\n    socialProviders\n    studentFooter\n    enableChannels\n    dangerZone\n    enableSharedWorker\n    enableRecaptchaV3\n    enableDebugger\n    enableDebuggerPremium\n    enableAutocomplete\n    enableAutocompletePremium\n    enableAllQuestionsRaw\n    autocompleteLanguages\n    enableIndiaPricing\n    enableReferralDiscount\n    maxTimeTravelTicketCount\n    enableStoreShippingForm\n    enableCodingChallengeV2\n    __typename\n  }\n  streakCounter {\n    streakCount\n    daysSkipped\n    currentDayCompleted\n    __typename\n  }\n  currentTimestamp\n  userStatus {\n    isSignedIn\n    isAdmin\n    isStaff\n    isSuperuser\n    isMockUser\n    isTranslator\n    isPremium\n    isVerified\n    checkedInToday\n    username\n    realName\n    avatar\n    optedIn\n    requestRegion\n    region\n    activeSessionId\n    permissions\n    notificationStatus {\n      lastModified\n      numUnread\n      __typename\n    }\n    completedFeatureGuides\n    __typename\n  }\n  siteRegion\n  chinaHost\n  websocketUrl\n  recaptchaKey\n  recaptchaKeyV2\n  sitewideAnnouncement\n  userCountryCode\n}\n"
# }

# {"interpret_id": "runcode_1649907939.3660505_gLGGHWZzt0", "test_case": "[1,2,3,1]"}
import requests
import os

code = '''
var rob = function(nums) {
    const n = nums.length;
    if (n < 2) return Math.max(...nums);
    let first = nums[0], second = Math.max(nums[0], nums[1]);
    for (let i = 2; i < n; ++i) [first, second] = [second, Math.max(first + nums[i], second)];
    return second;
};
'''

header = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.60 Safari/537.36 Edg/100.0.1185.29',
    'cookie': 'cf_clearance=zfUFKuUgtqnLqWzi64HygFk8hho3csWiqgEov6we7AE-1634964988-0-250; __stripe_mid=a8605c9b-615e-4acf-ab74-59389b083fafef7035; csrftoken=EHaavwo2YvrHULZoh0OeBH99JVDBStKjS2HgYStO2IEvpoGls3T2ar3Kcg2U63lu; NEW_PROBLEMLIST_PAGE=1; LEETCODE_SESSION=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiNTQ0NDA0IiwiX2F1dGhfdXNlcl9iYWNrZW5kIjoiZGphbmdvLmNvbnRyaWIuYXV0aC5iYWNrZW5kcy5Nb2RlbEJhY2tlbmQiLCJfYXV0aF91c2VyX2hhc2giOiJjOWM2ZWE5OTcxNjkxNzY0ZWY5NWY1OWQ1MjFkMzkwNDZmNDMzMzdhIiwiaWQiOjU0NDQwNCwiZW1haWwiOiJiamNoYWNoYUBvdXRsb29rLmNvbSIsInVzZXJuYW1lIjoieHh4eHhzaHVhaTAiLCJ1c2VyX3NsdWciOiJ4eHh4eHNodWFpMCIsImF2YXRhciI6Imh0dHBzOi8vYXNzZXRzLmxlZXRjb2RlLmNvbS91c2Vycy94eHh4eHNodWFpMC9hdmF0YXJfMTU4MzEzMzQ3OS5wbmciLCJyZWZyZXNoZWRfYXQiOjE2NDk3NDkyOTEsImlwIjoiMTcyLjEwNC45Ni4yNDgiLCJpZGVudGl0eSI6IjgwZDVhY2FiODNiZjZjNWMyODRhN2IxNDAyNDI1YzYxIiwiX3Nlc3Npb25fZXhwaXJ5IjoxMjA5NjAwLCJzZXNzaW9uX2lkIjoxOTY3NjY3NH0.NDRmgtc_rw3QUCVli5biQW5ZDLcw1l4Kg7ZJDiUPUbE; c_a_u="eHh4eHhzaHVhaTA=:1neqLd:uDd0tLIyxaiYoxWTzIXgjIUJriA"'
}
data = {
  "question_id": "198",
  "data_input": "[1,2,3,1]",
  "lang": "javascript",
  "typed_code": code,
  "judge_type": "large"
}

url = 'https://leetcode.com/problems/house-robber/interpret_solution/'

my_request = requests.post(url, headers=header, json=data)

print(my_request)