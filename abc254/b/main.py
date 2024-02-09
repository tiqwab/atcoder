from typing import List


def main():
    N = int(input())

    prev_line = []

    for i in range(N):
        cur_line = []
        for j in range(i + 1):
            if j == 0 or j == i:
                cur_line.append(1)
            else:
                cur_line.append(prev_line[j - 1] + prev_line[j])
        print(' '.join(format_line(cur_line)))
        prev_line = cur_line


def format_line(l: List[int]) -> List[str]:
    res = []
    for x in l:
        res.append(str(x))
    return res


if __name__ == '__main__':
    main()
