def main():
    N = int(input())
    counter = dict()

    for _ in range(N):
        s = input().strip()
        if s in counter:
            print(f"{s}({counter[s]})")
            counter[s] += 1
        else:
            print(s)
            counter[s] = 1


if __name__ == '__main__':
    main()
