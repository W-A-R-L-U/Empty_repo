from collections import deque
import heapq

def find_maximum_distance(grid):
    n, m = len(grid), len(grid[0])
    directions = [(-1,0), (1,0), (0,-1), (0,1)]

    start = end = None
    obstacles = []
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'S':
                start = (i, j)
            elif grid[i][j] == 'E':
                end = (i, j)
            elif grid[i][j] == '*':
                obstacles.append((i, j))

    def compute_obstacle_dist():
        dist = [[float('inf')] * m for _ in range(n)]
        q = deque()
        for r, c in obstacles:
            dist[r][c] = 0
            q.append((r, c))
        
        while q:
            r, c = q.popleft()
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < m and grid[nr][nc] != '*' and dist[nr][nc] == float('inf'):
                    dist[nr][nc] = dist[r][c] + 1
                    q.append((nr, nc))
        return dist

    obs_dist = compute_obstacle_dist()

    pq = [(-obs_dist[start[0]][start[1]], start)]
    visited = [[-1] * m for _ in range(n)]
    visited[start[0]][start[1]] = obs_dist[start[0]][start[1]]

    while pq:
        neg_min_dist, (r, c) = heapq.heappop(pq)
        min_dist = -neg_min_dist
        if (r, c) == end:
            return min_dist

        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < m and grid[nr][nc] != '*':
                new_min = min(min_dist, obs_dist[nr][nc])
                if new_min > visited[nr][nc]:
                    visited[nr][nc] = new_min
                    heapq.heappush(pq, (-new_min, (nr, nc)))

    return -1  # if no path is found
print(find_maximum_distance(["S..*","..*.","....","...E"]))
