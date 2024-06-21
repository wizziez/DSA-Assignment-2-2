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
 ll n , k ;
    cin >> n >> k ;
    map<ll,ll> mp ;
    for(ll i = 0 ; i < n ; i++ ){
        ll x ;
        cin >> x ;
        if( x % k == 0 ) continue ;
        mp[ k - (x % k) ]++ ;
    }
    ll mx_rem = 0 ;
    for(auto it : mp )
        mx_rem = max(mx_rem , it.second) ;

    ll mx_num = 0 ;
    for(auto it : mp){
        if(it.second == mx_rem )
            mx_num = max( mx_num , it.first) ;
    }
    cout << max( 0LL , 1LL + ( (mx_rem - 1LL) * k ) + mx_num ) << endl ;
}

int main() {
    fast;
     Test
    solve() ;
    return 0;
}

