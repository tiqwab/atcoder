import copy
import typing


def rec(ss: typing.List[str], n: int, N: int) -> typing.List[str]:
    if n > N:
        return ss

    cur_ss = copy.copy(ss)
    cur_ss.append(str(n))
    cur_ss.extend(ss)
    return rec(cur_ss, n + 1, N)


def main():
    n = int(input())
    print(" ".join(rec([], 1, n)))


if __name__ == '__main__':
    main()
