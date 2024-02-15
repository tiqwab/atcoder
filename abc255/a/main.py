def main() -> int:
    r, c = [int(x) for x in input().split(' ')]
    m = [[int(x) for x in input().split(' ')] for _ in range(2)]
    return m[r-1][c-1]


if __name__ == '__main__':
    print(main())
