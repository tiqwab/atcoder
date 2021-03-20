if __name__ == '__main__':
    N = int(input())

    cnt = 0

    for x in [10 ** 3, 10 ** 6, 10 ** 9, 10 ** 12, 10 ** 15]:
        if N >= x:
            cnt += N - x + 1

    print(cnt)
