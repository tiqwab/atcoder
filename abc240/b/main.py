def main() -> int:
    N = int(input())
    xs = [int(x) for x in input().split(' ')]
    acc = set()

    for x in xs:
        acc.add(x)

    return len(acc)


if __name__ == '__main__':
    print(main())
