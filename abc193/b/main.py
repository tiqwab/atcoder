INF = 1000 * 1000 * 1000 + 1

def solve():
    N = int(input())

    ans = INF

    for i in range(0, N):
        [A, P, X] = map(int, input().split(' '))
        if A < X:
            ans = min(ans, P)

    if ans == INF:
        return -1
    else:
        return ans

if __name__ == '__main__':
    print(solve())
