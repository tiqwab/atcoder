def main() -> bool:
    N = int(input())
    edges = [[] for x in range(N)]

    for i in range(N - 1):
        a, b = [int(x) for x in input().split(' ')]
        a -= 1
        b -= 1
        edges[a].append(b)
        edges[b].append(a)

    for i in range(N):
        if len(edges[i]) == N - 1:
            return True
    return False


if __name__ == '__main__':
    if main():
        print("Yes")
    else:
        print("No")
