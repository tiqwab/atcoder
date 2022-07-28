def main() -> bool:
    a, b = [int(x) for x in input().split(' ')]
    if b - a == 1:
        return True
    elif a == 1 and b == 10:
        return True
    else:
        return False


if __name__ == '__main__':
    if main():
        print("Yes")
    else:
        print("No")
