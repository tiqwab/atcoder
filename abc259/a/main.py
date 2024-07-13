def main() -> int:
    N, M, X, T, D = [int(x) for x in input().split(' ')]

    if X <= M:
        return T
    else:
        return T - D * (X - M)


if __name__ == '__main__':
    print(main())
