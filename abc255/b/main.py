MAX_X = 100000
DEVIATION = 0.000001


def check(lights, positions, target) -> bool:
    for one in positions:
        ok = False
        for k in lights:
            two = positions[k]
            d = (one[0] - two[0]) ** 2 + (one[1] - two[1]) ** 2
            if d <= target ** 2:
                ok = True
                break
        if not ok:
            return False
    return True


def main() -> float:
    N, K = [int(x) for x in input().split(' ')]
    lights = [int(x) - 1 for x in input().split(' ')]
    positions = [[int(x) for x in input().split(' ')] for _ in range(N)]

    left = 0
    right = MAX_X * 4
    while right - left > DEVIATION:
        cand = left + (right - left) / 2
        if check(lights, positions, cand):
            right = cand
        else:
            left = cand

    return right


if __name__ == '__main__':
    print(main())
