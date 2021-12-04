def main() -> int:
    S = input()

    counter = dict()

    for c in S:
        if counter.get(c):
            counter[c] += 1
        else:
            counter[c] = 1

    if len(counter.keys()) == 1:
        return 1
    elif len(counter.keys()) == 2:
        return 3
    else:
        return 6


if __name__ == '__main__':
    print(main())
