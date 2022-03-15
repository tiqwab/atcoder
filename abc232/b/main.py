def main() -> bool:
    S = input()
    T = input()
    l = len(S)

    for k in range(0, 26):
        s = []
        for i in range(0, l):
            s.append(chr(((ord(S[i]) - ord('a')) + k) % 26 + ord('a')))
        s = "".join(s)
        if s == T:
            return True

    return False


if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
