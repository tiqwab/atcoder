def main() -> bool:
    N, M = [int(x) for x in input().split(' ')]
    bss = [[int(x) - 1 for x in input().split(' ')] for _ in range(N)]

    start_y = bss[0][0] // 7
    start_x = bss[0][0] % 7

    for diff_y, bs in enumerate(bss):
        for diff_x, b in enumerate(bs):
            expected_y = b // 7
            expected_x = b % 7

            # print(start_y, start_x, b, diff_y, diff_x, expected_y, expected_x)

            if (start_y + diff_y != expected_y) or \
                    (start_x + diff_x != expected_x):
                return False

    return True


if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
