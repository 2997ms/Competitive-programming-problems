
def A(m,n):
    return 1 if n==0 else A(m,n-1) * (m-n+1)

class Solution(object):
    def numDupDigitsAtMostN(self, N):
        """
        :type N: int
        :rtype: int
        """
        L = map(int, str(N+1))
        res = 0
        n = len(L)

        for i in range(1,n):
            res += 9 * A(9, i-1)

        s = set()
        for i, x in enumerate(L):
            for y in range(0 if i else 1, x):
                if y not in s:
                    res += A(9-i, n-i-1)
            if x in s:
                break
            s.add(x)
        return N-res