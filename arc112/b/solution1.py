def solve():
    [B, C] = map(int, input().split())

    if B >= 0:
        # [l, r]
        if C >= 1:
            area1 = [-B - (C - 1) // 2, -1 * max(0, B - (C - 1) // 2)]
        else:
            area1 = None

        # [l, r]
        area2 = [B - C // 2, B]

        # [l, r]
        if C >= 4:
            area3 = [B + 1, B + (C - 2) // 2]
        else:
            area3 = None

    else:
        area1 = [B - C // 2, B + (C - 2) // 2]

        if C >= 1:
            area2 = [-B - (C - 1) // 2, -B + (C - 1) // 2]
        else:
            area2 = None

        area3 = None

    # print(area1, area2, area3)

    areas = list(filter(lambda ar: ar is not None, [area1, area2, area3]))
    acc = []

    acc.append(areas[0])

    for i in range(1, len(areas)):
        area = areas[i]
        cur_area = acc[-1]
        if cur_area[1] < area[0]:
            acc.append(area)
        else:
            acc[-1][0] = min(area[0], cur_area[0])
            acc[-1][1] = max(area[1], cur_area[1])

    # print(acc)

    ans = 0
    for area in acc:
        ans += area[1] - area[0] + 1
    return ans

if __name__ == '__main__':
    print(solve())
