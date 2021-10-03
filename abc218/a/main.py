def main():
    N = int(input())
    S = input()
    return S[N - 1] == 'o'

if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
