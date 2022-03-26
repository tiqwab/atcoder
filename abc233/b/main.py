def main():
    L, R = [int(x) for x in input().split(' ')]
    L -= 1
    R -= 1
    S = input()
    for i in range(0, L):
        print(S[i], end='')
    for i in range(R, L - 1, -1):
        print(S[i], end='')
    for i in range(R + 1, len(S)):
        print(S[i], end='')
    print('')


if __name__ == '__main__':
    main()
