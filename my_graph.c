#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h" 

#define INF 99999

int main() {
    int graph[10][10] = {0};  // Initialize graph with 0s
    char choice;

    do {
        scanf(" %c", &choice);

        switch (choice) {
            case 'A': {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        scanf("%d", &graph[i][j]);
                    }
                }
                break;
            }

            case 'B': {
                int start, end;
                scanf("%d %d", &start, &end);

                if (start >= 0 && start < 10 && end >= 0 && end < 10) {
                    bool ans = isPath(graph, start, end);
                    printf("%s\n", ans ? "True" : "False");
                }
                break;
            }

            case 'C': {
                int start, end;
                scanf("%d %d", &start, &end);

                if (start >= 0 && start < 10 && end >= 0 && end < 10) {
                    int ans = shortestPath(graph, start, end);
                    if (ans == 0||ans==INF) {
                        printf("-1\n");
                    } else {
                        printf("%d\n", ans);
                    }
                }
                break;
            }

            case 'D': {
                break;
            }

            default: {
                break;
            }
        }
    } while (choice != 'D');

    return 0;
}
