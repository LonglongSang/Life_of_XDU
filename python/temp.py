class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        # 循环寻找根植
        def getroot(x):
            while father[x] != x:
                x = getroot(father[x])
            return x

        # 比较新的路径起点和终点，如果根植相同，证明有环，否则更新终点的根植
        def union(s, t):
            rs, rt = getroot(s), getroot(t)
            if rs == rt:
                return True
            father[rt] = rs
            return False

        # 由上而下，由左往右更新根植，如果发现环即返回，否则表示无环
        m, n = len(grid), len(grid[0])
        father = [i for i in range(m*n)]
        for i in range(m):
            for j in range(n):
                if i > 0 and grid[i][j] == grid[i-1][j]:
                    if union(i*n+j, (i-1)*n+j):
                        return True
                if j > 0 and grid[i][j] == grid[i][j-1]:
                    if union(i*n+j, i*n+(j-1)):
                        return True
        return False
