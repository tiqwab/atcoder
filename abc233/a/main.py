def main() -> int:
    X, Y = [int(x) for x in input().split(' ')]
    return max(0, (Y - X + (10 - 1)) // 10)


if __name__ == '__main__':
    print(main())
