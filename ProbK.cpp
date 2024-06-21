#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    int cc = 1;


    while(1) {
        ll N, Q;
        cin >> N >> Q;

        if (N == 0 && Q == 0) {
            break;
        }

        vector<ll> a(N);
        for (ll i = 0; i < N; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        //cout << endl;
         cout << "CASE# " << cc << ":" << endl;
        for (ll i = 0; i < Q; i++) {
            ll p;
            cin >> p;
             ll ans = lower_bound(a.begin(),a.end(),p) - a.begin();
            if(ans == N) {
                cout << p << " not found" << endl;
            } else if(a[ans] != p) {
                cout << p << " not found" << endl;
            } else {
                cout << p << " found at " << ans + 1 << endl;
            }
        }

        cc++;
    }
}

int main() {
    solve();
 return 0;
}

