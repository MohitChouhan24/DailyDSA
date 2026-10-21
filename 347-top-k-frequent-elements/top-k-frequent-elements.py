import heapq
class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        freq = {}
        for x in nums:
            if x in freq:
                freq[x] += 1
            else: freq[x] = 1
        
        min_heap = []
        for key in freq:
            if len(min_heap) < k:
                heapq.heappush(min_heap,(freq[key],key))
            elif len(min_heap) == k and min_heap[0][0] < freq[key]:
                heapq.heappop(min_heap)
                heapq.heappush(min_heap,(freq[key],key))
        
        ans = []
        for x,y in min_heap:
            ans.append(y)
        return ans
