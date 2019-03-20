- 保存已访问节点集合
- 用队列模拟bfs过程，每次从队头出队一个元素，入队这个元素可以访问到且不在已访问节点集合中的元素
```c++
void bfs(int v)
{
    list<int>::iterator it;
    printf("%5d", v);
    visited[v] = true;
    queue<int> t;
    t.push(v);
    while (!t.empty())
    {
        v = t.front();
        t.pop();
        for (it = graph[v].begin(); it != graph[v].end(); ++it)
            if (!visited[*it])
            {
                printf("%5d", *it);
                t.push(*it);
                visited[*it] = true;
           }
    }
}
```
