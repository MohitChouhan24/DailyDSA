class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n = len(s1)
        m = len(s2)
        first = {}
        second = {}
        for x in s1:
            first[x] = first.get(x,0)+1
        i = 0
        for j in range(m):
            second[s2[j]] = second.get(s2[j],0)+1
            if j-i+1 == n:
                if first == second : return True
                second[s2[i]] -= 1
                if second[s2[i]] == 0:
                    del second[s2[i]]
                i += 1
        return False