#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define eps 1e-9
#define infi 1e9
#define PI 2*acos(0.0)
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
const ll MOD = 1000000007;
int cmp(ll a, ll b){
	if (abs(a-b) < eps) return 0;
	return (a > b ? 1 : -1);
}
struct point{
    ll x;
    ll y;
    point(){}
    point(ll x,ll y){
        this->x = x;
        this->y = y;
    }
};
int ccw(point p0, point p1, point p2){      // vector p0p1, p0p2
    ll dx1 = p1.x - p0.x;               //counterclockwise
    ll dy1 = p1.y - p0.y;
    ll dx2 = p2.x - p0.x;
    ll dy2 = p2.y - p0.y;
    return cmp(dx1 * dy2 - dx2 * dy1, 0);
    // 0 thẳng hàng      1 hướng hương    2 hướng âm
}
ll dist(point p0, point p1){
    ll dx = p1.x - p0.x, dy = p1.y - p0.y;
    return dx * dx + dy * dy;
}


int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
    ll x;
    ll y;
    ll res = 0;
    int n;
    cin >> n;
    vector<point> v(n);
    
    FOR(i,0,n-1){
        cin >> x >> y;
        v[i] = point(x,y);
    }
    map<vector<ll>,ll> m0;
    FOR(p1,0,n-1){
        FOR(p2,p1+1,n-1){
            FOR(p3,p2+1,n-1){
                if (ccw(v[p1],v[p2],v[p3]) == 0) continue;
                vector<ll> tmp = {dist(v[p1], v[p2]), dist(v[p2], v[p3]), dist(v[p3], v[p1])};
                sort(tmp.begin(), tmp.end());
                m0[tmp]++;
            }
        }
    }
    
    map<pair<ll,vector<ll>>,ll> m1;
    FOR(p1,0,n-1){ 
        FOR(p2,0,n-1){
            FOR(p3,p2+1,n-1){
                if (ccw(v[p1],v[p2],v[p3]) == 0) continue;
                vector<ll> tmp = {dist(v[p1], v[p2]), dist(v[p2], v[p3]), dist(v[p3], v[p1])};
                sort(tmp.begin(), tmp.end());
                m1[{p1,tmp}]++;
            }
        }
    }
    map<pair<pair<ll,ll>,vector<ll>>,ll> m2;
    FOR(p1,0,n-1){
        FOR(p2,p1+1,n-1){
            FOR(p3,0,n-1){
                if (ccw(v[p1],v[p2],v[p3]) == 0) continue;
                vector<ll> tmp = {dist(v[p1], v[p2]), dist(v[p2], v[p3]), dist(v[p3], v[p1])};
                sort(tmp.begin(), tmp.end());
                m2[{{p1,p2},tmp}]++;
            }
            
        }
    }
    FOR(p1,0,n-1){
        FOR(p2,p1+1,n-1){
            FOR(p3,p2+1,n-1){
                if (ccw(v[p1],v[p2],v[p3]) == 0) continue;
                vector<ll> tmp = {dist(v[p1], v[p2]), dist(v[p2], v[p3]), dist(v[p3], v[p1])};
                sort(tmp.begin(), tmp.end());
                ll count = m0[tmp] - m1[{p1,tmp}] - m1[{p2,tmp}] - m1[{p3,tmp}]
                           + m2[{{p1,p2},tmp}] + m2[{{p2,p3},tmp}] + m2[{{p1,p3},tmp}] - 1;
                if (tmp[0] == tmp[1] || tmp[1] == tmp[2]) count *= 2;
                res += count;
            }
        }
    }
    cout << res;
}
