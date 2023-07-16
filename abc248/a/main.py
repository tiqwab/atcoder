def main() -> int:
    cs = input().strip()

    exists = [False for i in range(10)]

    for c in cs:
        exists[ord(c) - ord('0')] = True

    for (i, b) in enumerate(exists):
        if not b:
            return i

    return -1


if __name__ == '__main__':
    print(main())
