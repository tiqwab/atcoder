def main() -> int:
    A, B, C = [int(x) for x in input().split(' ')]
    return max(A + B, B + C, C + A)

if __name__ == '__main__':
    print(main())
