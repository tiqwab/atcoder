def main():
    N = int(input())
    xs = [int(x) for x in input().split(' ')]
    xs.sort()

    ok = True
    for i in range(0, N):
        if xs[i] != i + 1:
            ok = False
            break
    return ok

if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
