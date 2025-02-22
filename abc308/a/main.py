def main() -> bool:
    ss = [int(x) for x in input().split(' ')]

    for i in range(8):
        if ss[i] < 100 or ss[i] > 675:
            return False
        if ss[i] % 25 != 0:
            return False
        if i < 7 and ss[i] > ss[i + 1]:
            return False

    return True


if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
