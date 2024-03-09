#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define forr(x, n) for (int i = x; i < n; i++)
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define sp << ' ' <<
#define print_ara(x, st, ed)      \
    for (int i = st; i < ed; i++) \
        cout << x[i] << " \n"[i == ed - 1];
#define print_map(t) \
    for (auto u : t) \
        cout << u.ff << " -> " << u.ss << nl;
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                 \
    cout.tie(0);
 
const int N = (int)1e6 + 5;
const ll inf = (ll)1e18 + 5;
const int mod = (int)1e9 + 7;

int main(){
    faster;
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    ordered_set s;
    for(int i = 0; i < k; i++){
        s.insert({a[i], i});
    }
    cout<<s.find_by_order((k-1)/2)->first<<" ";
    for(int i = 1; i <= n-k; i++){
        s.erase(s.find({a[i-1],i-1}));
        s.insert({a[i+k-1], i+k-1});
        cout<<s.find_by_order((k-1)/2)->first<<" ";    
    }
    cout<<nl;
}
