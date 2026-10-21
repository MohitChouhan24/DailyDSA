import heapq
class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        min_heap = []
        for x in nums:
            if len(min_heap) < k:
                heapq.heappush(min_heap,x)
            elif len(min_heap) == k and min_heap[0] < x:
                heapq.heappop(min_heap)
                heapq.heappush(min_heap,x)
        return min_heap[0]

