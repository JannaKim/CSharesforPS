enu = enumerate
import sys; input= lambda: sys.stdin.readline().rstrip()
A = [[1,1,1,1]]
B = [[1,0],[1,0],[1,1]]
C = [[1,0] , [1,1] , [0,1]]
D = [[1,1,1] , [0,1,0]]
E = [ [1,1] , [1,1]]
F = [[0,1] , [0,1] , [1,1]]
G = [[0,1] , [1,1] , [1,0]]
BL = []
BL.append(A)
BL.append(B)
BL.append(C)
BL.append(D)
BL.append(E)
BL.append(F)
BL.append(G)

n , m = map(int, input().split())
mp =[ [*map(int, input().split())] for _ in range(n)]

def bound(y , x):
    if 0<=y<n and 0<=x<m:
        return True
    return False

def put(y,x,block):
    r = len(block)
    c = len(block[0])
    s=0
    for idy , i in enu(range(y,y+r)):
        for idx , j in enu(range(x,x+c)):
            if bound(i,j) and block[idy][idx]:
                s+=mp[i][j]
            elif not bound(i,j):
                return 0
    return s

ans = 0
for i in range(n):
    for j in range(m):
        for bloc in BL:
            #[print(*el) for el in bloc]
            #print()
            ans = max(ans , put(i,j,bloc))
            bloc = list(map(list, zip(*[el[::-1] for el in bloc])))
            #[print(*el) for el in bloc]
            #print()
            ans = max(ans , put(i,j,bloc))
            bloc = list(map(list, zip(*[el[::-1] for el in bloc])))
            #[print(*el) for el in bloc]
            #print()
            ans = max(ans , put(i,j,bloc))
            bloc = list(map(list, zip(*[el[::-1] for el in bloc])))
            #[print(*el) for el in bloc]
            #print()
            ans = max(ans , put(i,j,bloc))
            bloc = list(map(list, zip(*[el[::-1] for el in bloc])))

print(ans)

'''
1 5
1 1 6 7 7


4 4
2 2 1 1
2 1 1 1
2 1 1 1
1 1 1 1
'''