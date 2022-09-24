def main() -> str:
    ins = [int(x) for x in input().split(' ')]
    v = ins[0]
    ws = ins[1:]
    turn = 0

    while True:
        w = ws[turn]
        if v - w < 0:
            return turn
        v -= w
        turn = (turn + 1) % 3


if __name__ == '__main__':
    ans = main()
    if ans == 0:
        print("F")
    elif ans == 1:
        print("M")
    else:
        print("T")
