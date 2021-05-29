def main():
    S = input()
    slen = len(S)

    ans = []

    for i in range(slen - 1, -1, -1):
        c = S[i]
        if c == '0':
            ans.append('0')
        elif c == '1':
            ans.append('1')
        elif c == '6':
            ans.append('9')
        elif c == '8':
            ans.append('8')
        elif c == '9':
            ans.append('6')
        else:
            raise Exception(f"unknown character: {c}")

    return ans

if __name__ == '__main__':
    print(''.join(main()))
