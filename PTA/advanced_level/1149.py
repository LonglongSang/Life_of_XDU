n, m = [int(i) for i in input().split()]
mp = {}
for i in range(n):
	a, b = [int(j) for j in input().split()]
	if a not in mp: mp[a] = []
	if b not in mp: mp[b] = []
	mp[a].append(i)
	mp[b].append(i)
for i in range(m):
	li = [int(j) for j in input().split()]
	del li[0]
	bad = [0 for j in range(n)]
	good = True
	for j in li:
		if j not in mp: continue
		for a in mp[j]:
			bad[a] += 1
			if bad[a] == 2:
				good = False
				break
	if good: print("Yes")
	else: print("No")
		