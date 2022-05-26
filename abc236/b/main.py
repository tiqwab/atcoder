def main() -> int:
    N = int(input())
    ns = [int(x) for x in input().split(' ')]
    counter = [0 for _ in range(N + 1)]

    for n in ns:
        counter[n] += 1

    for i in range(1, N + 1):
        if counter[i] != 4:
            return i

    return -1


if __name__ == '__main__':
    print(main())
