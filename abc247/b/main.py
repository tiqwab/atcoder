def main():
    n = int(input())

    people = []
    for i in range(n):
        s, t = input().strip().split(' ')
        people.append((s, t))

    ok = True

    for i in range(n):
        ok_for_i = False

        for name in [people[i][0], people[i][1]]:
            ok_for_name = True
            for j in range(n):
                if i == j:
                    continue
                if name == people[j][0] or name == people[j][1]:
                    ok_for_name = False
                    break
            if ok_for_name:
                ok_for_i = True

        if not ok_for_i:
            ok = False
            break

    if ok:
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    main()
