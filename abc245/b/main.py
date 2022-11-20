MAX_A = 2000


def main() -> int:
    N = int(input())
    xs = [int(x) for x in input().split(' ')]

    found = [False for _ in range(MAX_A + 1)]

    for x in xs:
        found[x] = True

    for i, b in enumerate(found):
        if not b:
            return i


if __name__ == '__main__':
    print(main())
