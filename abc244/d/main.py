def count_hat(ss):
    r = 0
    g = 0
    b = 0
    for s in ss:
        if s == 'R':
            r += 1
        elif s == 'G':
            g += 1
        else:
            b += 1
    return r, g, b


def main() -> bool:
    S = "".join(input().split(' '))
    T = "".join(input().split(' '))

    sr, sg, sb = count_hat(S)
    tr, tg, tb = count_hat(T)
 
    if sr != tr or sg != tg or sb != tb:
        return False
 
    if sr == 0 or sg == 0 or sb == 0:
        return True

    match = 0
    for i in range(3):
        if S[i] == T[i]:
            match += 1
    return match != 1

if __name__ == '__main__':
    if main():
        print("Yes")
    else:
        print("No")
