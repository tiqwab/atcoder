def main() -> bool:
    ss = input()
    ss_len = len(ss)
    
    left_cnt = 0
    idx = 0
    while idx < ss_len and ss[idx] == 'a':
        left_cnt += 1
        idx += 1

    right_cnt = 0
    idx = ss_len - 1
    while idx >= 0 and ss[idx] == 'a':
        right_cnt += 1
        idx -= 1

    # print(left_cnt, right_cnt)

    if left_cnt > right_cnt:
        return False

    ss = list(reversed(list(ss)))
    ss.extend(['a'] * (right_cnt - left_cnt))

    # print(ss)

    return is_palindrome(ss)


def is_palindrome(ss) -> bool:
    l = len(ss)
    for i in range(l):
        if ss[i] != ss[l - 1 - i]:
            return False
    return True



if __name__ == '__main__':
    if main():
        print('Yes')
    else:
        print('No')
