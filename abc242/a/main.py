def main() -> float:
    A, B, C, X = [int(x) for x in input().split(' ')]
    if X <= A:
        return 1.0
    elif X <= B:
        return C / (B - A)
    else:
        return 0


if __name__ == '__main__':
    print(main())
