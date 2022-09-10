def main() -> str:
    S = input()
    cs = [0 for _ in range(26)]
    for c in S:
        cs[ord(c) - ord('a')] += 1
    ll = []
    for i in range(len(cs)):
        ll.append(chr(ord('a') + i) * cs[i])
    return ''.join(ll)

if __name__ == '__main__':
    print(main())
