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