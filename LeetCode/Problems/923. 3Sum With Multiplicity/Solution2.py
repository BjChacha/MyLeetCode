from collections import Counter, defaultdict
from typing import List

# 两重循环+二分查找，Hash计数
class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        
        def comb(n, m):
            if m > n:
                return 0
            res = 1
            for i in range(m):
                res *= (n - i) / (i + 1)
            return int(res)
        
        def bisearch(left, right, target):
            while left <= right:
                mid = (left + right) // 2
                if keys[mid] == target:
                    return mid
                elif keys[mid] > target:
                    right = mid - 1
                else:
                    left = mid + 1
            return -1
        
        MOD = 1000000007
        counter = Counter(arr)
        keys = sorted(counter.keys())
        n = len(keys)
        res = 0
        for i in range(n):
            for j in range(i, n):
                k = bisearch(j, n - 1, target - keys[i] - keys[j])
                if not k == -1:
                    com = defaultdict(int)
                    com[keys[i]] += 1
                    com[keys[j]] += 1
                    com[keys[k]] += 1

                    tmp_res = 1
                    for v in com:
                        tmp_res *= comb(counter[v], com[v])
                    res += tmp_res

        return res % MOD