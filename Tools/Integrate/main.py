import os
from collections import defaultdict
from read_frontmatter import read_frontmatter

DIR_PROBLEM = 'Problems'

def main():
    content = []
    indexing = {}
    tagging = defaultdict(list)

    problem_md_list = [f'{DIR_PROBLEM}/{d}' for d in os.listdir(DIR_PROBLEM) if os.path.isdir(f'{DIR_PROBLEM}/{d}')]
    for i, e in enumerate(problem_md_list):
        info = read_frontmatter(e + "/README.md")
        info['dir'] = e
        content.append(info)
    
    for item in content:
        indexing[item['no']] = item

        for tag in item['tags']:
            tagging[tag].append(item['no'])

    content = '# Summary\n'

    for key, values in tagging.items():
        content += f"## {key}\n"
        for v in values:
            url = f'https://github.com/BjChacha/MyLeetCode/tree/main/{indexing[v]["dir"].replace(" ", "%20")}'
            content += f"- \[{indexing[v]['no']}\]\[{indexing[v]['difficulty']}\][{indexing[v]['title']}]({url})\n"

    # print(content)
    with open("Summary_by_tags.md", 'w', encoding='utf-8') as f:
        f.write(content)

if __name__ == '__main__':
    main()