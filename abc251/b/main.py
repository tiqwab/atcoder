def main() -> int:
    N, W = [int(x) for x in input().split(' ')]
    xs = [int(x) for x in input().split(' ')]

    used = set()

    for i in range(0, N):
        if xs[i] <= W:
            used.add(xs[i])
        for j in range(i + 1, N):
            if xs[i] + xs[j] <= W:
                used.add(xs[i] + xs[j])
            for k in range(j + 1, N):
                if xs[i] + xs[j] + xs[k] <= W:
                    used.add(xs[i] + xs[j] + xs[k])

    return len(used)



if __name__ == '__main__':
    print(main())
