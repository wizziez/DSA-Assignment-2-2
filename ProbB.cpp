#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<ll>> dp(s2.size() + 1, vector<ll>(s1.size() + 1, 0));

    for (ll i = 0; i <= s2.size(); i++) {
        for (ll j = 0; j <= s1.size(); j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = i + j;
                continue;
            }
            if (s1[j - 1] != s2[i - 1])
                dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + 1;
            else
                dp[i][j] = dp[i - 1][j - 1];
        }
    }

    cout << dp[s2.size()][s1.size()] << endl;
}

int main() {

    solve();
    return 0;
}
