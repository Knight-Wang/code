class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        a, b = version1.split('.'), version2.split('.')
        a, b = list(map(lambda x: int(x), a)), list(map(lambda x: int(x), b))
        while len(a) > 0 and a[-1] == 0: a = a[:-1]
        while len(b) > 0 and b[-1] == 0: b = b[:-1]
        for i in range(min(len(a), len(b))):
            if a[i] != b[i]:
                if a[i] < b[i]: return -1
                elif a[i] > b[i]: return 1
        if len(a) < len(b): return -1
        elif len(a) > len(b): return 1
        else: return 0