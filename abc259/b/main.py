import math


def main():
    a, b, d = [int(x) for x in input().split(' ')]
    theta = d / 360 * 2 * math.pi
    x = a * math.cos(theta) - b * math.sin(theta)
    y = a * math.sin(theta) + b * math.cos(theta)
    return (x, y)


if __name__ == '__main__':
    x, y = main()
    print(x, y)
