def main():
    N = int(input())
    used = [False for _ in range(2 * N + 1)]

    for _ in range(N):
        for i in range(len(used)):
            if not used[i]:
                used[i] = True
                print(i + 1)
                break

        got = int(input())
        used[got - 1] = True

    for i in range(len(used)):
        if not used[i]:
            used[i] = True
            print(i + 1)
            break

    got = int(input())
    if got != 0:
        raise Exception(f"unexpected number: {got}\n")


if __name__ == '__main__':
    main()
