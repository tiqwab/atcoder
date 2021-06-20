def main() -> str:
    A, B, C = [int(x) for x in input().split(' ')]

    if C % 2 == 0:
        if abs(A) > abs(B):
            return '>'
        elif abs(A) == abs(B):
            return '='
        else:
            return '<'
    else:
        if A > B:
            return '>'
        elif A == B:
            return '='
        else:
            return '<'

if __name__ == '__main__':
    print(main())
