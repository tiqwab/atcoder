def main() -> int:
    N, X = [int(x) for x in input().split(' ')]
    stages = []
    for _ in range(N):
        a, b = [int(x) for x in input().split(' ')]
        stages.append((a, b))

    ans = (1000 ** 9) # more than expected answer

    base = 0  # accumulate of time to play stages at the first time

    for i in range(N):
        base += stages[i][0] + stages[i][1]
        ans = min(ans, base + max(0, (X - i - 1)) * stages[i][1])

    return ans


if __name__ == '__main__':
    print(main())
