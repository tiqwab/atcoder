def junken(c_left, c_right):
    if c_left == 'R':
        if c_right == 'R':
            return 'R'
        elif c_right == 'P':
            return 'P'
        else:
            return 'R'
    elif c_left == 'P':
        if c_right == 'R':
            return 'P'
        elif c_right == 'P':
            return 'P'
        else:
            return 'S'
    else:
        if c_right == 'R':
            return 'R'
        elif c_right == 'P':
            return 'S'
        else:
            return 'S'


def main(n, k, s):
    prev_s = s
    new_s = []
    for _ in range(0, k):
        t = prev_s + prev_s
        for i in range(0, n):
            new_s.append(junken(t[i * 2], t[i * 2 + 1]))
        prev_s = new_s
        new_s = []
    print(prev_s[0])


if __name__ == '__main__':
    n, k = [int(x) for x in input().split()]
    s = input()
    main(n, k, s)
