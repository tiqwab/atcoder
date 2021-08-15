INF = 1000 * 1000 * 1000 + 10

def main() -> int:
    N, M = [int(x) for x in input().split(' ')]
    xs = [int(x) for x in input().split(' ')]
    ys = [int(x) for x in input().split(' ')]
    xs = sorted(xs)
    ys = sorted(ys)

    ix = 0
    iy = 0
    ans = INF

    while ix < len(xs) and iy < len(ys):
        x = xs[ix]
        y = ys[iy]
        ans = min(ans, abs(x - y))

        if x < y:
            ix += 1
        else:
            iy += 1

    return ans


if __name__ == '__main__':
    print(main())
