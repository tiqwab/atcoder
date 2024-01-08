def gcd(a: int, b: int) -> int:
    if a > b:
        a, b = b, a
    if a == 0:
        return b
    return gcd(b % a, a)


def lcm(a: int, b: int) -> int:
    g = gcd(a, b)
    return a * b // g


def main() -> int:
    N, a, b = [int(x) for x in input().split(' ')]
    l = lcm(a, b)
    na = N // a
    nb = N // b
    nl = N // l
    max_a = na * a
    max_b = nb * b
    max_l = nl * l
    return ((1 + N) * N // 2) - ((a + max_a) * na // 2) - ((b + max_b) * nb // 2) + ((l + max_l) * nl // 2)


if __name__ == '__main__':
    print(main())
