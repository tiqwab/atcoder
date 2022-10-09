def main():
    N = int(input())
    print(2 * N + 1)

    for i in range(N):
        got = int(input())
        print(2 * N + 1 - got)

    got = int(input())
    if got != 0:
        raise Exception(f"expected 0 but got {got}\n")


if __name__ == '__main__':
    main()
