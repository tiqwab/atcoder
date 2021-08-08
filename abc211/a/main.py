def main() -> float:
    A, B = [int(x) for x in input().split(' ')]
    return (A - B) / 3 + B

if __name__ == '__main__':
    print(main())
