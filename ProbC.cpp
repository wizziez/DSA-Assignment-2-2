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
    ll n;
    cin >> n;

    vector<ll> v(n);

    for (auto &it : v)
        cin >> it;

    vector<ll> lis;
    lis.push_back(v[0]);

    for (ll i = 1; i < n; i++) {
        if (v[i] > lis.back())
            lis.push_back(v[i]);
        else {
            auto index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[index] = v[i];
        }
    }

    cout << lis.size() << endl;
}

int main() {
    fast;

        solve();
    return 0;
}

