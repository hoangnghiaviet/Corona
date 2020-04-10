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
const int MOD = 1e9 + 7;
const int N = 305;
int n , cnt , a[N] , gt[N] , rev[N] , s[N] , num[N] , dp[N][N] , vs[N];
void Input()
{
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
    {
    	cin >> a[i];
    }
}
bool Squre(int a)
{
	int t = sqrt(a);
	return t * t == a;
}
int Pow(int a , int b)
{
	if(b == 0) return 1;
	int T = Pow(a , b / 2);
	if(b % 2 == 0) return T * T % MOD;
	return T * T % MOD * a % MOD; 	
}
int C(int a , int b)
{
	return gt[b] * rev[a] % MOD * rev[b - a] % MOD;
}
void Prepare()
{
	gt[0] = 1 , rev[0] = 1;
    for(int i = 1 ; i <= n ; ++i)
    {
    	gt[i] = gt[i - 1] * i % MOD;
    	rev[i] = rev[i - 1] * Pow(i , MOD - 2) % MOD;
    }
}
void Divine()
{
	mset(vs , 0);
	s[0] = 0;
	cnt = 0;
	for(int i = 1 ; i <= n ; ++i)
	{
		if(vs[i]) continue;
		vs[i] = 1;
		cnt++;
		num[cnt] = 1;
		for(int j = i + 1 ; j <= n ; ++j)
		{
			if(Squre(a[i] * a[j])) 
			{
				vs[j] = 1;
				num[cnt]++;
			}
		}
		s[cnt] = s[cnt - 1] + num[cnt];
	}
}
void Add(int &a , int b)
{
	a = (a + b) % MOD;
}
void Cal()
{
	dp[1][num[1] - 1] = gt[num[1]];
	for(int i = 1 ; i < cnt ; ++i)
	{
		for(int j = 0 ; j <= n ; ++j)
		{
			if(dp[i][j] == 0) continue;
			for(int div = 1 ; div <= min(s[i] + 1 , num[i + 1]) ; ++div)
			{
				for(int bad = 0 ; bad <= min(j , div) ; ++bad)
				{
					Add(dp[i + 1][j - bad + num[i + 1] - div] , dp[i][j] * C(bad , j) % MOD * C(div - bad , s[i] + 1 - j) % MOD * C(div - 1 , num[i + 1] - 1) % MOD * gt[num[i + 1]] % MOD);
				}
			}
		}
	}
	cout << dp[cnt][0];
}
void Solve()
{
    Prepare();
    Divine();
    Cal();
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