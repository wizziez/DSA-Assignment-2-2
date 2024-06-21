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
#define Loop(i,n) for( ll i = 0 ; i < n ; i++ )
#define pb push_back
#define vect(v,n) ll n ; cin >> n ; vector<ll> v(n) ; for( ll i = 0 ; i < n ; i++ ) cin >> v[i];
#define maxAll(vec) (*max_element(vec.begin(), vec.end()))
#define minAll(vec) (*min_element(vec.begin(), vec.end()))

const ll MOD = 1e9 + 7 ;
const ll MX = LLONG_MAX ;
const ll MN = LLONG_MIN ;

ll dx[] = { 0 , 0 , -1 , 1 } ;
ll dy[] = { 1 , -1 , 0 , 0 } ;

#define SetP(value, precision) \
cout << fixed << setprecision(precision) << (value) << endl

class DSU{
 private:
     vector<ll> parent , ranK , sizE ;
 public:
    DSU( ll n ){
         parent.resize(n + 1) ;
         ranK.resize( n + 1 , 0) ;
         sizE.resize( n + 1 , 0 ) ;
         for(ll i = 0 ; i <= n ; i++)parent[i] = i ;
    }
   ll findParent(ll x){
        if( x == parent[x] ) return x ;
        return parent[x] = findParent(parent[x]) ;
   }


   void Union( ll node1 , ll node2 ){
      ll up1 = parent[node1] ;
      ll up2 = parent[node2] ;

      if( up1 == up2 )
          return ;
      if( sizE[up1] < sizE[up2]){
         parent[up1] = up2 ;
         sizE[up2] += sizE[up1] ;
      }
      else if(sizE[up1] > sizE[up2]){
        parent[up2] = up1 ;
        sizE[up1] += sizE[up2] ;
      }
      else{
        parent[up2] = up1 ;
        sizE[up1] += sizE[up2] ;
      }
   }

};

 ll row , col ;
void dfs( pair< ll ,ll > pr , vector<vector<ll>> &v ){
           ll p = pr.F ;
           ll q = pr.S ;
           v[p][q] = 1 ;

           for( ll i = 0 ; i < 4 ; i++){
              ll x = p + dx[i] ;
              ll y = q + dy[i] ;

              if( x >= 0 && x < row && y >= 0 && y < col && v[x][y] == 2 )
              dfs({x , y} , v) ;
           }


}




inline void solve() {


  cin >> row >> col ;

  vector<vector<ll>> v( row , vector<ll>(col , 0) ) ;

   for( ll i = 0 ; i < row ; i++)
         for( ll j = 0 ; j < col ; j++){
                {
                    char x ; cin >> x ;
                    if( x == '.' )
                        v[i][j] = 2 ;
                }
   }



     ll ans = 0 ;

     for( ll i = 0 ; i < row ; i++)
     for( int j = 0 ; j < col ; j++){
         if(v[i][j] == 2){
         dfs({i,j} , v ) ;
         ans++;
         }
     }
     cout << ans << endl ;
}

int main() {
    fast;

        solve();
    return 0;
}
