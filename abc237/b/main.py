def main():
    H, W = [int(x) for x in input().split(' ')]
    xs = []
    for i in range(H):
        ss = [x for x in input().split(' ')]
        xs.append(ss)

    ys = [[0] * H for _ in range(W)]
    for i in range(H):
        for j in range(W):
            ys[j][i] = xs[i][j]

    for i in range(W):
        print(' '.join(ys[i]))


if __name__ == '__main__':
    main()
