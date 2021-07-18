def main() -> bool:
    A, B = [int(x) for x in input().split(' ')]
    return A <= B and B <= 6 * A


if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
