def main() -> int:
    N = int(input())
    if N <= 125:
        return 4
    elif N <= 211:
        return 6
    else:
        return 8

if __name__ == '__main__':
    print(main())
