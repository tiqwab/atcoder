def main() -> bool:
    """
    Return True if Takahashi loses.
    """
    N = int(input())
    S = input()
    for idx, char in enumerate(S):
        if char == '1':
            return idx % 2 == 0

if __name__ == '__main__':
    if main():
        print('Takahashi')
    else:
        print('Aoki')
