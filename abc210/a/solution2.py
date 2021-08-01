def main() -> int:
    N, A, X ,Y = [int(x) for x in input().split(' ')]
    if N <= A:
        return N * X
    else:
        return A * X + (N - A) * Y

if __name__ == '__main__':
    print(main())
