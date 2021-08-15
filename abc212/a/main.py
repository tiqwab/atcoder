def main():
    A, B = [int(x) for x in input().split(' ')]
    if A > 0 and B > 0:
        print('Alloy')
    elif A == 0:
        print('Silver')
    else:
        print('Gold')

if __name__ == '__main__':
    main()
