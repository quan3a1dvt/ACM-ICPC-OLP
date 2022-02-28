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

ll d[10000005];
void SieveOfEratosthenes()
{
    ll n=10000001;
    memset(d, 0, sizeof(d));
    FOR(i,2,sqrt(n)) {
        if (d[i] == 0) {
            for (ll j = i * i; j <= n; j += i)
                if (d[j] == 0) d[j] = i;          
        }
    }
    FOR(i,2,n) if (d[i] == 0) d[i] = i;
    d[1] = 0;
}


ll a[1000000];
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    SieveOfEratosthenes();
    int n;
    cin >> n;
    
    FOR(i,0,n-1) cin >> a[i];
    map<ll,ll> m;
    FOR(i,0,n-1){
        ll product = 1;
        ll x = 1;
        while(a[i] != 1){
         
            if (d[a[i]] != x) {
                x = d[a[i]];
                product *= d[a[i]];
            }
            a[i] /= d[a[i]];
        }
        //cout << product <<" ";
        m[product]++;
    }
    ll res = 0;
    for(auto i:m){
        res += (i.second * (i.second - 1) / 2);
    }
    cout << res;
}
