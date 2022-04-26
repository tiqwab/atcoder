def main() -> int:
    N = int(input())
    hs = [int(x) for x in input().split(' ')]
    pos = 0
    while pos < N - 1:
        if hs[pos] < hs[pos + 1]:
            pos += 1
        else:
            break
    return hs[pos]

if __name__ == '__main__':
    print(main())
