import typing

def main() -> typing.List[int]:
    N = int(input().strip())
    ps = [int(x) for x in input().split(' ')]
    ans = [-1] * N
    for i, p in enumerate(ps):
        ans[p - 1] = i + 1
    return ans

if __name__ == '__main__':
    ans = main()
    print(' '.join(map(lambda x: str(x), ans)))
