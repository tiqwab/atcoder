def main() -> str:
    ps = [int(x) for x in input().split(' ')]
    ans = []
    for p in ps:
        ans.append(chr(ord('a') + (p - 1)))
    return ''.join(ans)

if __name__ == '__main__':
    print(main())
