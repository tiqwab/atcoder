def solve(L):
    acc = 1
    for i in range(L - 12 + 1, L - 12 + 11 + 1):
        acc *= i
    for i in range(1, 12):
        acc //= i
    return int(acc)

if __name__ == '__main__':
    L = int(input())
    print(solve(L))
