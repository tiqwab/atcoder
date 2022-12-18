def main():
    xs = set()
    ys = set()
    ps = set()
    for _ in range(3):
        x, y = input().split(' ')
        xs.add(x)
        ys.add(y)
        ps.add((x, y))

    for x in xs:
        for y in ys:
            if not (x, y) in ps:
                return x, y


if __name__ == '__main__':
    x, y = main()
    print(f"{x} {y}")
