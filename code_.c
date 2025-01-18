#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1501

typedef struct {
    char key[20];
    int row;
    int col;
} hash_;

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        char arr[n][m][20];  // 2D array of strings (each with max 19 chars + null terminator)
        
        // Input the grid of strings
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%s", arr[i][j]);
            }
        }

        hash_ hashmap[MAX_SIZE];
        int hash_count = 0;

        // Build the hashmap
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                strcpy(hashmap[hash_count].key, arr[i][j]);  // Correctly copy the string into hashmap
                hashmap[hash_count].row = i;
                hashmap[hash_count].col = j;
                hash_count++;
            }
        }

        int q;
        scanf("%d", &q);
        
        // Process each query
        while (q--) {
            int row_ = -1;
            char a[20], b[20];
            scanf("%s %s", a, b);
            
            // Find the row where string `a` is located
            for (int i = 0; i < hash_count; i++) {
                if (strcmp(hashmap[i].key, a) == 0) {  // Compare entire strings
                    row_ = hashmap[i].row;
                    break;  // Exit once the row is found
                }
            }

            // If no matching row was found, print -1
            if (row_ == -1) {
                printf("-1\n");
                continue;
            }

            // Now search for string `b` in the row `row_`
            int found = 0;
            for (int j = 0; j < m; j++) {
                if (strcmp(b, arr[row_][j]) == 0) {  // Compare entire strings
                    printf("%d ", row_);
                    found = 1;
                    break;  // Exit once the string `b` is found
                }
            }

            if (!found) {
                printf("-1 ");
            }
        }
        printf("\n");
    }

    return 0;
}
