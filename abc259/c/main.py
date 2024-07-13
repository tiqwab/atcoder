from typing import List, Tuple


def parse(s: str) -> List[Tuple[str, int]]:
    ans = []
    cnt = 1
    prev_char = s[0]

    for i in range(1, len(s)):
        if s[i] == prev_char:
            cnt += 1
        else:
            ans.append((prev_char, cnt))
            cnt = 1
            prev_char = s[i]

    ans.append((prev_char, cnt))
    return ans


def main() -> bool:
    S = input().strip()
    T = input().strip()
    s_parsed = parse(S)
    t_parsed = parse(T)

    if len(s_parsed) != len(t_parsed):
        return False

    for i in range(len(s_parsed)):
        s_elem = s_parsed[i]
        t_elem = t_parsed[i]
        if s_elem[0] != t_elem[0]:
            return False
        if not ((s_elem[1] == t_elem[1]) or (s_elem[1] > 1 and s_elem[1] < t_elem[1])):
            return False

    return True


if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
