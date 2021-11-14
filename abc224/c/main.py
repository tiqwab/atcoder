def main() -> int:
    N = int(input())

    points = []
    for i in range(0, N):
        x, y = [int(x) for x in input().split(' ')]
        points.append((x, y))

    ans = 0

    for i_a in range(0, N):
        for i_b in range(i_a + 1, N):
            for i_c in range(i_b + 1, N):
                a = points[i_a]
                b = points[i_b]
                c = points[i_c]

                if (b[1] - a[1]) * (c[0] - b[0]) != \
                        (c[1] - b[1]) * (b[0] - a[0]):
                    ans += 1

    return ans


if __name__ == '__main__':
    print(main())
