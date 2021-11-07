def main() -> float:
    N = int(input())
    bars = []
    for i in range(0, N):
        A, B = [int(x) for x in input().split(' ')]
        bars.append((A, B))

    total_seconds = sum(map(lambda x: x[0] / x[1], bars))
    seconds_from_left = total_seconds / 2

    ans = 0.0

    for A, B in bars:
        if seconds_from_left >= A / B:
            ans += A
            seconds_from_left -= A / B
        else:
            ans += B * seconds_from_left
            break

    return ans


if __name__ == '__main__':
    print(main())
