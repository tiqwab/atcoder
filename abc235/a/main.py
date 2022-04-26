def main() -> int:
    s = input();
    a = int(s[0])
    b = int(s[1])
    c = int(s[2])
    x = a * 100 + b * 10 + c
    y = b * 100 + c * 10 + a
    z = c * 100 + a * 10 + b
    return x + y + z


if __name__ == '__main__':
    print(main())
