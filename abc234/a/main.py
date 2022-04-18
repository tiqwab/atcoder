def f(x: int) -> int:
    return x * x + 2 * x + 3


def main() -> int:
    t = int(input())
    return f(f(f(t) + t) + f(f(t)))


if __name__ == '__main__':
    print(main())
