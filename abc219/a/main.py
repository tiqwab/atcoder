def main() -> str:
    X = int(input())
    if X < 40:
        return str(40 - X)
    elif X < 70:
        return str(70 - X)
    elif X < 90:
        return str(90 - X)
    else:
        return "expert"

if __name__ == '__main__':
    print(main())
