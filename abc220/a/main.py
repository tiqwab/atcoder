def main() -> int:
    A, B, C = [int(x) for x in input().split(' ')]

    for x in range(A, B + 1):
        if x % C == 0:
            return x

    return -1

if __name__ == '__main__':
    print(main())
