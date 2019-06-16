n = int(input())
s = input()
p = [i for i in range(n) if s[i] != '0'][1:]
p = sorted(p, key=lambda x: abs(x - n / 2))
minn = int(s)
for i in range(min(4, len(p))):
    minn = min(minn, int(s[:p[i]]) + int(s[p[i]:]))
print (minn)