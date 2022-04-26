def main():
    N, Q = [int(x) for x in input().split(' ')]
    elems = [int(x) for x in input().split(' ')]

    memo = dict()
    for i, v in enumerate(elems):
        if memo.get(v) is not None:
            memo[v].append(i + 1)
        else:
            memo[v] = [i + 1]

    for _ in range(Q):
        x, k = [int(x) for x in input().split(' ')]
        if memo.get(x) is not None and k - 1 < len(memo[x]):
            print(memo[x][k - 1])
        else:
            print(-1)


if __name__ == '__main__':
    main()
