import typing


def factorial(x: int) -> int:
    if x == 0:
        return 1
    else:
        return x * factorial(x - 1)


def calc_comb(A: int, B: int) -> typing.Dict[typing.Tuple[int, int], int]:
    ans = dict()
    for a in range(0, A + 1):
        for b in range(0, B + 1):
            ans[(a, b)] = factorial(a + b) // (factorial(a) * factorial(b))
    ans[(0, 0)] = 0
    return ans


def main():
    A, B, K = [int(x) for x in input().split(' ')]
    comb = calc_comb(A, B)

    a = A
    b = B
    k = comb[(A, B)] - K + 1
    ans = []
    for i in range(A + B):
        if a == 0:
            ans.append('b')
            b -= 1
        elif b == 0:
            ans.append('a')
            a -= 1
        else:
            # the number of patterns if use 'B' for i
            pats_b = comb[(a, b - 1)]
            if k <= pats_b:
                # should use 'B' for i
                ans.append('b')
                b -= 1
            else:
                # should use 'A' for i
                ans.append('a')
                a -= 1
                k -= pats_b
    print(''.join(ans))


if __name__ == '__main__':
    main()
