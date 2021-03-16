def solve() -> float:
    N = int(input())

    ans = 0.0

    for i in range(0, N - 1):
        a = 1.0 - ((i + 1) / N)
        a = 1.0 / (a * a)
        a *= (N - 1 - i) / N
        # print(a)
        ans += a

    return ans

if __name__ == '__main__':
    print(solve())
