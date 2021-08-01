def main() -> int:
    N, A, X ,Y = [int(x) for x in input().split(' ')]
    ans = 0
    for i in range(1, N + 1):
        if i <= A:
            ans += X;
        else:
            ans += Y;
    return ans

if __name__ == '__main__':
    print(main())
