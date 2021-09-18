def main() -> str:
    N = int(input())
    ans = []

    while N > 0:
        if N % 2 == 1:
            ans.append("A") 
            N = N - 1
        else:
            ans.append("B")
            N = N // 2

    ans.reverse()
    return "".join(ans)

if __name__ == '__main__':
    print(main())
