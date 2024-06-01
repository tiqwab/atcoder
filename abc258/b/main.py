def main() -> int:
    N = int(input())
    cells = []
    for i in range(N):
        line = [int(x) for x in list(input())]
        cells.append(line)

    # (diff_y, diff_x)
    dirs = [(0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1)]

    ans = 0

    for start_y in range(N):
        for start_x in range(N):
            for (diff_y, diff_x) in dirs:
                acc = 0
                for i in range(N):
                    y = (start_y + diff_y * i + N) % N
                    x = (start_x + diff_x * i + N) % N
                    acc = acc * 10 + cells[y][x]
                # print(acc)
                ans = max(ans, acc)

    return ans


if __name__ == '__main__':
    print(main())
