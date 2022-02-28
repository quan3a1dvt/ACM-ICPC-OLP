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
int cal(vector<int> v, int n){
    int MIN = 1000;
    FOR(i,0,25){
        int tmp = 0;
        FOR(j,0,n-1){ 
            if (v[j] >= i) tmp += min(v[j] - i, 25 - v[j] + i + 1);
            else tmp += min(i-v[j], v[j] - 0 + 25 - i + 1);
        }
        MIN = min(MIN,tmp);
    }
    return MIN;
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    int r,c;
    cin >> r >> c;
    int a[r][c];
    char x;
    FOR(i,0,r-1){
        FOR(j,0,c-1){
            cin >> x;
            a[i][j] = x - 'A';
        }
    }
    int res = 0;
    FOR(i,0,(r-1)/2){
        FOR(j,0,(c-1)/2){
            if (i == r-i-1 && j == c-j-1){
                vector<int> t = {a[i][j]};
                res += cal(t,1);
            }
            else if(i == r-i-1){
                vector<int> t = {a[i][j], a[i][c-j-1]};
                res += cal(t,2);
            }
            else if(j == c-j-1){
                vector<int> t = {a[i][j], a[r-i-1][j]};
                res += cal(t,2);
            }
            else{
                vector<int> t = {a[i][j], a[i][c-j-1], a[r-i-1][j], a[r-i-1][c-j-1]};
                res += cal(t,4);
            }
            
        }
    }
    cout << res;
}
