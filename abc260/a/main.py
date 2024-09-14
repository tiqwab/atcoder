from typing import Optional

def main() -> Optional[str]:
    s = input().strip()
    chars = dict()
    for c in s:
        if c in chars:
            chars[c] += 1
        else:
            chars[c] = 1
    for k, v in chars.items():
        if v == 1:
            return k
    return None


if __name__ == '__main__':
    x = main()
    if x is None:
        print("-1")
    else:
        print(x)
