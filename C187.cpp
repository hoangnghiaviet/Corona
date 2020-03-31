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
const int inf = 1e15;
const int N = 2e5 + 5;
int n , m , k , s , t , vol[N] , dis[N];
vector < int > ad[N];
IImin qu;
void Input()
{
    cin >> n >> m >> k;
    for(int i = 1 ; i <= k ; ++i) 
    {
    	int u;
    	cin >> u;
    	vol[u] = 1;
    }
    for(int i = 1 ; i <= m ; ++i)
    {
    	int u , v;
    	cin >> u >> v;
    	ad[u].pb(v);
    	ad[v].pb(u);
    }
    cin >> s >> t;
}
bool Check(int mid)
{
	mset(dis , 0x3f);
	dis[s] = 0;
	qu.push({0 , s});
	while(!qu.empty())
	{
		int u = qu.top().se , dd = qu.top().fi;
		qu.pop();
		if(dd != dis[u]) continue;
		for(auto y : ad[u])
		{
			int Tam = dd + 1;
			if(vol[y]) Tam = 0;
			if(dis[y] > Tam)
			{
				dis[y] = Tam;
				if(dis[y] < mid) qu.push({dis[y] , y});
			}
		} 
	}
	return dis[t] <= mid;
}
void Solve()
{
	int low = 0 , high = n , Res = -1;
	while(low <= high)
	{
		int mid = (low + high) / 2;
		if(Check(mid)) Res = mid , high = mid - 1;
		else low = mid + 1;
	}
	cout << Res;
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