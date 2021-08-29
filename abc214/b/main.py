def main() -> int:
    S, T = [int(x) for x in input().split(' ')]

    ans = 0

    for a in range(0, 101):
        for b in range(0, 101):
            for c in range(0, 101):
                if a + b + c <= S and a * b * c <= T:
                    ans += 1

    return ans

if __name__ == '__main__':
    print(main())
