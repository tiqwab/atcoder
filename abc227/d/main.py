def check(mid, N, K, xs):
    acc = 0
    for x in xs:
        acc += min(x, mid)
    return acc >= mid * K


def main():
    N, K = [int(x) for x in input().split(' ')]
    xs = [int(x) for x in input().split(' ')]

    left = 0
    right = 2 * (10 ** 17) + 5

    while right - left > 1:
        mid = left + (right - left) // 2
        if (check(mid, N, K, xs)):
            left = mid
        else:
            right = mid

    return left


if __name__ == '__main__':
    print(main())
