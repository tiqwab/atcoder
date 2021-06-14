def main() -> int:
    x, y = [int(x) for x in input().split(' ')]
    if x == y:
        return x
    else:
        return 3 - x - y

if __name__ == '__main__':
    print(main())
