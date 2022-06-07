def main() -> int:
    x = int(input())
    return -1 * (1 << 31) <= x and x < (1 << 31)

if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
