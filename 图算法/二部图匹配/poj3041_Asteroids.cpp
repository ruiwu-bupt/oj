// 模板题，不是很好理解
#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>
#include <climits>
#define N 502

using namespace std;

// 邻接矩阵
int graph[N][N];
// 每次增广记录是否已经访问过
bool checked[N];
// 记录二部图x、y的匹配关系
int x[N], y[N];
int n, k;

// 寻找以u为未匹配点开始的增广路径
bool search_path(int u) {
    for (int v = 0; v < N; v++) {
        if (graph[u][v] == 1 && !checked[v]) {
            checked[v] = true;
            if (y[v] == -1 || search_path(y[v])) {
                y[v] = u;
                x[u] = v;
                return true;
            }
        }
    }
    return false;
}
// 计数增广路数目，每次扩展一对匹配
int max_match() {
    int matches = 0;
    for (int i = 0; i < N; i++)
        x[i] = y[i] = -1;
    for (int i = 0; i < N; i++) {
        if (x[i] == -1) {
            memset(checked, false, sizeof(checked));
            if (search_path(i))
                matches++;
        }
    }
    return matches;
}
// 主函数，输入图的边和二部图的x，y顶点集合
int main() {
    memset(graph, 0, sizeof(graph));
    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 0; i < k; i++) {
            int r, c;
            scanf("%d%d", &r, &c);
            graph[r][c] = 1;
        }
        printf("%d\n", max_match());
    }
    return 0;
}
