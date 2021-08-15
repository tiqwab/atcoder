def check1(line: str) -> bool:
    c = line[0]
    for i in range(1, 4):
        if c != line[i]:
            return True
    return False

def check2(line: str) -> bool:
    for i in range(0, 3):
        j = i + 1
        a = int(line[i])
        b = int(line[j])
        if b != ((a + 1) % 10):
            return True
    return False

def main() -> bool:
    line = input().strip()

    if not check1(line):
        return False

    if not check2(line):
        return False

    return True

if __name__ == '__main__':
    if main():
        print('Strong')
    else:
        print('Weak')
