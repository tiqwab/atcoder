def main() -> int:
    A, B, C, D = [int(x) for x in input().split(' ')]

    if C * D - B <= 0:
        return -1

    return (A + (C * D - B - 1)) // (C * D - B)

if __name__ == '__main__':
    print(main())
