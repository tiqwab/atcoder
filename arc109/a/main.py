def solve(a, b, x, y):
    if a == b:
        ans = x
    elif a < b:
        ans = x
        ans += min(x * 2, y) * (b - a)
    else:
        ans = x
        ans += min(x * 2, y) * (a - b - 1)

    return ans

if __name__ == '__main__':
    a, b, x, y = [int(x) for x in input().split()]
    print(solve(a, b, x, y))
