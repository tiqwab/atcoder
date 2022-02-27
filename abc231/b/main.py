def main() -> str:
    N = int(input())

    candidates = dict()
    for _ in range(N):
        name = input()
        v = candidates.get(name) or 0
        candidates[name] = v + 1

    ans = None
    max_v = 0
    for k, v in candidates.items():
        if v > max_v:
            ans = k
            max_v = v

    return ans


if __name__ == '__main__':
    print(main())
