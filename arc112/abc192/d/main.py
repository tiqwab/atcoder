def f(X: str, M: int, mid: int) -> bool:
    acc = 0
    for i in X:
        acc = acc * mid + int(i)
        if acc > M:
            return False
    return True


def solve1(X: str, M: int, d: int) -> int:
    l = 0
    r = 10000000000000000000 # 10^19

    while r - l > 1:
        mid = l + (r - l) // 2
        if f(X, M, mid):
            l = mid
        else:
            r = mid

    return max(0, l - d)

def main():
    X = input()
    M = int(input())

    d = 0
    for i in X:
        if d < int(i):
            d = int(i)

    if len(X) == 1:
        if int(X) <= M:
            print(1)
        else:
            print(0)
    else:
        print(solve1(X, M, d))

if __name__ == '__main__':
    main()
