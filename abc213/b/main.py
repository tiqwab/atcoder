def main() -> int:
    N = int(input())
    xs = [int(x) for x in input().split(' ')]
    tuples = list(zip(xs, range(1, N + 1)))
    tuples.sort()
    # print(tuples)
    return tuples[N - 2][1]

if __name__ == '__main__':
    print(main())
