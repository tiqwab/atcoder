import queue
from collections import deque


def main() -> bool:
    N = int(input())
    sx, sy, tx, ty = [int(x) for x in input().split(' ')]

    start_circle = -1
    goal_circle = -1

    # (x, y, r)
    circles = []
    for i in range(N):
        cx, cy, cr = [int(x) for x in input().split(' ')]
        circles.append((cx, cy, cr))

        if (cx - sx) ** 2 + (cy - sy) ** 2 == cr ** 2:
            start_circle = i
        if (cx - tx) ** 2 + (cy - ty) ** 2 == cr ** 2:
            goal_circle = i

    # edges[i] contains edge from i
    edges = [[] for _ in range(N)]
    for i in range(N):
        ci = circles[i]
        for j in range(i + 1, N):
            cj = circles[j]

            # distance between two centers
            d = (ci[0] - cj[0]) ** 2 + (ci[1] - cj[1]) ** 2

            # if too far
            if d > (ci[2] + cj[2]) ** 2:
                continue

            # if ci contains cj
            if (d + cj[2]) ** 2 < ci[2] ** 2:
                continue

            # # if cj contains ci
            if (d + ci[2]) ** 2 < cj[2] ** 2:
                continue

            edges[i].append(j)
            edges[j].append(i)

    # for i in range(N):
    #     print(f"{i}: {edges[i]}")

    q = queue.Queue()
    q.put(start_circle)

    visited = [False] * N
    visited[start_circle] = True

    while not q.empty():
        cur_circle = q.get()
        if cur_circle == goal_circle:
            return True

        for next_circle in edges[cur_circle]:
            if visited[next_circle]:
                continue
            q.put(next_circle)
            visited[next_circle] = True

    return False

if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
