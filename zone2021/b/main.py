def main():
    N, D, H = map(int, input().split(' '))
    D = float(D)
    H = float(H)

    ans = 0.0

    for i in range(N):
        d, h = map(float, input().split(' '))
        b = H - (H - h) / (D - d) * D
        ans = max(ans, b)

    return ans

if __name__ == '__main__':
    print(main())
