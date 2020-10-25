#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define lc u<<1
#define rc (u<<1)+1
#define m (l+r)>>1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MAX = 1e5 + 10;

struct node {
	int u, v, l, r;
}a[MAX];

int N, M, ans;
int tot, mp[MAX << 1];
int pre[MAX], rk[MAX];

vector<pii> t[MAX << 3];
vector<int> merged[MAX << 3];//记录节点i被合并的点

int pos(int x) { return lower_bound(mp + 1, mp + 1 + tot, x) - mp; }//返回离散化后的数值

void insert(int u, int l, int r, int ql, int qr, int from, int to) {//点路径插入对应点
    //insert(1, 1, tot + 1, pos(a[i].l), pos(a[i].r + 1), a[i].u, a[i].v);
	if (ql <= l && r <= qr) {
		t[u].emplace_back(from, to);
		return;
	}
	if (ql < m)insert(lc, l, m, ql, qr, from, to);
	if (qr > m)insert(rc, m+1, r, ql, qr, from, to);
}
void insert1(int u, int l, int r, int ql, int qr, int from, int to) {//点路径插入对应点
    //insert(1, 1, tot + 1, pos(a[i].l), pos(a[i].r + 1), a[i].u, a[i].v);
	if (ql <= l && r <= qr) {
		t[u].emplace_back(from, to);
		return;
	}
    //m=(l+r)//2;
    //lc=
	if (ql < m)insert(lc, l, m, ql, qr, from, to);
	if (qr > m)insert(rc, m, r, ql, qr, from, to);
}
int find(int x) { 
    //if(x==pre[x]) return x;
    //else return pre[x]=find(pre[x]);
    return x == pre[x] ? x : find(pre[x]); 
}

void merge(int u, int x, int y) {//按秩合并
	x = find(x);
	y = find(y);
	if (x == y)return;
	//if (rk[x] < rk[y])swap(x, y);
    if(x>y) swap(x,y);
	pre[y] = x;
	//if (rk[x] == rk[y])rk[x]++;
	merged[u].push_back(y);
}

void update(int u) {//全部合并 
	for (auto & i : t[u])
		merge(u, i.first, i.second);
}

void cancel(int u) {//还原 
	for (auto & i : merged[u])
		pre[i] = i;
}

void dfs(int u, int l, int r) {
	update(u);
	if (l == r - 1) {
		if (find(1) == find(N))//位于同一个集中
			ans += mp[r] - mp[l];//说明当前size能够连通
		cancel(u);//将并查集还原
		return;
	}
	dfs(lc, l, m);
	dfs(rc, m, r);
	cancel(u);//并查集还原
}

int main() {
	tot = ans = 0;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)pre[i] = i;
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d%d", &a[i].u, &a[i].v, &a[i].l, &a[i].r);
		mp[++tot] = a[i].l;
		mp[++tot] = a[i].r + 1;
	}
	sort(mp + 1, mp + 1 + tot);
	tot = unique(mp + 1, mp + 1 + tot) - mp - 1;
	for (int i = 1; i <= M; i++)
		insert(1, 1, tot + 1, pos(a[i].l), pos(a[i].r + 1), a[i].u, a[i].v);//将路径插入对应的节点
	dfs(1, 1, tot + 1);//dfs查询
	printf("%d\n", ans);
	return 0;
}