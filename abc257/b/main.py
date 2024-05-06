from typing import List


def main() -> List[int]:
    N, K, Q = [int(x) for x in input().split(' ')]
    xs = [int(x) - 1 for x in input().split(' ')]
    ls = [int(x) for x in input().split(' ')]

    cells = [0] * N
    for x in xs:
        cells[x] += 1

    for l in ls:
        order = 0
        target = -1
        for i, x in enumerate(cells):
            if x > 0:
                order += 1
                if order == l:
                    target = i
                    break
        if target < N - 1 and cells[target + 1] == 0:
            cells[target + 1] += 1
            cells[target] -= 1

    ans = []
    for i, x in enumerate(cells):
        if x > 0:
            ans.append(i + 1)
    return ans


if __name__ == '__main__':
    ans = ' '.join(map(lambda x: str(x), main()))
    print(ans)
