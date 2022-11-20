def main() -> str:
    A, B, C, D = [int(x) for x in input().split(' ')]
    if A < C:
        return "Takahashi"
    elif A > C:
        return "Aoki"
    else:
        if B <= D:
            return "Takahashi"
        else:
            return "Aoki"


if __name__ == '__main__':
    print(main())
