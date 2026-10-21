class Solution:
    def minWindow(self, s: str, t: str) -> str:
        start = -1
        left = 0
        right = 0
        minLen = float(inf)
        freq = {}
        for c in t:
            freq[c] = freq.get(c,0)+1
        count = 0
        while right < len(s):
            if freq.get(s[right],0) > 0 : count += 1
            freq[s[right]] = freq.get(s[right],0)-1
            while count == len(t):
                if right-left+1 < minLen:
                    start = left
                    minLen = right-left+1
                freq[s[left]] += 1
                if freq[s[left]] > 0:
                    count -= 1
                left += 1
            right += 1
        return "" if start ==-1 else s[start:start+minLen]