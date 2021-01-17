def get_line():
    return list(map(int, input().split()))
n = int(input())
for _ in range(n):
    line = get_line() 
    n, d = line[0], line[1]
    a = get_line() 
    a = sorted(a)
    if a[-1] <= d or a[0] + a[1] <= d:
        print('yes')
    else:
        print('no')
