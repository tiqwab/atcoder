def main():
    N = int(input())
    ss = [int(x) for x in input().split(' ')]

    cands = set()
    for a in range(1, 1001):
        for b in range(1, 1001):
            cands.add(4 * a * b + 3 * a + 3 * b)

    cnt = 0
    for s in ss:
        if s not in cands:
            cnt += 1
    return cnt


if __name__ == '__main__':
    print(main())
