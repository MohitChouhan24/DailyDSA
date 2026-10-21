class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        freq = {}
        ans = 0
        i = 0
        for j in range(len(s)):
            freq[s[j]] = freq.get(s[j],0)+1
            while freq[s[j]] > 1:
                freq[s[i]] -= 1
                i += 1
            ans = max(ans,j-i+1)
        return ans