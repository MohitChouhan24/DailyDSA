class Solution:
    def findAnagrams(self, s: str, p: str) -> list[int]:
        m = len(p)
        n = len(s)
        pmap = {}
        smap = {}
        for x in p:
            pmap[x] = pmap.get(x,0)+1
        ans = []
        i = 0
        for j in range(n):
            smap[s[j]] = smap.get(s[j],0)+1
            if j-i+1 == m:
                if smap == pmap:
                    ans.append(i)
                smap[s[i]] -= 1
                if smap[s[i]] == 0:
                    del smap[s[i]]
                i += 1
        return ans 
        