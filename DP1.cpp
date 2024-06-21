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
ll n , x ;
cin >> n>> x ;

  vector<ll>v(n) ;

  for(auto &it : v)
     cin >> it ;

  vector<ll> dp( x + 1 , MX) ;
  dp[0] = 0 ;

  for( ll i =1 ; i <=  x ; i++){
    for(auto it : v) {
        dp[i] = min( dp[i] , (i >= it && dp[i-it] != MX ) ? 1 + dp[ i - it] : MX  ) ;
    }
  }
   if(dp.back() == MX){
    cout << -1 << endl ;
    return ;
   }
  cout << dp.back() << endl ;

}

int main() {
    fast;

        solve();
    return 0;
}

