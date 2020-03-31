#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define II pair < int , int > 
#define pb push_back
#define mset(a , b) memset(a , b , sizeof a);
#define Hmax priority_queue < int > 
#define Hmin priority_queue < int , vector < int > , greater < int > >
#define IImax priority_queue < II >  
#define IImin priority_queue < II , vector < II > , greater < II > >
#define FOR(i , a , b) for(int i = a ; i <= b ; ++i)
#define FOD(i , a , b) for(int i = a ; i >= b ; --i)
const int inf = 1e16;
const int N = 1e5 + 5;
int n , m , dis[N] , par[N];
IImin qu;
vector < II > ad[N];
void Input()
{
    cin >> n >> m;
    mset(dis , 0x3f);
    mset(par , -1);
    for(int i = 1 ; i <= n ; ++i) 
    {
    	int col;
    	cin >> col;
    	if(col)
    	{
    		dis[i] = 0;
    		qu.push({0 , i});
    		par[i] = i;
    	}
    }
    for(int i = 1 ; i <= m ; ++i)
    {
    	int u , v , w;
    	cin >> u >> v >> w;
    	ad[u].pb({v , w});
    	ad[v].pb({u , w});
    }
}
void Solve()
{
    while(!qu.empty())
    {
    	int u = qu.top().se , dd = qu.top().fi;
    	qu.pop();
    	if(dis[u] != dd) continue;
    	for(auto i : ad[u])
    	{
    		int v = i.fi , len = i.se + dd;
    		if(dis[v] > len)
    		{
    			dis[v] = len;
    			par[v] = par[u];
    			qu.push({len , v});
    		} 
    	}
    }

    int Res = inf , out1 , out2;
    for(int i = 1 ; i <= n ; ++i)
    {
    	for(auto j : ad[i])
    	{
    		int u = j.fi , len = j.se;
    		if(par[i] != par[u]) 
    		{
    			if(dis[i] + dis[u] + len < Res)
    			{
    				Res = dis[i] + dis[u] + len;
    				out1 = par[i] , out2 = par[u];
    			}
    		}
    	}
    }
    if(Res == inf) cout << "No luck at all";
    else cout << Res << '\n' << out1 << ' ' << out2;
}
#undef int
int main()
{
    if(fopen("trash.inp" , "r"))
        freopen("trash.inp" , "r" , stdin) , freopen("trash.out" , "w" , stdout);
    // else freopen(".inp" , "r" , stdin) , freopen(".out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
}