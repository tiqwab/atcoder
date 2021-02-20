def solve():
    [B, C] = map(int, input().split())

    # [l, r]
    area1 = [-B - (C - 1) // 2, -B + (C - 1) // 2]
    area2 = [B - C // 2, B + max((C - 2), 0) // 2]

    ans = 0
    ans += area1[1] - area1[0] + 1
    ans += area2[1] - area2[0] + 1
    ans -= max(0, min(area1[1], area2[1]) - max(area1[0], area2[0]) + 1)

    return ans


if __name__ == '__main__':
    print(solve())
