def is_palindrome(s: str):
    t = ''.join(reversed(s))
    return s == t


def main(S: str):
    for i in range(0, 10):
        T = '0' * i + S
        if is_palindrome(T):
            print('Yes')
            return
    print('No')
    return


if __name__ == '__main__':
    main(input())
