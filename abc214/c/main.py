def main():
    N = int(input())
    ss = [int(x) for x in input().split(' ')]
    ts = [int(x) for x in input().split(' ')]

    min_idx = -1
    min_t = 1000 * 1000 * 1000 + 10
    for i, t in enumerate(ts):
        if t < min_t:
            min_idx = i
            min_t = t

    acc = min_t
    i = min_idx
    ans = [1 << 60] * N

    for _ in range(0, N):
        # print(i, acc)
        ans[i] = min(ts[i], acc)
        acc = ans[i] + ss[i]
        i = (i + 1) % N

    for i in range(0, N):
        print(ans[i])


if __name__ == '__main__':
    main()
