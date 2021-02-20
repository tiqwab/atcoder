def solve():
    T = int(input())

    for _ in range(0, T):
        [L, R] = map(int, input().split())

        x = R - 2 * L + 1
        if x < 1:
            ans = 0
        else:
            ans = x * (x + 1) // 2

        print(ans)

if __name__ == '__main__':
    solve()
