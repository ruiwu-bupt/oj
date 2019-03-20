- 保存已访问节点
- 递归展开每个节点可以访问的下一个节点
```c++
void dfs(int v)
{
    list<int>::iterator it;
    visited[v] = true;
    printf("%5d", v);
    for (it = graph[v].begin(); it != graph[v].end(); ++it)
        if (!visited[*it])
            dfs(*it);
}
```
