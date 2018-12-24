#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>
#include <climits>

#define N 502

using namespace std;
int graph[N][N];
int n, k;
bool checked[N];
int x[N], y[N];

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
