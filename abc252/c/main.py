from typing import List

MAX_T = 10000


def check(c: str, ss: List[int]) -> int:
    poss = [0] * 10
    for s in ss:
        poss[s.index(c)] = poss[s.index(c)] + 1

    ans = 0
    for pos, count in enumerate(poss):
        ans = max(ans, pos + 10 * (count - 1))

    return ans


def main() -> int:
    N = int(input())
    ss = []
    for _ in range(N):
        ss.append(input().strip())

    ans = MAX_T
    for i in range(10):
        ans = min(ans, check(chr(ord('0') + i), ss))
    return ans


if __name__ == '__main__':
    print(main())
