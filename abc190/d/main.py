def calc_divs(x):
    res = []
    i = 1
    while i * i <= x:
        if x % i == 0:
            if i * i == x:
                res.append(i)
            else:
                res.append(i)
                res.append(x // i)
        i += 1
    return sorted(res)

def solve():
    N = 2 * int(input())
    divs = calc_divs(N)
    cnt = 0
    for x in divs:
        y = N // x
        if x % 2 == y % 2:
            continue
        a = (x - y + 1) // 2
        b = (x + y - 1) // 2
        cnt += 1
    return cnt

if __name__ == '__main__':
    print(solve())
