def main():
    N = int(input())
    T = input()

    dirs = [[1, 0], [0, -1], [-1, 0], [0, 1]]

    x = 0
    y = 0
    cur = 0

    for t in T:
        if t == 'S':
            x = x + dirs[cur][0]
            y = y + dirs[cur][1]
        else:
            cur = (cur + 1) % len(dirs)

    return x, y

if __name__ == '__main__':
    ans = main()
    print(f"{ans[0]} {ans[1]}")
