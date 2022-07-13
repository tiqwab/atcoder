# requires only primes less than 200
primes = \
    [ \
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, \
    101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, \
    ]


# Return True if Aoki wins
def main() -> bool:
    A, B, C, D = [int(x) for x in input().split(' ')]
    for x in range(A, B + 1):
        ok = True
        for y in range(C, D + 1):
            if x + y in primes:
                ok = False
                break
        if ok:
            return False
    return True


if __name__ == '__main__':
    if main():
        print('Aoki')
    else:
        print('Takahashi')
