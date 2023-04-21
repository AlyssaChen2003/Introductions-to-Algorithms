#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
int n, m, k, E, d, head[500], tot;
int len[105][105]; 
bool dy[25][105];
long long f[105];
struct E {
	int to, nxt, w;
}edge[1000];

void add(int u, int v, int w) {
	edge[++tot].to = v;
	edge[tot].nxt = head[u];
	edge[tot].w = w;
	head[u] = tot;
}
int spfa(int x, int y) {
	int dis[25]; 
	bool vis[25], inq[25];//在原基础上增加一个标记点的数组
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(inq, 0, sizeof(inq));
	for (int i = 1; i <= m; i++)
		for (int j = x; j <= y; j++)
			if (dy[i][j]) inq[i] = 1;
				dis[1] = 0, vis[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int u = q.front(); 
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].to, w = edge[i].w;
			if (inq[v]) 
				continue;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if (!vis[v]) {
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return dis[m];
}
int main()
{
	cin >> n >> m >> k >> E;
	for ( int i = 1; i <= E; i++) {
		 int x, y, h;
		 cin >> x >> y >> h;
		add(x, y, h), add(y, x, h);//加边
	}
	cin >> d;
	for (int i = 1; i <= d; i++) {
		 int p, a, b;
		 cin >> p >> a >> b;
		for (int j = a; j <= b; j++)
			dy[p][j] = 1;//dy[p][j]表示第p个点在第j天能否通过
	}
	for (int i = 1; i <= n; i++) {
		for ( int j = 1; j <= n; j++)
			len[i][j] = spfa(i, j);
	}
	for (int i = 1; i <= n; i++) {
		f[i] = (long long)len[1][i] * i;
		for (int j = 1; j <= i; j++)
			f[i] = min(f[i], f[j] + (long long)len[j + 1][i] * (i - j) + k);
	}//dp，注意将变量转化为long long
	printf("%lld", f[n]);
	return 0;
}