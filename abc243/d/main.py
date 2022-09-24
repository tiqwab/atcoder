def main() -> int:
    N, X = [int(x) for x in input().split(' ')]
    S = input()

    cur = X
    for i in range(N):
        move = S[i]
        if move == 'U':
            cur = cur // 2
        elif move == 'L':
            cur = cur * 2
        else:
            cur = cur * 2 + 1
    return cur


if __name__ == '__main__':
    print(main())
