import math

if __name__ == '__main__':
    [A, B, W] = map(int, input().split(' '))
    W *= 1000

    l = math.ceil(W / B)
    r = math.floor(W / A)

    if l <= r:
        print(f"{l} {r}")
    else:
        print("UNSATISFIABLE")
