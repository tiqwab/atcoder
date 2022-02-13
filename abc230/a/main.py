def main() -> str:
    N = int(input())
    if N >= 42:
        N += 1
    return f"AGC{N:0>3}"


if __name__ == '__main__':
    print(main())
