import math


def main() -> float:
    N = int(input())
    ps = [[int(p) for p in input().split(' ')] for _ in range(N)]

    ans = 0
    for one in ps:
        for two in ps:
            diff_x = one[0] - two[0]
            diff_y = one[1] - two[1]
            ans = max(ans, diff_x * diff_x + diff_y * diff_y)

    return math.sqrt(ans)


if __name__ == '__main__':
    print(main())
