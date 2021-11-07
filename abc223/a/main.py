def main() -> bool:
    X = int(input())
    if X == 0:
        return False
    return X % 100 == 0


if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
