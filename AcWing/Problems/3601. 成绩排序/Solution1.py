import sys

N = int(sys.stdin.readline().strip())
arr = []
for _ in range(N):
    name, age, score = sys.stdin.readline().strip().split()
    arr.append([int(score), name, int(age)])

arr.sort()
for a in arr:
    print(f'{a[1]} {a[2]} {a[0]}')