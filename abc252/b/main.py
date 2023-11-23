def main() -> bool:
    N, K = [int(x) for x in input().split(' ')]
    goodness = [int(x) for x in input().split(' ')]
    dislike = [int(x) - 1 for x in input().split(' ')]

    best_score = max(goodness)

    for i, g in enumerate(goodness):
        if g != best_score:
            continue
        if i in dislike:
            return True

    return False


if __name__ == '__main__':
    if main():
        print("Yes")
    else:
        print("No")
