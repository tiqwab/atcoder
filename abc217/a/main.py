def main():
    S, T = input().split(' ')
    return S < T

if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
