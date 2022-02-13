def main():
    S = input()
    T = "oxx" * 100000
    return S in T


if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
