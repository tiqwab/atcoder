import math

def parse(s: str) -> int:
    arr = s.split('.')

    # already integer
    if len(arr) == 1:
        return int(arr[0]) * 10000

    ans = int(arr[0])

    for i in range(0, len(arr[1])):
        ans = ans * 10 + int(arr[1][i])

    for i in range(0, 4 - len(arr[1])):
        ans = ans * 10

    return ans

def check(x: int, X: int, y: int, Y: int, R: int) -> bool:
    return (x - X) ** 2 + (y - Y) ** 2 <= R ** 2

def do_solve(X: int, Y: int, R: int, lim: int) -> int:
    ans = 0
    l = 0
    r = 1
    for y in range(1000 * 1000 * 1000 + 50000, lim - 10000, -10000):
        while check(r * 10000, X, y, Y, R):
            r += 1

        while check(l * 10000, X, y, Y, R):
            l -= 1
        ans += r - l - 1
    return ans

def solve() -> int:
    [X, Y, R] = [parse(x) for x in input().split()]
    X = abs(X) % 10000
    Y = abs(Y) % 10000
    # print(X, Y, R)

    ans = 0
    ans += do_solve(X, Y, R, 10000)
    ans += do_solve(X, -Y, R, 0)
    return ans

if __name__ == '__main__':
    print(solve())
