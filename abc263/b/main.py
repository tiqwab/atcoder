def main() -> int:
    N = int(input())
    ps = [0]
    ps.extend([int(x) - 1 for x in input().split(' ')])

    ans = 0
    cur = N - 1
    while cur > 0:
        cur = ps[cur]
        ans += 1
    return ans


if __name__ == '__main__':
    print(main())
