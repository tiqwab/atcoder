def main() -> bool:
    ns = [int(x) for x in input().split(' ')]
    b = ns[1]
    ns.sort()
    return b == ns[1]


if __name__ == '__main__':
    if main():
        print("Yes")
    else:
        print("No")
