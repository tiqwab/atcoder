def g1(x: int) -> int:
    s = str(x)
    return int(''.join((sorted(s, reverse=True))))

def g2(x: int) -> int:
    s = str(x)
    return int(''.join((sorted(s))))

def solve() -> int:
    [N, K] = map(int, input().split(' '))

    n = N

    for i in range(0, K):
        x1 = g1(n)
        x2 = g2(n)
        n = x1 - x2

    return n

if __name__ == '__main__':
    print(solve())
