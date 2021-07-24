def main() -> int:
    A, B = [int(x) for x in input().split(' ')]
    return max(0, B - A + 1)

if __name__ == '__main__':
    print(main())
