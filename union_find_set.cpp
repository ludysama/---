#include <stdio.h>
#include <string.h>

const int MAX_N = 200;

int n, m;
int edge[200][2];
int parent[MAX_N];

int findFather(int x)
{
    if (parent[x] < 0)
        return x;
    return findFather(parent[x]);
}

void union_of_member(int x, int y)
{
    int father_of_x = findFather(x);
    int father_of_y = findFather(y);
    //不是同一个祖先，就执行合并，否则跳过此步骤
    if (father_of_x != father_of_y)
    {
        //parent数组的值若为负数，代表其族群中有多少个子嗣，该负数越小，说明子嗣越多，族群越大
        if (parent[father_of_x] <= parent[father_of_y])
        {
            // x的祖先子嗣更多，将y的族群作为子嗣并入x的族群
            parent[father_of_x] += parent[father_of_y];
            parent[father_of_y] = father_of_x;
        }
        else
        {
            // y的族群规模更大，将x的族群并入y的族群
            parent[father_of_y] += parent[father_of_x];
            parent[father_of_x] = father_of_y;
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
    for (int i = 0; i < m; i++)
        union_of_member(edge[i][0], edge[i][1]);

    show_result();
    printf("%c",'\n');
    union_of_member(2,7);
    show_result();

}