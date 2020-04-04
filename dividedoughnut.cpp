#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e15;
const int half = 5e8;
const int MOD = 1e9;
int n;
void Input()
{
    cin >> n;
}
void Out(int u)
{
	cout << "YES " << u;
	exit(0);
}
int Get(int u)
{
	int ans;
	cout << "QUERY " << u << ' ' << (u + half - 1) % MOD << endl;
	cin >> ans;
	if(ans == n / 2) Out(u);
	return ans;
}
void Solve()
{
    int low = 0 , high = half , Tem = Get(0);
    for(int i = 1 ; i <= 28 ; ++i)
    {
    	int mid = (low + high) / 2;
    	int Sprinkles = Get(mid);
    	if((Sprinkles > n / 2 && Tem < n / 2) || (Sprinkles < n / 2 && Tem > n / 2)) high = mid;
    	else low = mid;
    }
    Out((low + high) / 2);
}
#undef int
int main()
{
    // if(fopen("trash.inp" , "r"))
    //     freopen("trash.inp" , "r" , stdin) , freopen("trash.out" , "w" , stdout);
    // else freopen(".inp" , "r" , stdin) , freopen(".out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
}