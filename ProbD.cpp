#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define Test ll tc; cin >> tc; while(tc--)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define srt(v) sort(v.begin() , v.end())
#define revSrt(v) sort(v.rbegin() , v.rend())
#define Loop(n) for( ll i = 0 ; i < n ; i++ )
#define pb push_back
#define vect(n) ll n ; cin >> n ; vector<ll> v(n) ; for( ll i = 0 ; i < n ; i++ ) cin >> v[i];
#define maxAll(vec) (*max_element(vec.begin(), vec.end()))
#define minAll(vec) (*min_element(vec.begin(), vec.end()))

const ll MOD = 1e9 + 7 ;
const ll MX = LLONG_MAX ;
const ll MN = LLONG_MIN ;

#define SetP(value, precision) \
cout << fixed << setprecision(precision) << (value) << endl

inline void solve() {
ll n ;
cin >> n ;
vector<vector<char>> grid( n , vector<char>(n)) ;

   for( ll i = 0 ; i < n ; i++)
      for( ll j = 0; j < n ; j++)
        cin >> grid[i][j] ;

    vector<vector<ll>> dp( n , vector<ll>( n , 0)) ;
     dp[0][0] = 1 ;

    if( grid[0][0] == '*')
        dp[0][0] = 0 ;
for( ll i = 0 ; i < n ; i++)
     for( ll j = 0 ; j < n ; j++)
     {
        if(grid[i][j] == '*' || i == j && i == 0)
        continue ;
        dp[i][j] = (i > 0 ? dp[i-1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0);
     dp[i][j] %= MOD ;

     }
    cout << dp[n-1][n-1] << endl ;
}

int main() {
    fast;

        solve();
    return 0;
}
