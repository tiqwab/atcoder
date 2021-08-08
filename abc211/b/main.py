def main() -> bool:
    S1 = input().strip()
    S2 = input().strip()
    S3 = input().strip()
    S4 = input().strip()

    se = set()
    se.add(S1)
    se.add(S2)
    se.add(S3)
    se.add(S4)
    return len(se) == 4


if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
