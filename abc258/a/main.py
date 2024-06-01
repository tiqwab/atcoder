def main() -> str:
    K = int(input())
    h = 21 + (K // 60)
    m = K % 60
    return f"{h:02d}:{m:02d}"


if __name__ == '__main__':
    print(main())
