#include <bits/stdc++.h>
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)
#define ll long long
 
#define fillArray(n, arr) ll arr[n]; for(ll i=0; i< n; i++) cin>>arr[i]
#define fillVector(n, arr) vector<ll> arr(n);loop(i,n)cin>>arr[i];
#define speed cin.tie(0); cin.sync_with_stdio(0)
#define tests  ll t;cin>>t;Loop(T,t+1)
#define OO 9223372036854775807//9223372036854775807
#define dotProduct(a,b) ((conj(a)*(b)).real())
#define crossProduct(a,b) ((conj(a)*b).imag())
#define rotate0(p,ang) ((p) *exp(complex<long double>(0,ang)))
#define rotate(p,ang,about) (rotate0((p - about),ang)+ about)
#define reflect0(v,m) (conj((v)/(m))*(m))
#define reflect(p,p0,p1) conj((p - p0)/(p1-p0))*(p1-p0)  + p0   // Reflect poll p1 around p0p1
const long double PI= 3.141592653589793238462643383279;
using namespace std;
ll mod =  998244353;
 
ll max(ll one, ll two)
{
    if(one > two)
        return one;
    return two;
}
ll min(ll one, ll two)
{
    if(one < two)
        return one;
    return two;
}
ll gcd(ll one, ll two)
{
    if(!two)
        return one;
    return gcd(two, one%two);
}

ll lcm(ll one, ll two)
{
    ll g = gcd(one, two);
    return (one * two)/g;
}
vector<vector<ll>> adj;
vector<bool> visited;
ll n;
vector<ll> ans;

void dfs(ll node, int cas)
{
    visited[node] = 1;
    if(cas == 2)
    {
        ans.push_back(adj[node].size());

        for(auto x:adj[node])
        {
            if(visited[x])
                continue;
            if(adj[x].size()> 1)
                dfs(x,0);
        }
    }
    else
    {
        for(auto x:adj[node])
        {
            if(visited[x])
                continue;
            dfs(x,cas+1);
        }
    }
}

void solve()
{
    cin>>n;
    adj = vector<vector<ll>>(n);
    visited = vector<bool>(n);
    
    loop(i,n-1)
    {
        ll one, two;
        cin>>one>>two;
        one--,two--;
        adj[one].push_back(two);
        adj[two].push_back(one);
    }
    loop(i,n)
    {
        if(adj[i].size() == 1)
        {
            dfs(i,1);
            break;
        }
    }
    sort(ans.begin(), ans.end());
    for(auto x:ans)
        cout<<x<<" ";

}

int main()
{
    speed;
    solve();
}
