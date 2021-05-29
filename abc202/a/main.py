def main():
    a, b, c = [int(x) for x in input().split(' ')]
    ans = 0
    ans += 7 - a
    ans += 7 - b
    ans += 7 - c
    return ans

if __name__ == '__main__':
    print(main())
