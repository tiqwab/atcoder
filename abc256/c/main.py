def main() -> int:
    h1, h2, h3, w1, w2, w3 = [int(x) for x in input().split(' ')]

    ans = 0

    # a1, a2, a3
    # a4, a5, a6
    # a7, a8, a9
    for a1 in range(1, 31):
        for a2 in range(1, 31):
            for a4 in range(1, 31):
                for a5 in range(1, 31):
                    a3 = h1 - a1 - a2
                    a6 = h2 - a4 - a5
                    a7 = w1 - a1 - a4
                    a8 = w2 - a2 - a5
                    if a3 <= 0 or a6 <= 0 or a7 <= 0 or a8 <= 0:
                        continue
                    if w3 - a3 - a6 <= 0 or h3 - a7 - a8 <= 0:
                        continue
                    if w3 - a3 - a6 != h3 - a7 - a8:
                        continue
                    ans += 1

    return ans


if __name__ == '__main__':
    print(main())
