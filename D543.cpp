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
const int MOD = 1e9 + 7;
int n , Down[N] , Up[N] , f[N];
vector < int > ad[N];
void Input()
{
	cin >> n;
	for(int i = 2 ; i <= n ; ++i)
	{
		int u;
		cin >> u;
		ad[i].pb(u);
		ad[u].pb(i);
	}    
}
void DFS_1(int u , int par)
{
	Down[u] = 1;
	for(auto y : ad[u])
	{
		if(y == par) continue;
		DFS_1(y , u);
		Down[u] = (Down[u] * (Down[y] + 1)) % MOD;
	}
}
void Downn()
{
	DFS_1(1 , 0);
}
void DFS_2(int u , int par)
{
	f[ad[u].size()] = 1;
	int cur = 1;
	for(int i = ad[u].size() - 1 ; i >= 0 ; --i)
	{
		int y = ad[u][i];
		if(y == par) f[i] == f[i + 1];
		else f[i] = f[i + 1] * (Down[y] + 1) % MOD;
	}
	for(int i = 0 ; i < ad[u].size() ; ++i)
	{
		int y = ad[u][i];
		if(y == par) continue;
		Up[y] = (Up[u] * cur % MOD * f[i + 1] % MOD + 1) % MOD;
		cur = cur * (Down[y] + 1) % MOD;
	}
	for(int i = 0 ; i < ad[u].size() ; ++i)
	{
		int y = ad[u][i];
		if(y == par) continue;
		DFS_2(y , u);
	}
}
void Upp()
{
	Up[1] = 1;
	DFS_2(1 , 0);
}
void Solve()
{
    Downn();
    Upp();
    for(int i = 1 ; i <= n ; ++i)
    {
    	cout << (Up[i] * Down[i]) % MOD << ' ';
    }
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