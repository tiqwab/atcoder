INF = 1000 * 1000 * 1000 + 1


class Node:
    def __init__(self, value, prev_node, next_node):
        self.value = value

        self.prev_node = prev_node
        if prev_node is not None:
            prev_node.next_node = self

        self.next_node = next_node
        if next_node is not None:
            next_node.prev_node = self


def main():
    N = int(input())
    S = input()

    start = Node(-INF, None, None)
    end = Node(INF, None, None)

    node_memo = [None] * (N + 1)
    node_memo[0] = Node(0, start, end)

    for i in range(N):
        value = i + 1
        direction = S[i]
        base_node = node_memo[i]
        if S[i] == 'L':
            node_memo[i + 1] = Node(value, base_node.prev_node, base_node)
        else:
            node_memo[i + 1] = Node(value, base_node, base_node.next_node)

    cur_node = start.next_node
    print(cur_node.value, end='')
    cur_node = cur_node.next_node
    for i in range(N):
        print(' ' + str(cur_node.value), end='')
        cur_node = cur_node.next_node
    print()


if __name__ == '__main__':
    main()
