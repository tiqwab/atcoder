import collections


def main():
    Q = int(input())

    deque = collections.deque()

    for _ in range(Q):
        cols = [int(x) for x in input().strip().split(' ')]
        if cols[0] == 1:
            x = cols[1]
            c = cols[2]
            deque.append((x, c))
        elif cols[0] == 2:
            c = cols[1]
            ans = 0
            while c > 0:
                item_x, item_c = deque.popleft()
                if c >= item_c:
                    ans += item_x * item_c
                    c -= item_c
                else:
                    ans += item_x * c
                    deque.appendleft((item_x, item_c - c))
                    c = 0
            print(ans)
        else:
            raise Exception("unexpected query")


if __name__ == '__main__':
    main()
