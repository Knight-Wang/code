f = [1, 1]
for i in range(2, 100):
	f.append(f[i - 2] + f[i - 1])
n = int(input())
for i in range(1, n + 1):
	if i in f:
		print ('O', end='')
	else:
		print ('o', end='')