def main():
    N, K = [int(x) for x in input().split(' ')]
    xs = [int(x) for x in input().split(' ')]
    id_idx_val = list(map(lambda x: [x[0], x[1], x[2]], zip(xs, range(0, N), [0] * N)))
    id_idx_val.sort()

    for i in range(0, N):
        id_idx_val[i][2] = K // N;
        if i < K % N:
            id_idx_val[i][2] += 1

    id_idx_val.sort(key=lambda x: x[1])
    for i in range(0, N):
        print(id_idx_val[i][2])

if __name__ == '__main__':
    main()
