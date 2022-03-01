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

int c;
int a[10];
int pin[4];
int gpin[4][4] = {{1,2,4,5},{2,3,5,6},{4,5,7,8},{5,6,8,9}};

void rotate(int x){
    vector<int> v = {x};
    FOR(i,0,3) {
        if (pin[i] == 1){
            FOR(j,0,3) v.push_back(gpin[i][j]);
        }
    }
    sort(v.begin(), v.end());
    auto ip = unique(v.begin(), v.end());
    v.resize(distance(v.begin(), ip));
    FOR(i,0,v.size()-1){
        a[v[i]] = (a[v[i]] + 1) % c;
    }
    
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    
    cin >> c;
    FOR(i,1,9) cin >> a[i];
    vector<string> res;
    res.push_back("YES");
    res.push_back("");
    int move[9] = {2,4,6,8,1,3,7,9,5};
    int moveres[9][6] = {
        {0, 0, 1, 1, 7, 0},
        {0, 1, 0, 1, 9, 0},
        {1, 0, 1, 0, 1, 0},
        {1, 1, 0, 0, 3, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 7, 0},
        {0, 0, 0, 0, 9, 0},
        {1, 1, 1, 1, 1, 0},
    };
    FOR(i,0,8){
        string s = "";
        int dem = 0;
        FOR(j,0,3) pin[j] = moveres[i][j];
        if (i != 8 && a[move[i]] != a[5]){
            while(a[move[i]] != a[5]){
                rotate(moveres[i][4]);
                dem++;
            }
            moveres[i][5] = dem;
            FOR(j,0,5) s += (to_string(moveres[i][j]) + " ");
            res.push_back(s);
        }
        else if (i == 8){
            while(a[move[i]] != 0){
                rotate(moveres[i][4]);
                dem++;
            }
            moveres[i][5] = dem;
            FOR(j,0,5) s += (to_string(moveres[i][j]) + " ");
            res.push_back(s);            
        }
    }
    res[1] = to_string(res.size() - 2);
    FOR(i,0,res.size()-1){
        cout << res[i] << endl;
    }
}
