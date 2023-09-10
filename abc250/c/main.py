def main():
    N, Q = [int(x) for x in input().split(' ')]

    bs = [i for i in range(N + 1)]
    n_to_pos = [i for i in range(N + 1)]

    # print(bs)
    for _ in range(Q):
        x = int(input())
        px = n_to_pos[x]

        if px < N:
            py = px + 1
        else:
            py = px - 1
        y = bs[py]

        bs[px], bs[py] = bs[py], bs[px]
        n_to_pos[x], n_to_pos[y] = n_to_pos[y], n_to_pos[x]
        # print(bs)

    cs = [str(i) for i in bs]
    print(' '.join(cs[1:]))


if __name__ == '__main__':
    main()
