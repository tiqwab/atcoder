import typing


def calc_points_for(x, y) -> typing.List[typing.Tuple[int, int]]:
    diffs = [(1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1), (-2, 1), (-1, 2)]
    ans = []
    for (dx, dy) in diffs:
        ans.append((x + dx, y + dy))
    return ans


def main() -> bool:
    cx1, cy1, cx2, cy2 = [int(x) for x in input().split(' ')]

    cands1 = calc_points_for(cx1, cy1)
    cands2 = calc_points_for(cx2, cy2)

    for (x1, y1) in cands1:
        for (x2, y2) in cands2:
            if x1 == x2 and y1 == y2:
                return True
    return False


if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
