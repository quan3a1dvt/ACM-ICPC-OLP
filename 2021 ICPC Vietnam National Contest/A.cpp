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
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    pair<int,int> a[n*n];
    FOR(i,0,n*n-1){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a,a+n*n);
    vector<pair<pair<int,int>,vector<int>>> v;
    vector<int> tmp;
    tmp.push_back(a[0].second);
    v.pb({{1,a[0].first},tmp});
    
    FOR(i,1,n*n-1){
        if (a[i].first == a[i-1].first){
            v[v.size()-1].first.first++;
            v[v.size()-1].second.push_back(a[i].second);
        }
        else{
            tmp.clear();
            tmp.push_back(a[i].second);
            v.pb({{1,a[i].first},tmp});
        }
    }
    // FOR(i,0,v.size()-1){
    //     cout << v[i].first << " " << v[i].second << endl;
    // }
    
    int res[n*n] = {0};
    FOR(i,1,n){
        
        int index = 0;
        while(v[index].first.first == 0) index++;
        sort(v.begin() + index,v.end());
        // FOR(j,0,v.size()-1){
        //     cout << v[j].first.first << " " << v[j].first.second << endl;
        // }
        // cout << index << endl ;
    
        int m = min(n,v[index].first.first);
        FOR(j,1,m){
            v[index].first.first--;
            res[v[index].second.back()] = i;
            v[index].second.pop_back();
        }
        FOR(j,1,n-m){
            v[v.size()-1].first.first--;
            res[v[v.size()-1].second.back()] = i;
            v[v.size()-1].second.pop_back();
        }
    }
    cout << "YES\n";
    FOR(i,0,n*n-1) cout << res[i] << " ";
}
