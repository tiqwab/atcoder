def main() -> int:
    N, K = [int(x) for x in input().split(' ')]
    ans = 0
    for n in range(1, N + 1):
        for k in range(1, K + 1):
            ans += n * 100 + k
    return ans

if __name__ == '__main__':
    print(main())
