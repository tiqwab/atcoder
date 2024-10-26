def main() -> int:
    N = int(input())
    xs = [int(x) - 1 for x in input().split(' ')]

    ans = 0
    same_position_and_number = 0

    for i, x in enumerate(xs):
        if i == x:
            same_position_and_number += 1
        else:
            if xs[x] == i:
                ans += 1

    ans = ans // 2
    ans += same_position_and_number * (same_position_and_number - 1) // 2
    return ans


if __name__ == '__main__':
    print(main())
