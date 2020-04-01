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
const int N = 3e6 + 9;
int n , m , a[N] , b[N] , Num[N] , Equal[N] , f[N] , Max;
void Input()
{
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
    {
    	cin >> a[i];
    	Num[a[i]]++;
    }
    cin >> m;
    for(int i = 1 ; i <= m ; ++i)
    {
    	cin >> b[i];
    	Max = max(Max , b[i]);
    }
}
void Prepare()
{
	for(int i = 1 ; i <= 3000005 ; ++i)
	{
		for(int j = i ; j <= 3000005 ; j = j + i)
		{
			if(j / i != i)
			{
				Equal[j] += (Num[i] * Num[j / i]);
			}
			else 
			{
				Equal[j] += (Num[i] * (Num[i] - 1));
			}
		}
	}
	f[1] = n * (n - 1);
	for(int i = 2 ; i <= 3000000 ; ++i)
	{
		f[i] = f[i - 1] - Equal[i - 1];
	}
}
void Solve()
{
	Prepare();
    for(int i = 1 ; i <= m ; ++i)
    {
    	cout << f[b[i]] << '\n';
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