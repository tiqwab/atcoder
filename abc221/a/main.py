def main() -> int:
    A, B = [int(x) for x in input().split(' ')]
    return pow(32, A - B)

if __name__ == '__main__':
    print(main())
