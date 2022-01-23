def main():
    N, K = [int(x) for x in input().split(' ')]

    scores = []
    for i in range(N):
        scores.append([int(x) for x in input().split(' ')])

    total_scores = list(map(lambda xs: sum(xs), scores))
    total_scores.sort()
    total_scores.reverse()

    border = total_scores[K - 1]

    for xs in scores:
        total = sum(xs)
        if total + 300 >= border:
            print('Yes')
        else:
            print('No')


if __name__ == '__main__':
    main()
