from collections import Counter, defaultdict
from typing import List

# 三指针，Hash计数
class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        
        def comb(n, m):
            if m > n:
                return 0
            res = 1
            for i in range(m):
                res *= (n - i) / (i + 1)
            return int(res)
        
        MOD = 1000000007
        counter = Counter(arr)
        keys = sorted(counter.keys())
        n = len(keys)
        res = 0
        for i in range(n):
            j, k = i, n -1
            while (j <= k):
                sm = keys[i] + keys[j] + keys[k]
                if sm > target:
                    k -= 1
                elif sm < target:
                    j += 1
                else:
                    com = defaultdict(int)
                    com[keys[i]] += 1
                    com[keys[j]] += 1
                    com[keys[k]] += 1

                    tmp_res = 1
                    for v in com:
                        tmp_res *= comb(counter[v], com[v])
                    res += tmp_res   
                    
                    j += 1
                    k -= 1

        return res % MOD