def main() -> int:
    N = int(input())
    xs = [int(x) for x in input().split(' ')]

    ans = 0
    for i in range(0, N):
        ans += max(0, xs[i] - 10)
    return ans

if __name__ == '__main__':
    print(main())
