def main() -> str:
    N = int(input())
    S = input().strip()

    r_blaces = []
    elems = []

    for i in range(N):
        c = S[i]

        if c == '(':
            elems.append(c)
            r_blaces.append(i)
        elif c == ')':
            if len(r_blaces) > 0:
                while elems.pop() != '(':
                    pass
                r_blaces.pop()
            else:
                elems.append(c)
        else:
            elems.append(c)

    return ''.join(elems)


if __name__ == '__main__':
    print(main())
