# prefix sum
from typing import List

class Solution:
    def maxTrailingZeros(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        v = [[(0, 0)] * n for _ in range(m+1)]
        h = [[(0, 0)] * (n+1) for _ in range(m)]
        res = 0
        
        def get_Ns(num, n):
            cnt = 0
            while num % n == 0:
                num //= n
                cnt += 1
            return cnt    
        
        for j in range(n):
            cnt2, cnt5 = 0, 0
            for i in range(m):
                cnt2 += get_Ns(grid[i][j], 2)
                cnt5 += get_Ns(grid[i][j], 5)
                v[i+1][j] = (cnt2, cnt5)
        
        for i in range(m):
            cnt2, cnt5 = 0, 0
            for j in range(n):
                cnt2 += get_Ns(grid[i][j], 2)
                cnt5 += get_Ns(grid[i][j], 5)
                h[i][j+1] = (cnt2, cnt5)
        
        for i in range(m):
            for j in range(n):
                # top-left
                score1 = min(v[i+1][j][k] + h[i][j][k] for k in range(2))
                # top-right
                score2 = min(v[i+1][j][k] + h[i][n][k] - h[i][j+1][k] for k in range(2))
                # bottom-left
                score3 = min(v[m][j][k] - v[i][j][k] + h[i][j][k] for k in range(2))
                # bottom-right
                score4 = min(v[m][j][k] - v[i][j][k] + h[i][n][k] - h[i][j+1][k] for k in range(2))
                
                # print(i, j, score1, score2, score3, score4)
                res = max(res, max(score1, score2, score3, score4))
                        
        return res
