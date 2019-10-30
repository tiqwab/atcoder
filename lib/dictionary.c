#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * ref. http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_C
 */

#define TABLE_SIZE 10000

typedef struct dictionary_entry {
    char *val;
    struct dictionary_entry *next;
} DictionaryEntry;

typedef DictionaryEntry *Dictionary[TABLE_SIZE];

// A = 0, C = 1, G = 2, T = 3
// We should change mappings to differentiate empry and A (both are 0 in the above mapping).

static int convert_char(char c) {
    if (c == 'A') {
        return 0;
    } else if (c == 'C') {
        return 1;
    } else if (c == 'G') {
        return 2;
    } else if (c == 'T') {
        return 3;
    } else {
        return -1;
    }
}

static int hash(char *str, int len) {
    int res = 0;
    for (int i = 0; i < len; i++) {
        res = res * 4 + convert_char(str[i]);
    }
    return res;
}

void insert(Dictionary dict, char *str, int len) {
    int h = hash(str, len);
    int ind = h % TABLE_SIZE;

    DictionaryEntry *entry = (DictionaryEntry *) malloc(sizeof (DictionaryEntry));
    entry->val = str;
    entry->next = dict[ind];
    dict[ind] = entry;
}

bool find(Dictionary dict, char *str, int len) {
    int h = hash(str, len);
    int ind = h % TABLE_SIZE;

    for (DictionaryEntry *entry = dict[ind]; entry != NULL; entry = entry->next) {
        if (strcmp(entry->val, str) == 0) {
            return true;
        }
    }

    return false;
}



#define MAX_N 1000000
#define MAX_STR_LEN 12

Dictionary dict;
char strings[MAX_N][MAX_STR_LEN + 2];

int main(void) {
    int n, str_len, strings_ind = 0;
    char buf[8];

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        fgets(buf, 6, stdin);
        if (buf[0] == 'i') {
            // insert
            fgets(buf, 3, stdin);
            fgets(strings[strings_ind], MAX_STR_LEN + 2, stdin);
            str_len = strlen(strings[strings_ind]);
            strings[strings_ind][str_len - 1] = '\0';
            str_len--;

            insert(dict, strings[strings_ind], str_len); 
            strings_ind++;
        } else if (buf[0] == 'f') {
            // find
            fgets(strings[strings_ind], MAX_STR_LEN + 2, stdin);
            str_len = strlen(strings[strings_ind]);
            strings[strings_ind][str_len - 1] = '\0';
            str_len--;

            if (find(dict, strings[strings_ind], str_len)) {
                fprintf(stdout, "yes\n");
            } else {
                fprintf(stdout, "no\n");
            }
        } else {
            fprintf(stderr, "invalid command\n");
            return 1;
        }
    }

    return 0;
}
