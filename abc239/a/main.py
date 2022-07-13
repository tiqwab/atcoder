import math


def main() -> float:
    H = int(input())
    return math.sqrt(H * (12800000 + H))


if __name__ == '__main__':
    print(main())
