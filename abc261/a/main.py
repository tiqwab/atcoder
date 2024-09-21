def main() -> int:
    l1, r1, l2, r2 = [int(x) for x in input().split(' ')]
    if l1 > l2:
        l_tmp = l1
        r_tmp = r1
        l1 = l2
        r1 = r2
        l2 = l_tmp
        r2 = r_tmp
    if r1 <= l2: 
        return 0
    if r1 > l2 and r1 <= r2:
        return r1 - l2
    else:
        return r2 - l2


if __name__ == '__main__':
    print(main())
