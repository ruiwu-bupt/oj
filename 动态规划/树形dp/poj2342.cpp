#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <climits>

using namespace std;

struct nd {
	int parent;
	set<int> children;
	nd(int a=0) : parent(a){}
};
int traverse(vector<nd>& relation, vector<int>& dp, vector<int>& conviv, int cur) {
	int choose = conviv[cur], no_choose = 0;
	set<int> grandchildren;
	for (set<int>::iterator i = relation[cur].children.begin(); i != relation[cur].children.end(); ++i){
		for (set<int>::iterator j = relation[*i].children.begin(); j != relation[*i].children.end(); ++j) {
            if (dp[*j] == INT_MAX)
                dp[*j] = traverse(relation, dp, conviv, *j);
            choose += dp[*j];
		}
	}
    for (set<int>::iterator i = relation[cur].children.begin(); i != relation[cur].children.end(); ++i) {
        if (dp[*i] == INT_MAX)
            dp[*i] = traverse(relation, dp, conviv, *i);
        no_choose += dp[*i];
    }
    dp[cur] = max(choose, no_choose);
    return dp[cur];
}
int main() {
	int N;
	scanf("%d", &N);
	vector<int> conviv(N+1, 0);
	vector<nd> relation(N+1, nd());
	vector<int> dp(N+1, INT_MAX);
	for (int i = 1; i <= N; i++)
		scanf("%d", &conviv[i]);
	while(1) {
		int L, K;
		scanf("%d %d", &L, &K);
		if (!L && !K)
			break;
		relation[L].parent = K;
		relation[K].children.insert(L);
	}
	int p;
	for (int i = 1; i <= N; i++) {
		if (relation[i].parent == 0) {
			p = i;
			break;
		}
	}
    cout << traverse(relation, dp, conviv, p) << endl;
}
