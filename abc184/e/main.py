from collections import deque, defaultdict


INF = 10**18
dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]


if __name__ == '__main__':
    H, W = [int(x) for x in input().split()]

    board = [['#'] * (W + 2) for _ in range(0, H + 2)]
    dp = [[INF] * (W + 2) for _ in range(0, H + 2)]
    warps = [[] for _ in range(0, 26)]
    used_warp = [False for _ in range(0, 26)]

    start = None
    goal = None

    for h in range(0, H):
        row = input()
        for w in range(0, W):
            c = row[w]
            board[h + 1][w + 1] = c
            if c == 'S':
                start = (h + 1, w + 1)
            if c == 'G':
                goal = (h + 1, w + 1)
            if 'a' <= c and c <= 'z':
                warps[ord(c) - ord('a')].append((h + 1, w + 1))

    def solve(start: (int, int), goal: (int, int), H: int, W: int):
        q = deque([])
        dp[start[0]][start[1]] = 0
        q.append(start)

        while len(q) > 0:
            (cur_h, cur_w) = q.popleft()
            cur_dist = dp[cur_h][cur_w]
            for (dh, dw) in dirs:
                next_h = cur_h + dh
                next_w = cur_w + dw

                if board[next_h][next_w] == '#':
                    continue

                if cur_dist + 1 < dp[next_h][next_w]:
                    dp[next_h][next_w] = cur_dist + 1
                    q.append((next_h, next_w))

            if 'a' <= board[cur_h][cur_w] and board[cur_h][cur_w] <= 'z':
                idx = ord(board[cur_h][cur_w]) - ord('a')
                if not used_warp[idx]:
                    for (next_h, next_w) in warps[idx]:
                        if cur_dist + 1 < dp[next_h][next_w]:
                            dp[next_h][next_w] = cur_dist + 1
                            q.append((next_h, next_w))
                    used_warp[idx] = True

    solve(start, goal, H, W)

    if dp[goal[0]][goal[1]] < INF:
        print(dp[goal[0]][goal[1]])
    else:
        print(-1)
