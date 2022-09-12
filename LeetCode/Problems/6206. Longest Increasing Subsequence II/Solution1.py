// segment tree
class Solution:
    def lengthOfLIS(self, nums: List[int], k: int) -> int:
        n = len(nums)
        mx = 1000000
        dp = [1] * n
        tree = [0] * (4 * mx)

        def getMax(lo, hi):
            res = 0
            lo += mx - 1
            hi += mx - 1
            while lo <= hi:
                if lo % 2 == 1:
                    res = max(res, tree[lo])
                    lo += 1
                if hi % 2 == 0:
                    res = max(res, tree[hi])
                    hi -= 1
                lo >>= 1
                hi >>= 1
            return res

        res = 1

        for i in range(n - 1, -1, -1):
            dp[i] = getMax(nums[i] + 1, nums[i] + k) + 1
            res = max(dp[i], res)
            cur = nums[i] + mx - 1
            while cur:
                tree[cur] = max(dp[i], tree[cur])
                cur >>= 1

        return res
