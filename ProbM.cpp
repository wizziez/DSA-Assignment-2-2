#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
inline void solve()
{
    ll l, r;
    cin >> l >> r;
    ll sz = floor(log2(r / l)) + 1;
    ll max_l = floor(r / pow(2, sz - 1));
    ll max_l_3 = floor(r / (pow(2, sz - 2) *3 ));
    if(max_l_3 >= l)
    cout << sz << " " <<  (max_l_3 - l + 1)*( sz - 1) + max_l - l + 1 << endl;
    else
    cout << sz << " " <<  /*(max_l_3 - l + 1)*( sz - 1)*/ + max_l - l + 1 << endl;
}
int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
