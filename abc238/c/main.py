def main() -> int:
    N = int(input())
    ans = 0

    power = 10
    while power <= N:
        start = power // 10
        n = power - start
        ans += n * (n + 1) // 2
        power *= 10

    power //= 10
    n = N - power + 1
    ans += n * (n + 1) // 2

    return ans % 998244353 


if __name__ == '__main__':
    print(main())
