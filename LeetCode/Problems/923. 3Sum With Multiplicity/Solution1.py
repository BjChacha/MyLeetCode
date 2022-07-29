from collections import Counter, defaultdict
from typing import List

# 三重循环，Hash计数
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
            for j in range(i, n):
                for k in range(j, n):
                    if keys[i] + keys[j] + keys[k] == target:
                        com = defaultdict(int)
                        com[keys[i]] += 1
                        com[keys[j]] += 1
                        com[keys[k]] += 1
                        
                        tmp_res = 1
                        for v in com:
                            tmp_res *= comb(counter[v], com[v])
                        res += tmp_res

        return res % MOD