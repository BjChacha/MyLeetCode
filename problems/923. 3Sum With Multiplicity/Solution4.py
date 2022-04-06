from collections import Counter, defaultdict
from typing import List

# 三指针，Hash计数, without comb
class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        
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
                    if i == j == k:
                        if counter[keys[i]] >= 3:
                            res += counter[keys[i]] * (counter[keys[i]] - 1) * (counter[keys[i]] - 2) // 6
                    elif j == i:
                        if counter[keys[i]] >= 2:
                            res += counter[keys[i]] * (counter[keys[i]] - 1) // 2 * counter[keys[k]]
                    elif j == k:
                        if counter[keys[j]] >= 2:
                            res += counter[keys[j]] * (counter[keys[j]] - 1) // 2 * counter[keys[i]]
                    else:
                        res += counter[keys[i]] * counter[keys[j]] * counter[keys[k]] 
                    j += 1
                    k -= 1

        return res % MOD