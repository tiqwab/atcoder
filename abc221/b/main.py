import copy


def main() -> bool:
    S = list(input().strip())
    T = list(input().strip())

    if S == T:
        return True

    for i in range(0, len(S) - 1):
        s = copy.deepcopy(S)
        tmp = s[i]
        s[i] = s[i + 1]
        s[i + 1] = tmp
        if s == T:
            return True

    return False


if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
