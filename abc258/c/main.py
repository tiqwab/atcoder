def main():
    N, Q = [int(x) for x in input().split(' ')]
    S = input().strip()

    head = 0

    for _ in range(Q):
        t, x = [int(x) for x in input().split(' ')]
        if t == 1:
            head = (head - x + N) % N
        elif t == 2:
            print(S[(head + x - 1) % N])
        else:
            raise Exception(f"unexpected t value: {t}")


if __name__ == '__main__':
    main()
