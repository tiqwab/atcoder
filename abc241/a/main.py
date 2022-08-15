def main() -> int:
    xs = [int(x) for x in input().split(' ')]
    i = 0
    ans = 0
    for _ in range(3):
        ans = xs[i]
        i = ans
    return ans


if __name__ == '__main__':
    print(main())
