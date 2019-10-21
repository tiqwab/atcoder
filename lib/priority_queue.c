#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * ref.http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
 */

#define swap(typ, x, y) \
    do { \
        typ tmp; \
        tmp = x; \
        x = y; \
        y = tmp; \
    } while (0)

void max_heapify(int *arr, int i, int size) {
    int l, r, largest;

    l = (i+1) * 2 - 1;
    r = (i+1) * 2;

    if (l <= (size - 1) && arr[l] > arr[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r <= (size - 1) && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(int, arr[i], arr[largest]);
        max_heapify(arr, largest, size);
    }
}

void build_max_heap(int *arr, int size) {
    for (int i = (size / 2); i >= 0; i--) {
        max_heapify(arr, i, size);
    }
}

void insert_priority_queue(int *arr, int elem, int *size) {
    int index;
    arr[*size] = elem;
    (*size)++;

    index = *size - 1;
    while (arr[index] > arr[(index-1) / 2]) {
        swap(int, arr[index], arr[(index-1) / 2]);
        index = (index-1) / 2;
    }
}

int extract_priority_queue(int *arr, int *size) {
    int max_val = arr[0];
    swap(int, arr[0], arr[*size-1]);
    (*size)--;
    max_heapify(arr, 0, *size);
    return max_val;
}





int main(void) {
    int arr[2000000];
    int size = 0;
    char command[8];

    for (;;) {
        fgets(command, 7, stdin);
        if (strncmp(command, "end", 3) == 0) {
            break;
        } else if (strncmp(command, "insert", 7) == 0) {
            int val;
            scanf("%d", &val);
            insert_priority_queue(arr, val, &size);
            fgets(command, 8, stdin); // to consume newline
        } else if (strncmp(command, "extrac", 7) == 0) {
            int max_val = extract_priority_queue(arr, &size);
            printf("%d\n", max_val);
            fgets(command, 8, stdin); // to consume newline
        } else {
            fprintf(stderr, "illegal command: %s\n", command);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
