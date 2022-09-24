def solve1(N, aa, bb) -> int:
    ans = 0
    for i in range(N):
        if aa[i] == bb[i]:
            ans += 1
    return ans


def solve2(N, aa, bb) -> int:
    ans = 0
    for i in range(N):
        for j in range(N):
            if aa[i] == bb[j] and i != j:
                ans += 1
    return ans


def main():
    N = int(input())
    aa = [int(x) for x in input().split(' ')]
    bb = [int(x) for x in input().split(' ')]

    print(solve1(N, aa, bb))
    print(solve2(N, aa, bb))


if __name__ == '__main__':
    main()
