def main() -> int:
    N = int(input())
    vs = [int(x) for x in input().split(' ')]

    cut_ps = [0]
    cur_p = 0
    for v in vs:
        cur_p = (cur_p + v) % 360
        cut_ps.append(cur_p)
    cut_ps.append(360)
    cut_ps.sort()

    ans = 0
    for i in range(len(cut_ps) - 1):
        ans = max(ans, cut_ps[i + 1] - cut_ps[i])
    return ans


if __name__ == '__main__':
    print(main())
