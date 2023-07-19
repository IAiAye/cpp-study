import sys,math,heapq
from collections import deque

def f(s,e):
	v=[False]*(n+1)
	hq=[]
	heapq.heappush(hq,(-math.inf,s))
	res=math.inf
	while hq:
		vol,node=heapq.heappop(hq)
		vol*=-1

		if v[node]:
			continue
		v[node]=True

		res=min(res,vol)
		if node==e:
			return res
		for nextnode,nextvol in gragh[node].items():
			heapq.heappush(hq,[-nextvol,nextnode])

n,k,m=map(int,sys.stdin.readline().split())
c=list(map(int,sys.stdin.readline().split()))
gragh=[dict() for j in range(n+1)]
for i in range(m):
	a,b,w=map(int,sys.stdin.readline().split())
	gragh[a][b]=w
	gragh[b][a]=w

cc=[[]for i in range(k+1)]
for i,j in enumerate(c):
	cc[j].append(i+1)


for i in cc[1:]:
	res=0
	for j in range(len(i)):
		for k in range(j):
			res+=f(i[j],i[k])
			print(f(i[j],i[k]))
	print(res)