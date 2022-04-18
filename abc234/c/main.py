def main():
    K = int(input())
    bits = []
    while K > 0:
        if K % 2 == 1:
            bits.append('2')
        else:
            bits.append('0')
        K = K // 2
    bits = list(reversed(bits))
    print(''.join(bits))


if __name__ == '__main__':
    main()
