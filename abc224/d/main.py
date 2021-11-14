import collections


def main() -> int:
    M = int(input())

    edges = [[] for x in range(0, 9)]
    for i in range(0, M):
        u, v = [int(x) for x in input().split(" ")]
        u -= 1
        v -= 1
        edges[u].append(v)
        edges[v].append(u)

    goal = [0] * 9
    for i, x in enumerate([int(x) for x in input().split(" ")]):
        goal[x - 1] = i + 1

    que = collections.deque()
    que.append(((1, 2, 3, 4, 5, 6, 7, 8, 0), 0))

    m = {}
    m[(1, 2, 3, 4, 5, 6, 7, 8, 0)] = 0

    while len(que) > 0:
        elem, cnt = que.popleft()
        if m.get(elem) is not None and m[elem] < cnt:
            continue

        # print(elem)

        li = list(elem)
        idx_empty = li.index(0)

        for next_v in edges[idx_empty]:
            next_list = list(elem)
            tmp = elem[idx_empty]
            next_list[idx_empty] = elem[next_v]
            next_list[next_v] = tmp
            next_elem = tuple(next_list)
            if m.get(next_elem) is None:
                m[next_elem] = cnt + 1
                que.append((next_elem, cnt + 1))

    return m.get(tuple(goal), -1)


if __name__ == '__main__':
    print(main())
