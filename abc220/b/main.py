def convert10(s: str, k: int) -> int:
    acc = 0
    for c in s:
        acc *= k
        acc += ord(c) - ord('0')
    return acc

def main() -> int:
    K = int(input())
    A, B = [x for x in input().split(' ')]

    a = convert10(A, K)
    b = convert10(B, K)

    return a * b

if __name__ == '__main__':
    print(main())
