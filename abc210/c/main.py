def main() -> int:
    N, K = [int(x) for x in input().split(' ')]
    cs = [int(x) for x in input().split(' ')]

    counter = dict()

    for i in range(0, K):
        counter[cs[i]] = counter.get(cs[i], 0) + 1

    ans = len(counter)

    for i in range(K, N):
        counter[cs[i]] = counter.get(cs[i], 0) + 1
        counter[cs[i - K]] -= 1
        if counter[cs[i - K]] == 0:
            counter.pop(cs[i - K])
        ans = max(ans, len(counter))

    return ans

if __name__ == '__main__':
    print(main())
