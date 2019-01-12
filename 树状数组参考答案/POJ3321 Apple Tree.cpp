#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 1e5 + 1;
int a[N + 1], n;
int cnt;
int lowbit(int x)
{
    return x&(-x);
}
void update(int x, int v) 
{
    while(x <= n) {
        a[x] += v;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int sum = 0;
    while(x){
        sum += a[x];
        x -= lowbit(x);
    }
    return sum;
}
vector< vector<int> > g(N);
int start[N], end[N], sign[N];
void dfs(int u)
{
    start[u] = cnt;
    for(int i = 0; i < g[u].size(); i++) {
        cnt++;
        dfs(g[u][i]);
    }
    end[u] = cnt;
}
int main()
{
    while(scanf("%d", &n)!=EOF){
        g.clear();
        g.resize(N +1);
        for(int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
        }
        cnt = 1;
        dfs(1);
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; i++) {
            sign[i] = 1;//标记有没有苹果 
            update(i, 1);
        }
//        for(int i=1; i<=n; i++){
//        	cout << " " << start[i];
//		}
//		cout << endl;
//		for(int i=1; i<=n; i++){
//        	cout << " " << end[i];
//		}
//		cout << endl;
        int m, x;
        char cmd[8];
        scanf("%d", &m);
        for(int i = 1; i <=m; i++) {
            scanf("%s%d", cmd, &x);
            if(cmd[0] == 'Q')
                printf("%d\n", sum(end[x]) - sum(start[x] - 1));
            else {
                update(start[x], sign[x] ? -1 : 1);
                sign[x] = 1 - sign[x];
            }
        }
    }
    return 0;
}

//5
//1 2
//1 3
//3 4
//3 5
