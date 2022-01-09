def main():
    N, K, A = [int(x) for x in input().split(' ')]
    return ((A + K - 2) % N) + 1


if __name__ == '__main__':
    print(main())
