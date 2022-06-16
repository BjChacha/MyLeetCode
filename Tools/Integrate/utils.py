import sys
sys.path.append('Tools')
sys.path.append('..')

import requests
from bs4 import BeautifulSoup as bs
from var import URL_GRAPHQL_LEETCODE, QUERY_DIFFICULTY_NUMBER

def read_frontmatter(filename):
    try:
        content = []
        d = {}
        with open(filename, 'r', encoding='utf-8') as f:
            while f.readline() != '---\n':
                pass
            line = f.readline()
            while line != '---\n':
                content.append(line)
                line = f.readline()
        for line in content:
            key, value = line.strip('\n').split(': ')
            if value.isdigit():
                d[key] = int(value)
            elif value.startswith('['):
                d[key] = value[1:-1].split(', ')
            else:
                d[key] = value
        return d

    except FileNotFoundError:
        print(f"Can't find file: {filename}")

def get_difficult_problems_number():
    
    url = URL_GRAPHQL_LEETCODE
    q = QUERY_DIFFICULTY_NUMBER
    username = 'xxxxxshuai0'

    header = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.60 Safari/537.36 Edg/100.0.1185.29',
    }
    data = {
        "variables": {
            "username": f"{username}"
        },
        "query": q,
    }
    
    my_request = requests.post(url, headers=header, json=data)
    content = my_request.json()
    
    return [content['data']['allQuestionsCount'][i]['count'] for i in range(1, 4)]
