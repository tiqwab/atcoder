def main() -> int:
    N = int(input())
    S = input()
    ws = [int(x) for x in input().split(' ')]

    # (w, is_adult)
    ps = []
    for i in range(N):
        is_adult = S[i] == '1'
        ps.append((ws[i], is_adult))
    ps = sorted(ps)

    cnt = 0
    for w, is_adult in ps:
        if is_adult:
            cnt += 1
    ans = cnt

    # qs[w] = [is_adult]
    qs = dict()
    for w, is_adult in ps:
        if qs.get(w) is None:
            qs[w] = [is_adult]
        else:
            qs[w].append(is_adult)

    # (w, [is_adult])
    rs = sorted(qs.items(), key=lambda x: x[0])

    for _, is_adults in rs:
        for is_adult in is_adults:
            if is_adult:
                cnt -= 1
            else:
                cnt += 1
        ans = max(ans, cnt)

    return ans


if __name__ == '__main__':
    print(main())
