def main() -> int:
    P = int(input())

    coins = [1]
    for i in range(2, 11):
        coins.append(coins[-1] * i)
    coins.reverse()

    cnt = 0
    for i in coins:
        for j in range(1, 101):
            if i * j > P:
                cnt += j - 1;
                P -= i * (j - 1)
                break;
    return cnt


if __name__ == '__main__':
    print(main())
