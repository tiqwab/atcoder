def main() -> int:
    A, B, K = [int(x) for x in input().split(' ')]

    ans = 0

    while A < B:
        A *= K 
        ans += 1

    return ans


if __name__ == '__main__':
    print(main())
