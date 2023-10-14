def main() -> int:
    N = int(input())

    poems = set()
    highest_score = -1
    highest_idx = -1

    for i in range(N):
        s, t = input().split(' ')
        t = int(t)
        if s in poems:
            continue
        poems.add(s)
        if highest_score < t:
            highest_score = t
            highest_idx = i

    return highest_idx + 1


if __name__ == '__main__':
    print(main())
