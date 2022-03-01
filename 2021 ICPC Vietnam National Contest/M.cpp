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
    int n; cin >> n; 
    int m = n * (n - 1) + 1;
    vector<vector<int>> res(m, vector<int>(n, 0));
    vector<vector<int>> tmp(n - 1, vector<int>(n - 1, 0));
    FOR(i,0,n-1) res[0][i] = i + 1;
    FOR(i,1,m-1) {
        res[i][0] = (i - 1) / (n - 1) + 1;
    }
    FOR(i,0,n-2){
        FOR(j,0,n-2){
            tmp[i][j] = i * (n - 1) + j + n + 1;
        }
    }   
    FOR(i,1,n-1) {
        FOR(j,1,n-1) {
            res[i][j] = tmp[i - 1][j - 1];
        }
    }

    FOR(i,0,n-2) {
        FOR(j,0,n-2) {
            FOR(k,0,n-2) {
                res[i * (n - 1) + j + n][k + 1] = tmp[k][(j + i * k) % (n - 1)];
            }
        }
    }

    cout << m << endl;
    FOR(i,0,m-1) {
        FOR(j,0,n-1) cout << res[i][j] << " ";
        cout << endl;
    }
}
