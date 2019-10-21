#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * ref. https://ja.wikipedia.org/wiki/%E3%82%AF%E3%83%8C%E3%83%BC%E3%82%B9%E2%80%93%E3%83%A2%E3%83%AA%E3%82%B9%E2%80%93%E3%83%97%E3%83%A9%E3%83%83%E3%83%88%E6%B3%95
 */

void kmp_table(char *str, int *table, int size) {
    int i = 2;
    int j = 0;

    table[0] = -1;
    table[1] = 0;

    while (i < size) {
        if (str[i-1] == str[j]) {
            table[i] = j+1;
            i++;
            j++;
        } else if (j > 0) {
            j = table[j];
        } else {
            table[i] = 0;
            i++;
        }
    }
}

/*
 * Return index if substring is found, otherwise -1.
 */
int kmp_search(char *text, int text_size, char *word, int word_size, int *table) {
    int m = 0;
    int i = 0;

    while (m + i < text_size) {
        if (word[i] == text[m + i]) {
            i++;
            if (i == word_size) {
                return m;
            }
        } else {
            m = m + i - table[i];
            if (i > 0) {
                i = table[i];
            }
        }
    }

    return -1;
}

#define BUF_SIZ (1024 * 1024)

int main(void) {
    char t[1000002];
    int nt;
    char p[10002];
    int np;
    int table[10000];
    char buf[BUF_SIZ];

    fgets(t, 1000002, stdin);
    nt = strlen(t);
    if (t[nt-1] == '\n') {
        t[nt-1] = '\0';
        nt--;
    }

    fgets(p, 10002, stdin);
    np = strlen(p);
    if (p[np-1] == '\n') {
        p[np-1] = '\0';
        np--;
    }

    kmp_table(p, table, np);
    // printf("table:");
    // for (int i = 0; i < np; i++) {
    //     printf("%d\n", table[i]);
    // }
    // printf("\n");

    setvbuf(stdout, buf, _IOFBF, BUF_SIZ);

    char *tt = t;
    int remain = nt;
    int index;
    while ((index = kmp_search(tt, remain, p, np, table)) >= 0) {
        printf("%d\n", (nt - remain + index));
        tt += index + 1;
        remain = remain - index - 1;
    }

    fflush(stdout);

    return 0;
}
