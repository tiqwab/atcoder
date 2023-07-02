def check(s: str) -> bool:
    t = ''.join(reversed(list(s)))
    return s == t


def main() -> bool:
    N = int(input())

    ss = []
    for i in range(N):
        s = input().strip()
        ss.append(s)

    for i in range(N):
        for j in range(N):
            if i == j:
                continue

            cand = ss[i] + ss[j]
            if check(cand):
                return True

    return False


if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
