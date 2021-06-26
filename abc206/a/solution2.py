def main():
    N = int(input())

    if N * 108 < 20600:
        print('Yay!')
    elif N * 108 >= 20700:
        print(':(')
    else:
        print('so-so')

if __name__ == '__main__':
    main()
