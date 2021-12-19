def main():
    X = input()
    xs = X.split('.')
    x = int(xs[0])
    y = int(xs[1][0])
    if y >= 5:
        return x + 1
    else:
        return x


if __name__ == '__main__':
    print(main())
