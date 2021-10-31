def solve() -> int:
    N, P = [int(x) for x in input().split(' ')]
    xs = [int(x) for x in input().split(' ')];
    ans = 0
    for x in xs:
        if x < P:
            ans += 1
    return ans

if __name__ == '__main__':
    print(solve())
