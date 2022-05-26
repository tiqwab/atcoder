def main():
    N, M = [int(x) for x in input().split(' ')]
    ss = [x for x in input().split(' ')]
    ts = [x for x in input().split(' ')]

    ans = [False] * N

    si = 0
    for t in ts:
        while si < N:
            if ss[si] == t:
                ans[si] = True
                si += 1
                break
            else:
                si += 1

    for b in ans:
        if b:
            print('Yes')
        else:
            print('No')


if __name__ == '__main__':
    main()
