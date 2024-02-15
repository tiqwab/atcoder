def main() -> int:
    X, A, D, N = [int(x) for x in input().split(' ')]

    if D == 0:
        return abs(A - X)

    a_first = A
    a_last = A + D * (N - 1)
    if D < 0:
        a_first, a_last = a_last, a_first
        D *= -1

    if X <= a_first:
        return a_first - X
    if X >= a_last:
        return X - a_last

    m = (X - a_first) // D
    return min(X - (a_first + m * D), (a_first + (m + 1) * D) - X) 


if __name__ == '__main__':
    print(main())
