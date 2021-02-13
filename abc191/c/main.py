import sys

def solve():
    [H, W] = map(int, (input().split()))

    board = [input() for _ in range(H)]

    ans = 0

    for y in range(1, H):
        for x in range(1, W):
            cnt = 0
            for by, bx in [(y - 1, x - 1), (y - 1, x), (y, x - 1), (y, x)]:
                if board[by][bx] == '#':
                    cnt += 1
            if cnt == 1 or cnt == 3:
                ans += 1

    return ans

if __name__ == '__main__':
    print(solve())
