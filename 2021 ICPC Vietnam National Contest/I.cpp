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
int tag(string s) {
    if (s == "dp") return 0;
    if (s == "graph") return 1;
    if (s == "mathgeo") return 2;
    if (s == "ds") return 3;
    if (s == "adhoc") return 4;
    return -1;
}
//ll dp[51][17][17][17][17][17];
ll dp[2][17][17][17][17][17];
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
    int n,t;
    string s;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(5, 0));
    FOR(i,0,n-1) {
        cin >> t;
        FOR(j,1,t) {
            cin >> s;
            v[i][tag(s)]++;
        }
    }
    int L[5];
    int R[5];
    FOR(i,0,4) cin >> L[i] >> R[i];
    dp[0][0][0][0][0][0] = 1;
    FOR(i,0,n-1) {
        FOR(x1,0,15) {
            FOR(x2,0,15) {
                FOR(x3,0,15) {
                    FOR(x4,0,15) {
                        FOR(x5,0,15) {
                            if (dp[0][x1][x2][x3][x4][x5]) {
                                dp[1][x1][x2][x3][x4][x5] += dp[0][x1][x2][x3][x4][x5];
                                int n1 = x1 + v[i][0];
                                int n2 = x2 + v[i][1];
                                int n3 = x3 + v[i][2];
                                int n4 = x4 + v[i][3];
                                int n5 = x5 + v[i][4];
                                if (n1 <= 15 && n2 <= 15 && n3 <= 15 && n4 <= 15 && n5 <= 15) {
                                   dp[1][n1][n2][n3][n4][n5] += dp[0][x1][x2][x3][x4][x5];
                                }
                            }

                        }
                    }
                }
            }
        }
        FOR(x1,0,15) {
            FOR(x2,0,15) {
                FOR(x3,0,15) {
                    FOR(x4,0,15) {
                        FOR(x5,0,15) {
                            dp[0][x1][x2][x3][x4][x5] = dp[1][x1][x2][x3][x4][x5];
                            dp[1][x1][x2][x3][x4][x5] = 0;
                        }
                            
                    }
                }
             }
        }
        
    }
    ll res = 0;
    FOR(i,L[0],R[0]) {
        FOR(j,L[1],R[1]) {
            FOR(k,L[2],R[2]) {
                FOR(l,L[3],R[3]) {
                    FOR(m,L[4],R[4]) {
                        res += dp[0][i][j][k][l][m];
                        if (i == 0 && j == 0 && k == 0 && l == 0 && m == 0) res--;
                    }
                }
            }
        }
    }
    cout << res;
}
