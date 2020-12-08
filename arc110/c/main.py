# swap(ps[right-1], ps[right]), swap(ps[right-2], ps[right-1]), ... swap(ps[left], ps[left+1])
def f(left, right, ps, acc):
    for i in range(right - 1, left - 1, -1):
        ps[i], ps[i + 1] = ps[i + 1], ps[i]
        acc.append(i + 1)

def solve(n, ps, acc):
    for i in range(n):
        if ps[i] == i + 1:
            return False

    cur_number = 1
    prev_idx = 0
    cur_idx = 0
    while cur_idx < n:
        if ps[cur_idx] == cur_number:
            f(prev_idx, cur_idx, ps, acc)
            prev_idx = cur_idx
            cur_number = cur_idx + 1
        cur_idx += 1

    for i in range(n):
        if ps[i] != i + 1:
            return False

    return True

if __name__ == '__main__':
    n = int(input())
    ps = [int(p) for p in input().split()]
    acc = []
    if not solve(n, ps, acc):
        print(-1)
    else:
        for line in acc:
            print(line)
