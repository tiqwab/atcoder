def solve(a: int, s: int) -> bool:
    s -= 2 * a
    if s < 0:
        return False
    return (a & s) == 0


def main():
    T = int(input())
    for _ in range(T):
        a, s = [int(x) for x in input().split(' ')]
        if solve(a, s):
            print("Yes")
        else:
            print("No")


if __name__ == '__main__':
    main()
