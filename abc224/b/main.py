def main() -> bool:
    H, W = [int(x) for x in input().split(" ")]

    table = []
    for h in range(0, H):
        table.append([int(x) for x in input().split(" ")])

    for i1 in range(0, H):
        for j1 in range(0, W):
            for i2 in range(i1 + 1, H):
                for j2 in range(j1 + 1, W):
                    a = table[i1][j1]
                    b = table[i2][j2]
                    c = table[i2][j1]
                    d = table[i1][j2]
                    if a + b > c + d:
                        return False

    return True


if __name__ == '__main__':
    if main():
        print("Yes")
    else:
        print("No")
