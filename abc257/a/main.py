def main() -> chr:
    N, X = [int(x) for x in input().split()]
    X -= 1
    return chr(ord('A') + (X // N))


if __name__ == '__main__':
    print(main())
