import sys
input = sys.stdin.readline
from queue import PriorityQueue


dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(grid, n, dist):
    dist[0][0] = 0
    pq = PriorityQueue()
    
    pq.put((0, 0, 0)) # dist, x, y

    while not pq.empty():
        _weight, x, y = pq.get()
        for i in range(4):
            new_x = x + dx[i]
            new_y = y + dy[i]
            if new_x < 0 or new_x >= n or new_y < 0 or new_y >= n:
                continue
            weight = grid[new_x][new_y]
            #print(weight, new_x, new_y)
            if dist[new_x][new_y] > dist[x][y] + weight:
                dist[new_x][new_y] = dist[x][y] + weight
                pq.put((dist[new_x][new_y], new_x, new_y))


if __name__=="__main__":
    num_tc = int(input().rstrip())
    for i in range(num_tc):
        n = int(input().rstrip())
        grid = [[int(i) for i in input().rstrip()] for i in range(n)]
        dist = [[float("inf")] * n for i in range(n)]
        bfs(grid, n, dist)
        print(f'#{i+1} {dist[n-1][n-1]}')
