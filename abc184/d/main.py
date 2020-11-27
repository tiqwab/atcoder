dp = [[[None] * 105 for _ in range(0, 105)] for _ in range(0, 105)]


def solve(a_, b_, c_):
    def dfs(a, b, c):
        if dp[a][b][c] is not None:
            return dp[a][b][c]

        acc = 0.0
        acc += float(a) / float(a + b + c) * (dfs(a + 1, b, c) + 1)
        acc += float(b) / float(a + b + c) * (dfs(a, b + 1, c) + 1)
        acc += float(c) / float(a + b + c) * (dfs(a, b, c + 1) + 1)

        dp[a][b][c] = acc
        return acc

    return dfs(a_, b_, c_)


if __name__ == '__main__':
    A, B, C = [int(x) for x in input().split()]

    for i in range(0, 101):
        for j in range(0, 101):
            for k in range(0, 101):
                if i == 100 or j == 100 or k == 100:
                    dp[i][j][k] = 0
    print(solve(A, B, C))
