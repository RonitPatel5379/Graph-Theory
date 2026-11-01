#include <stdio.h>

void main() {
    int n, m, i, j;
    int a[20][20];
    int match[20];
    int matched[20] = {0};
    int count = 0;

    printf("Enter number of vertices in Left set: ");
    scanf("%d", &n);

    printf("Enter number of vertices in Right set: ");
    scanf("%d", &m);

    printf("Enter adjacency matrix (%d x %d):\n", n, m);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (j = 0; j < m; j++) {
        match[j] = -1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] == 1 && matched[j] == 0) {
                match[j] = i;
                matched[j] = 1;
                count++;
                break;
            }
        }
    }

    printf("\nMatching set:\n");

    for (j = 0; j < m; j++) {
        if (match[j] != -1) {
            printf("(%d, %d) ", match[j] + 1, j + 1);
        }
    }

    printf("\n\nNumber of matching edges = %d\n", count);

    if (count == n && count == m) {
        printf("Type: Perfect Matching\n");
        printf("It is also a Maximum Matching.\n");
        printf("It is also a Maximal Matching.\n");
    }
    else if (count == n || count == m) {
        printf("Type: Maximum Matching\n");
        printf("It is also a Maximal Matching.\n");
        printf("It is NOT a Perfect Matching.\n");
    }
    else {
        printf("Type: Maximal Matching\n");
        printf("It is NOT a Perfect Matching.\n");
    }
}