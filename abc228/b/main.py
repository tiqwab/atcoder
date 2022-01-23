def main() -> int:
    N, X = [int(x) for x in input().split(' ')]
    speak_to = [int(x) - 1 for x in input().split(' ')]
    does_know = [False] * N

    cur = X - 1
    while not does_know[cur]:
        does_know[cur] = True
        cur = speak_to[cur]

    return does_know.count(True)


if __name__ == '__main__':
    print(main())
