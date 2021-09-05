def main() -> int:
    N = int(input())
    ans = 0
    acc = 2
    while acc <= N:
        ans += 1
        acc *= 2
    return ans

if __name__ == '__main__':
    print(main())
