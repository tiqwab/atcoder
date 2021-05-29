def main() -> int:
    N = int(input())
    aa = [int(x) for x in input().split(' ')]
    bb = [int(x) for x in input().split(' ')]
    cc = [int(x) for x in input().split(' ')]

    counter = dict()
    for i in range(0, N):
        k = bb[cc[i] - 1]
        v = counter.get(k) or 0
        counter[k] = v + 1

    ans = 0
    for i in range(0, N):
        ans += counter.get(aa[i]) or 0

    return ans

if __name__ == '__main__':
    print(main())
