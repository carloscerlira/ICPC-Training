#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl                        '\n'
#define fastIO()                    cin.tie(0); cout.tie(0);
#define FO(i, b)                    for (int i = 0; i < (b); i++)
#define FOR(i, a, b)                for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)               for (int i = (a); i > (b); i--)
#define TR(v, arr)                  for (auto& (v) : (arr))
#define debug(x)                    cout << #x << " = "; _debug(x); cout << endl;
#define si(x)	                    scanf("%d",&x)
#define sl(x)	                    scanf("%lld",&x)
#define pi(x)	                    printf("%d\n",x)
#define pl(x)	                    printf("%lld\n",x)
#define pb                          push_back
#define mp                          make_pair
#define F                           first
#define S                           second
#define all(x)                      x.begin(), x.end() 
#define sz(x)                       (int) x.size()
#define LB(arr, x)                  lower_bound(all(arr), x)-(arr).begin()
#define UB(arr, x)                  upper_bound(all(arr), x)-(arr).begin()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void setIO(){
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";
    freopen(in_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);
}

template <typename T>
void _debug(T& x){
    cout << x;
}

template <typename T1, typename T2>
void _debug(pair<T1, T2>& pair){
    cout << "{"; _debug(pair.F); cout << ","; _debug(pair.S); cout << "}";  
}

template <typename T>
void _debug(vector<T>& vec){
    int n = sz(vec);
    if(n == 0){cout << "[ ]"; return;}
    cout << "[";
    FO(i, n-1){
        _debug(vec[i]); cout << " ";
    }
    _debug(vec[n-1]); cout << "]";
}

void _debug(vector<string>& vec){
    int n = sz(vec);
    cout << endl;
    FO(i, n){
        cout << vec[i] << endl;
    }
}

template <typename T>
void _debug(vector<vector<T>>& A){
    int n = sz(A);
    cout << endl;
    FO(i, n){
        _debug(A[i]); cout << endl;
    }
}

template <typename T>
void print(T& x){
    cout << x << endl;
    return;
}

template <typename T>
void print(vector<T>& vec, int a=0, int b=-1){
    if(b == -1){b = sz(vec);}
    if(b == 0){return;}
    FOR(i, a, b-1){
        cout << vec[i] << " ";
    }
    cout << vec[b-1] << endl;
    return; 
}

struct sensor{
    ll x, y, s;
};

const int MXK = 1e3+1;
vector<sensor> sensors(MXK);
vector<bool> vis(MXK, 0);
bool wall_left, wall_down, wall_right, wall_up;
int m, n, k; 

ll power(ll x){
    return x*x;
}

bool inter(sensor a, sensor b){
    return power(a.x-b.x)+power(a.y-b.y) <= a.s*a.s+b.s*b.s+2*a.s*b.s;
}

void check_walls(sensor a){
    if(a.x-a.s <= 0){wall_left=true;}
    if(a.y-a.s <= 0){wall_down=true;}
    if(a.x+a.s >= m){wall_right=true;}
    if(a.y+a.s >= n){wall_up=true;}
}

void dfs(int i){
    if(vis[i] == 1){return;}
    vis[i] = true;
    check_walls(sensors[i]);
    FO(j, k){
        if(j == i){continue;}
        if(inter(sensors[i], sensors[j])){dfs(j);}
    }
}

void solve(){
    si(m); si(n); si(k);
    FO(i, k){
        sl(sensors[i].x); sl(sensors[i].y); sl(sensors[i].s);
    }
    FO(i, k){
        if (vis[i] == 0){
            wall_left = wall_down = wall_right = wall_up = false;
            dfs(i);
            if(wall_left && wall_down){cout << "N"; return;}
            if(wall_right && wall_up){cout << "N"; return;}
            if(wall_left && wall_right){cout << "N"; return;}
            if(wall_up && wall_down){cout << "N"; return;}
        }
    }
    cout << "S";
    return;
}

int main()
{
    fastIO();
    if(getenv("LOCAL")){setIO();}
    int T=1;
    FO(tc, T){
        solve();
    }	
    return 0;
}