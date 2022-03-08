import sys
from collections import Counter

N = int(sys.stdin.readline())
lst = []
for _ in range(N):
    i = int(sys.stdin.readline())
    lst.append(i)

lst.sort()

avg = int(round(sum(lst) / N, 0))
mid = lst[int(N/2)]
cnt = Counter(lst).most_common(2)
# cnt = [(idx1, mod1), (idx2, mod2)]
mod = 12210
if len(lst) > 1:
    mod = cnt[1][0] if cnt[0][1] == cnt[1][1] else cnt[0][0]
else:
    mod = cnt[0][0]
ran = max(lst) - min(lst)

print(avg, mid, mod, ran, end='\n')
