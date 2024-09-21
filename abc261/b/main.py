def main() -> bool:
    N = int(input())
    board = [ input().strip() for _ in range(N)]

    for i in range(N):
        for j in range(N):
            if i == j:
                if board[i][j] != '-':
                    return False
                continue

            if board[i][j] == 'W':
                if not board[j][i] == 'L':
                    return False
            elif board[i][j] == 'D':
                if not board[j][i] == 'D':
                    return False
            elif board[i][j] == 'L':
                if not board[j][i] == 'W':
                    return False

    return True


if __name__ == '__main__':
    if main():
        print('correct')
    else:
        print('incorrect')
