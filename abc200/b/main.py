if __name__ == '__main__':
    N, K = map(int, input().split(' '))

    for i in range(K):
        if N % 200 == 0:
            N //= 200
        else:
            N *= 1000
            N += 200

    print(N)
