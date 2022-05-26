def main() -> str:
    S = list(input())
    a, b = [int(x) - 1 for x in input().split(' ')]
    S[a], S[b] = S[b], S[a]
    return ''.join(S)


if __name__ == '__main__':
    print(main())
