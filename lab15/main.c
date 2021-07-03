#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "graph.h"

int main(void){
    int ver = 0; //guarda os vertices
    int arest1 = -1;
    int arest2 = -1;
    int find = 0;
    table* p = NULL;
    char cmd[25];
    scanf(" %[^\n]s", cmd);
        if(strcmp(cmd, "Vertices:") == 0){
            scanf("%d", &ver);
            //printf("vertice = %d\n", ver);
            p = graph_creat(ver);
        }
    scanf(" %[^\n]s", cmd);
        if(strcmp(cmd, "Arestas:")== 0){
            while(arest1 != 0 && arest2 != 0){
                scanf("%d,%d", &arest1, &arest2);
                if(arest1 != 0 && arest2 != 0){
                    //printf("arestas = %d %d\n", arest1, arest2);
                    graph_insert(p, arest1, arest2);
                }
            }
        }
    //graph_print(ver, p);

    scanf(" %[^\n]s", cmd);
        if(strcmp(cmd, "Origem:")== 0){
            scanf("%d", &find);
            printf("Origem da busca: %d\n", find);
            printf("Vertices alcancados e distancias:\n");
            graph_BFS(p, ver, find);
            graph_free(p);
            return 0;
        }
    return 0;
}

