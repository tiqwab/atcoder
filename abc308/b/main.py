def main() -> int:
    N, M = [int(x) for x in input().split(' ')]
    cs = [x for x in input().split(' ')]
    ds = [x for x in input().split(' ')]
    ps = [int(x) for x in input().split(' ')]

    default_price = ps[0]

    prices = dict()
    for i in range(M):
        prices[ds[i]] = ps[i + 1]

    ans = 0
    for i in range(N):
        price = default_price
        if prices.get(cs[i]) is not None:
            price = prices[cs[i]]
        ans += price

    return ans


if __name__ == '__main__':
    print(main())
