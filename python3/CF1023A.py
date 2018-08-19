n, m = list(map(int, input().split()))
s = input()
t = input()
if '*' not in s:
	ans = 'YES' if s == t else 'NO'
	print (ans)
elif n > m + 1:
	print ('NO')
else:
	p, q = s.split('*')
	flg = True
	if len(p) > 0 and t[:len(p)] != p: flg = False
	if len(q) > 0 and t[-len(q):] != q: flg = False
	ans = 'YES' if flg else 'NO'
	print (ans)