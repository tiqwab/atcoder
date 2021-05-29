import typing


def calc_comb(A: int, B: int) -> typing.List[typing.List[int]]:
    # ans[A][B]
    ans = [[0 for _ in range(0, B + 1)] for _ in range(0, A + 1)]
    ans[0][0] = 1

    for a in range(0, A + 1):
        for b in range(0, B + 1):
            if a == 0 and b == 0:
                continue
            acc = 0
            if a - 1 >= 0:
                acc += ans[a - 1][b]
            if b - 1 >= 0: 
                acc += ans[a][b - 1]
            ans[a][b] = acc

    return ans


def main():
    A, B, K = [int(x) for x in input().split(' ')]
    comb = calc_comb(A, B)

    a = A
    b = B
    k = K
    ans = []
    for i in range(A + B):
        if a == 0:
            ans.append('b')
            b -= 1
        elif b == 0:
            ans.append('a')
            a -= 1
        else:
            # the number of patterns if use 'A' for i
            pats_a = comb[a - 1][b]
            if k <= pats_a:
                # should use 'a' for i
                ans.append('a')
                a -= 1
            else:
                # should use 'b' for i
                ans.append('b')
                b -= 1
                k -= pats_a
    print(''.join(ans))


if __name__ == '__main__':
    main()
