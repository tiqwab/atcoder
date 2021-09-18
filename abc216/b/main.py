def main() -> bool:
    N = int(input())
    people = []

    for i in range(0, N):
        s, t = [x for x in input().split(' ')]
        people.append((s, t))

    for i in range(0, N):
        for j in range(i + 1, N):
            if people[i] == people[j]:
                return True

    return False

if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
