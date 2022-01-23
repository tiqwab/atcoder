def main() -> bool:
    S, T, X = [int(x) for x in input().split(' ')]

    cur = S
    while cur != T:
        if cur == X:
            return True
        cur = (cur + 1) % 24

    return False


if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
