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

#define SetP(value, precision) \
cout << fixed << setprecision(precision) << (value) << endl

inline void solve() {
    ll row ,col ;
    cin >> row >> col ;

    ll sx ,sy , ex , ey;

    vector< vector<char> > vis( row , vector<char>(col)) ;

    for(ll r = 0 ; r < row ; r++)
        for( ll c = 0 ; c < col ; c++){
            cin >> vis[r][c] ;
            if( vis[r][c] == 'A') { sx = r ; sy = c ; }
            if( vis[r][c] == 'B') { ex = r ; ey = c ; }
        }


    ll dx[] = { 0 , 0 , -1 , 1 } ;
    ll dy[] = { 1 , -1 , 0 , 0 } ;
    char dir[] = {'R' , 'L' , 'U' , 'D'} ;


    vector< vector< pair < ll, ll > >  > parent( row , vector< pair<ll,ll> > (col , {MX , MX})) ;

    queue< pair<ll,ll> > q ;
    q.push({sx , sy }) ;
    parent[sx][sy] = { -1 , -1 } ;
    vis[sx][sy] = '#' ;
    bool f = false ;


    while( !q.empty()){
        ll x = q.front().F ;
        ll y = q.front().S ;

        q.pop() ;

        for( ll i = 0 ; i < 4 ; i++){
            ll new_x = x + dx[i] ;
            ll new_y = y + dy[i] ;
            char mov = dir[i] ;


            if( new_x >= 0 && new_x < row && new_y >= 0 && new_y < col && (vis[new_x][new_y] == '.' || vis[new_x][new_y] == 'A' || vis[new_x][new_y] == 'B') ){

                if( vis[new_x][new_y] == 'B' )
                    f = true ;
                vis[new_x][new_y] = mov ;
                parent[new_x][new_y] = {x , y} ;
                q.push({ new_x , new_y}) ;
                if(f)
                    break ;
            }
        }
        if(f)
            break ;
    }

    if(!f){
        cout << "NO" << endl ;
        return ;
    }


    string path ;
    ll a = ex ;
    ll b = ey ;
    while( !(a == sx && b == sy) ){
        path.push_back(vis[a][b]) ;
        ll temp_a = parent[a][b].F ;
        ll temp_b = parent[a][b].S ;
        a = temp_a;
        b = temp_b ;

    }
    reverse(path.begin() , path.end());
    cout << "YES" << endl ;
    cout << path.size() << endl ;
    cout << path << endl ;
}

int main() {
    fast;

    solve();
    return 0;
}
