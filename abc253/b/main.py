def main() -> int:
    H, W = [int(x) for x in input().split(' ')]
    board = [input() for _ in range(H)]

    ks = []
    for h in range(H):
        for w in range(W):
            if board[h][w] == 'o':
                ks.append((h, w))

    return abs(ks[0][0] - ks[1][0]) + abs(ks[0][1] - ks[1][1])


if __name__ == '__main__':
    print(main())
