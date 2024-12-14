def main() -> bool:
    xs = [int(x) for x in input().split(' ')]

    counter = dict()
    for x in xs:
        if counter.get(x):
            counter[x] += 1
        else:
            counter[x] = 1

    if len(counter) != 2:
        return False
    if counter[xs[0]] != 2 and counter[xs[0]] != 3:
        return False
    return True


if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
