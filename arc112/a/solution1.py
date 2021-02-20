def solve():
    T = int(input())

    for _ in range(0, T):
        [L, R] = map(int, input().split())

        n = R - 2 * L
        if n < 0:
            print(0)
        else:
            ans = (n + 2) * (n + 1) // 2
            print(ans)

if __name__ == '__main__':
    solve()
