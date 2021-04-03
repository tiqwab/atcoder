import math

def solve():
    N = int(input())

    x_s, y_s = map(float, input().split(' '))
    s1 = complex(x_s, y_s)

    x_d, y_d = map(float, input().split(' '))

    center_x = (x_s + x_d) / 2.0
    center_y = (y_s + y_d) / 2.0
    center = complex(center_x, center_y)

    theta = 2.0 * math.pi * float(360 / N) / 360.0

    s2 = s1 - center
    s2 *= complex(math.cos(theta), math.sin(theta))
    s2 += center
    print(s2.real, s2.imag)


if __name__ == '__main__':
    solve()
