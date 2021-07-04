def main() -> int:
    N = int(input())

    # [l, r)
    intervals = []
    for i in range(0, N):
        t, l, r = [int(x) for x in input().split(' ')]

        if t == 1:
            r += 0.1
        elif t == 2:
            pass
        elif t == 3:
            l += 0.1
            r += 0.1
        else:
            l += 0.1

        intervals.append([l, r])

    ans = 0

    for i in range(0, N):
        for j in range(i + 1, N):
            one = intervals[i]
            two = intervals[j]
            if one[0] > two[0]:
                one, two = two, one

            if one[1] > two[0]:
                ans += 1

    return ans

if __name__ == '__main__':
    print(main())
