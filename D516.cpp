#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define II pair < int , int > 
#define pb push_back
#define mset(a , b) memset(a , b , sizeof a);
const int inf = 1e15;
const int N = 1e5 + 5;
int n , q , l , Root , U[N] , D[N] , Dis[N] , f[N] , par[N] , vs[N];
vector < II > ad[N] , vc;
void Input()
{
    cin >> n;
    for(int i = 1 ; i < n ; ++i)
    {
    	int u , v , w;
    	cin >> u >> v >> w;
    	ad[u].pb({v , w});
    	ad[v].pb({u , w});
    }
    cin >> q;
}
void DFS_1(int u , int par)
{
	for(auto i : ad[u])
	{
		int y = i.fi , len = i.se;
		if(y == par) continue;
		DFS_1(y , u);
		D[u] = max(D[u] , D[y] + len);
	}
}
void Down()
{
	DFS_1(Root , 0);
}
void DFS_2(int u , int par)
{
	int cur = 0;
	f[ad[u].size()] = 0;
	for(int i = ad[u].size() - 1 ; i >= 0 ; --i)
	{
		int y = ad[u][i].fi , len = ad[u][i].se;
		if(y == par) f[i] = f[i + 1];
		else f[i] = max(f[i + 1] , D[y] + len);
	}
	for(int i = 0 ; i < ad[u].size() ; ++i)
	{
		int y = ad[u][i].fi , len = ad[u][i].se;
		if(y == par) continue;
		U[y] = max({U[u] , f[i + 1] , cur}) + len;
		cur = max(cur , D[y] + len);
	}
	for(int i = 0 ; i < ad[u].size() ; ++i)
	{
		int y = ad[u][i].fi , len = ad[u][i].se;
		if(y == par) continue;
		DFS_2(y , u);
	}
}
void Up()
{
	U[Root] = 0;
	DFS_2(Root , 0);
}
void Prepare()
{
	Root = 1;
	for(int i = 1 ; i <= n ; ++i)
	{
		if(ad[i].size() == 1) D[i] = 0;
		else Root = i;
	}
	Down();
	Up();
	for(int i = 1 ; i <= n ; ++i)
	{
		Dis[i] = max(D[i] , U[i]);
		vc.pb({Dis[i] , i});
	}
	sort(vc.rbegin(), vc.rend());
}
int Roott(int u)
{
	if(par[u] < 0) return u;
	par[u] = Roott(par[u]);
	return par[u];
}
void Remove(int u)
{
	vs[u] = 0;
	par[Roott(u)]++;
}
void Merge(int u , int v)
{
	if((u = Roott(u)) == (v = Roott(v))) return;
	if(par[u] > par[v]) swap(u , v);
	par[u] += par[v];
	par[v] = u;
}
void Solve()
{
    int cur = 0 , Res = 0;
    mset(par , -1);
    mset(vs , 0);
    for(int i = 0 ; i < vc.size() ; ++i)
    {
    	int u = vc[i].se , len = vc[i].fi;
    	vs[u] = 1;
    	while(vc[cur].fi - len > l) 
    	{
    		Remove(vc[cur].se);
   			cur++;
    	}
    	for(auto j : ad[u])
    	{
    		int y = j.fi;
    		if(vs[y]) Merge(y , u);
    	}
    	Res = max(Res , -par[Roott(u)]);
    }
    cout << Res << '\n';
}
#undef int
int main()
{
    if(fopen("trash.inp" , "r"))
        freopen("trash.inp" , "r" , stdin) , freopen("trash.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Prepare();
    while(q--)
    {
    	cin >> l;
    	Solve();
    }
}
