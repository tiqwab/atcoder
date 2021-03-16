import functools

def main() -> int:
    N = int(input())
    xs = [int(x) for x in input().split(' ')]

    a = functools.reduce(lambda x, y: x + y * y, xs, 0) 
    b = functools.reduce(lambda x, y: x + y, xs, 0)
    b *= b

    return (N * a - 2 * b + N * a) // 2

if __name__ == '__main__':
    print(main())
