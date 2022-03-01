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


int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    int n,k;
    cin >> n >> k;
    int a[n];
    FOR(i,0,n-1) cin >> a[i];
    sort(a,a+n);
    int MIN = 0, MAX = 0;
    FOR(i,0,k-1) if (a[i] != 1) MIN += a[i];
    FOR(i,n-k,n-1) if (a[i] != 1) MAX += a[i];
    cout << MIN << " " << MAX;
}
