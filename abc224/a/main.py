def main() -> str:
    s = input().strip()
    if s.endswith("er"):
        return "er"
    else:
        return "ist"


if __name__ == '__main__':
    print(main())
