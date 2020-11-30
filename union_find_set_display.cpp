#include <stdio.h>
#include <string.h>

const int MAX_N = 200;

int n, m;
int edge[200][2];
int parent[MAX_N];

int findFather(int x){
    if (parent[x]<0) return x;
    return findFather(parent[x]);
}

void union_of_member(int x, int y){
    int father_x = findFather(x);
    int father_y = findFather(y);
    if (father_x != father_y){
        if (parent[father_x] <= parent[father_y]){
            parent[father_x] += parent[father_y];
            parent[father_y] = father_x;
        }
        else{
            parent[father_y] += parent[father_x];
            parent[father_x] = father_y;
        }
    }
    return;
}

void show_result()
{
    printf("%c", '\n');
    for (int i = 0; i < n; i++)
        printf("%d\t", i);
    printf("%c", '\n');
    for (int i = 0; i < n; i++)
        printf("%d\t", parent[i]);
    return;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &edge[i][0], &edge[i][1]);
    }
    // 初始化并查集
    memset(parent, -1, sizeof(parent));
    // 为每个关系进行合并
    for (int i=0;i<m;i++) 
        union_of_member(edge[i][0],edge[i][1]);

    show_result();
    // printf("%c",'\n');
    union_of_member(2,4);
    show_result();

    printf("\n%d\n",findFather(4));

}