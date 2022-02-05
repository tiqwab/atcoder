def main() -> bool:
    cells = input() + input()
    return cells not in ["#...", ".#..", "..#.", "...#", "#..#", ".##."]


if __name__ == '__main__':
    if main():
        print("Yes")
    else:
        print("No")
