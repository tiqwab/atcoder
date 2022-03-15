import itertools

def main() -> bool:
    N, M = [int(x) for x in input().split(' ')]

    edges_t = []
    for i in range(M):
        a, b = [int(x) for x in input().split(' ')]
        a -= 1
        b -= 1
        edges_t.append((a, b))
        edges_t.append((b, a))

    edges_a = []
    for i in range(M):
        a, b = [int(x) for x in input().split(' ')]
        a -= 1
        b -= 1
        edges_a.append((a, b))
        edges_a.append((b, a))

    for perm in itertools.permutations(range(N), N):
        rule = dict()
        for i, j in enumerate(perm):
            rule[i] = j
        converted_edges = []
        for edge in edges_a:
            converted_edges.append((rule[edge[0]], rule[edge[1]]))

        if set(edges_t) == set(converted_edges):
            return True

    return False


if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
