def main():
    N = int(input())
    x = N * 108 // 100
    if x < 206:
        print('Yay!')
    elif x == 206:
        print('so-so')
    else:
        print(':(')

if __name__ == '__main__':
    main()
