from typing import List

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        import heapq
        stones = [-x for x in stones]
        heapq.heapify(stones)
        while len(stones) > 1:
            y, x = heapq.heappop(stones), heapq.heappop(stones)
            if x != y:
                heapq.heappush(stones, y - x)
        return -stones[0] if stones else 0