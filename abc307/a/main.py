def main():
    N = int(input())
    xs = [int(x) for x in input().split(' ')]

    ans = []
    for i in range(N):
        acc = 0
        for j in range(7):
            acc += xs[i * 7 + j]
        ans.append(str(acc))

    print(' '.join(ans))



if __name__ == '__main__':
    main()
