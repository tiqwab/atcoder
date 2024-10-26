def main() -> str:
    y = int(input())
    if y % 4 == 0:
        return y + 2
    elif y % 4 == 1:
        return y + 1
    elif y % 4 == 2:
        return y
    elif y % 4 == 3:
        return y + 3


if __name__ == '__main__':
    print(main())
