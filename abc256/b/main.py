def main() -> int:
    n = int(input())
    xs = [int(x) for x in input().split(' ')]

    board = [0, 0, 0, 0]

    score = 0

    for i in range(n):
        board[0] += 1
        x = xs[i]
        for j in reversed(range(4)):
            if board[j] > 0:
                if j + x > 3:
                    score += 1
                else:
                    board[j + x] += 1
                board[j] -= 1

    return score


if __name__ == '__main__':
    print(main())
