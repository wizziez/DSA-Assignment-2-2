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

///LUIMAS

inline void solve() {
ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> applicants(n);
    vector<ll> apartments(m);

    for (auto it : applicants )
        cin >> it;


    for (auto it : apartments)
        cin >> it ;

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    ll ans = 0;
    ll i = 0, j = 0;
    while (i < n && j < m) {
        if (abs(applicants[i] - apartments[j]) <= k) {
            ++ans;
            ++i;
            ++j;
        } else if (applicants[i] < apartments[j])
            ++i;
         else
            ++j;
    }

    cout << ans << endl;
}

int main() {
    fast;
     //Test
    solve() ;
    return 0;
}

