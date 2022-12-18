import math

def main():
    A, B = [int(x) for x in input().split(' ')]
    ll = A * A + B * B
    x = math.sqrt(A * A / ll)
    y = math.sqrt(B * B / ll)
    return x, y


if __name__ == '__main__':
    x, y = main()
    print(f"{x} {y}")
