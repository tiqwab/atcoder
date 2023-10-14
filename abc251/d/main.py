def main():
    _ = input()

    ans = []
    for i in range(1, 100):
        ans.append(str(i))
    for i in range(100, 10000, 100):
        ans.append(str(i))
    for i in range(10000, 1000000, 10000):
        ans.append(str(i))
    ans.append(str(1000000))

    print(len(ans))
    print(' '.join(ans))


if __name__ == '__main__':
    main()
