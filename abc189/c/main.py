MAX_A = 100000

def solve():
    N = int(input())
    vs = [int(x) for x in input().split(' ')]

    ans = 0

    # [l, r]
    for l in range(0, N):
        min_v = MAX_A
        for r in range(l, N):
            min_v = min(min_v, vs[r])
            ans = max(ans, min_v * (r - l + 1))

    return ans

if __name__ == '__main__':
    print(solve())
