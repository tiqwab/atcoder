def main() -> int:
    N, K, X = [int(x) for x in input().split(' ')]
    items = [int(x) for x in input().split(' ')]

    price_sum = sum(items)
    gain = 0

    for i in range(N):
        k = min(K, items[i] // X)
        gain += X * k
        K -= k
        items[i] -= X * k

    items.sort(reverse=True)

    for i in range(N):
        if K > 0:
            gain += items[i]
            K -= 1

    return price_sum - gain



if __name__ == '__main__':
    print(main())
