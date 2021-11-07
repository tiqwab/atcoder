def main() -> (str, str):
    S = input().strip()
    slen = len(S)
    ss = []

    for i in range(0, slen):
        s = []
        for j in range(0, slen):
            s.append(S[(i + j) % slen])
        ss.append(''.join(s))

    ss.sort()
    return ss[0], ss[-1]


if __name__ == '__main__':
    s_min, s_max = main()
    print(s_min)
    print(s_max)
