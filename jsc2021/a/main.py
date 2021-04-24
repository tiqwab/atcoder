def main():
    X, Y, Z = list(map(int, input().split(' ')))

    ans = 0

    for i in range(1, Y * Z + 1):
        if Y * Z <= X * i:
            break
        ans = i
    return ans

if __name__ == '__main__':
    print(main())
