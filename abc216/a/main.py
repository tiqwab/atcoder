def main() -> str:
    X, Y = [int(x) for x in input().split('.')]
    if Y <= 2:
        return str(X) + "-"
    elif Y <= 6:
        return str(X)
    else:
        return str(X) + "+"

if __name__ == '__main__':
    print(main())
