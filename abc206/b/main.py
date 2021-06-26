def main():
    N = int(input())
    acc = 0
    for i in range(1, 100000):
        acc += i
        if acc >= N:
            return i

if __name__ == '__main__':
    print(main())
