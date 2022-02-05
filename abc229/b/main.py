def main() -> bool:
    A, B = input().split(' ')
    A = list(reversed(A))
    B = list(reversed(B))

    for a, b in zip(A, B):
        if int(a) + int(b) >= 10:
            return False

    return True


if __name__ == '__main__':
    if main():
        print("Easy")
    else:
        print("Hard")
