def gcd(x, y):
    if x > y:
        x, y = y, x
    if x == 0:
        return y
    return gcd(y % x, x)

def lcm(x, y):
    return (x * y) // gcd(x, y)

def solve(N):
    ans = 1;
    for i in range(2, N+1):
        ans = lcm(ans, i)
    print(ans + 1)

if __name__ == '__main__':
    N = int(input())
    solve(N)
