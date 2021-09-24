def main():
    d = {"ABC", "ARC", "AGC", "AHC"}
    S1 = input().strip()
    d.remove(S1)
    S2 = input().strip()
    d.remove(S2)
    S3 = input().strip()
    d.remove(S3)
    return d.pop()

if __name__ == '__main__':
    print(main())
