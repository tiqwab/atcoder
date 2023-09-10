def print_board(board):
    for line in board:
        print(''.join(line))


def main():
    N, A, B = [int(x) for x in input().split(' ')]

    board = [['.' for _ in range(B * N)] for _ in range(A * N)]

    for y in range(A * N):
        for x in range(B * N):
            color1 = '.' if y % (A * 2) < A else '#'
            color2 = '#' if y % (A * 2) < A else '.'
            if x % (B * 2) < B:
                board[y][x] = color1
            else:
                board[y][x] = color2

    print_board(board)


if __name__ == '__main__':
    main()
