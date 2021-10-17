def main() -> int:
    N = int(input())
    xs = [int(x) for x in input().split(' ')]
    X = int(input())

    sum_xs = sum(xs)

    ans = X // sum_xs * N
    rem = X % sum_xs

    for i in range(N):
        if rem < 0:
            break
        rem -= xs[i]
        ans += 1

    return ans


if __name__ == '__main__':
    print(main())
