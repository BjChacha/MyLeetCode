import sys
print(' '.join(map(str,map(len, sys.stdin.readline().strip('. ').split()))))
