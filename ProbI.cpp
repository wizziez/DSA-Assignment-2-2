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
void Floyd_Warshall(vector<vector<ll>> &ms, int &countNode)
{
    for (int k = 0; k < countNode; ++k)
        for (int i = 0; i < countNode; ++i)
            for (int j = 0; j < countNode; ++j)
                if (ms[i][k] < LLONG_MAX && ms[k][j] < LLONG_MAX)
                    ms[i][j] = min(ms[i][j], ms[i][k] + ms[k][j]);
}

inline void solve() {
 int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> ms(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ms[i].push_back(LLONG_MAX);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a, --b;
        if (c < ms[a][b])
            ms[a][b] = c, ms[b][a] = c;
    }

    Floyd_Warshall(ms, n);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a == b)
            cout << 0 << endl;
        else
            cout << (ms[a][b] == LLONG_MAX ? -1 : ms[a][b]) << endl;
    }
}

int main() {
    fast;
  //  Test
        solve();
    return 0;
}

