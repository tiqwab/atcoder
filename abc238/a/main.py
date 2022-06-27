def main() -> bool:
    n = int(input())
    return n == 1 or n > 4


if __name__ == '__main__':
    if main():
        print("Yes")
    else:
        print("No")
