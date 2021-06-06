def main():
    a, b, c = [int(x) for x in input().split(' ')]
    if a == b:
        return c
    elif b == c:
        return a
    elif c == a:
        return b
    else:
        return 0

if __name__ == '__main__':
    print(main())
