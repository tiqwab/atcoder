def main() -> bool:
    N, K = [int(x) for x in input().split(' ')]
    xs = [int(x) for x in input().split(' ')]
    sorted_xs = sorted(xs)

    for k in range(K):
        nums = []
        expected_nums = []
        pos = k
        while pos < N:
            nums.append(xs[pos])
            expected_nums.append(sorted_xs[pos])
            pos += K
        # print(nums)
        # print(expected_nums)
        nums.sort()
        if nums != expected_nums:
            return False

    return True


if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
