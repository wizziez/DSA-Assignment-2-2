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
  int n , seq ;

  cin >> n >> seq ;

  vector<int> adj[ n + 1] ;
  vector<int> inOrder(n + 1 , 0 ) ;
   for(int i = 0 ; i < seq ; i++){
      ll course1 , course2 ;
      cin >> course1 >> course2 ;
       adj[course1].push_back(course2) ;
       inOrder[course2]++ ;
   }

   queue<int> q ;

    for(int i = 1 ; i <= n ; i++){
        if( inOrder[i] == 0)
            q.push(i) ;
    }
    vector<int> topo ;

    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;
        topo.push_back(node) ;

        for(auto it : adj[node]){
            inOrder[it]--;

            if(inOrder[it] == 0)
                 q.push(it) ;
        }
    }

    if( topo.size() < n ){
        cout << "IMPOSSIBLE" << endl ;
    }
    else{
        for(auto it  : topo)
             cout << it << " " ;
        cout << endl ;
    }
}

int main() {
    fast;
  //  Test
        solve();
    return 0;
}

