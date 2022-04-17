# simulate
from collections import defaultdict

class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        s = paragraph
        counter = defaultdict(int)
        tmp = ""
        for c in s:
            if c.isalpha():
                tmp += c
            else:
                if tmp:
                    counter[tmp.lower()] += 1
                tmp = ""
        if tmp:
            counter[tmp.lower()] += 1
            
        for w in banned:
            if w in counter:
                counter[w] = 0
        # print(counter)
        return sorted(counter.items(), key=lambda x: x[1])[-1][0]