import os
from collections import defaultdict
from .utils import read_frontmatter, get_difficult_problems_number

def main():
    dir_problem = 'LeetCode/Problems'
    output_filename = "Summary.md"

    content = []
    tagging = defaultdict(list)
    difficulty_count = defaultdict(int)

    # read problems from Problems folder
    problem_md_list = [f'{dir_problem}/{d}' for d in os.listdir(dir_problem) if os.path.isdir(f'{dir_problem}/{d}')]
    for i, e in enumerate(problem_md_list):
        info = read_frontmatter(e + "/README.md")
        info['dir'] = e
        info['github_url'] = f'https://github.com/BjChacha/MyLeetCode/tree/main/{info["dir"].replace(" ", "%20")}'
        content.append(info)
        
        difficulty_count[info['difficulty']] += 1
    
    content.sort(key=lambda x: x['no'])

    # tagging problems
    for item in content:
        for tag in item['tags']:
            tagging[tag].append(item)

    content = '# Summary\n'

    # show progress
    cnts = get_difficult_problems_number()
    content += '## Progress\n'
    lines = ""
    left_space = 21
    for i, d in enumerate(['Easy', 'Medium', 'Hard']):
        line = f"- {d}: {difficulty_count[d]} / {cnts[i]}"
        line += " " * (left_space - len(line)) + '\n'
        line += "\#" * (difficulty_count[d] * 20 // cnts[i])
        line += '\n'
        lines += line
    content += lines + '\n'

    # show problems by tag
    content += '## Problem\n'
    for key, items in tagging.items():
        content += f"### {key}\n"
        lines = ""
        for item in items:
            line = f"- \[{item['no']}\]\[{item['difficulty']}\] \- [{item['title']}]({item['github_url']})\n"
            lines += line
        content += lines

    # print(content)

    # write md file
    with open(output_filename, 'w', encoding='utf-8') as f:
        f.write(content)

if __name__ == '__main__':
    main()
