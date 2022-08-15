def main() -> bool:
    N, M = [int(x) for x in input().split(' ')]
    xs = [int(x) for x in input().split(' ')]
    ys = [int(x) for x in input().split(' ')]

    pastas = dict()
    for x in xs:
        if pastas.get(x):
            pastas[x] = pastas[x] + 1
        else:
            pastas[x] = 1

    for y in ys:
        if not pastas.get(y) or pastas[y] == 0:
            return False
        pastas[y] -= 1
    return True


if __name__ == '__main__':
    if main():
        print("Yes")
    else:
        print("No")
