def main() -> bool:
    N, X = [int(x) for x in input().split(' ')]
    xs = [int(x) for x in input().split(' ')]

    acc = 0

    for i in range(1, N + 1):
        if i % 2 == 0:
            acc += xs[i - 1] - 1
        else:
            acc += xs[i - 1]

    return X >= acc

if __name__ == '__main__':
    if main():
        print("Yes")
    else:
        print("No")
