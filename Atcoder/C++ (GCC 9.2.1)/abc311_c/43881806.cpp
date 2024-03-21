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
#define reflect(p,p0,p1) conj((p - p0)/(p1-p0))*(p1-p0)  + p0   // Reflect point p1 around p0p1
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

vector<ll> adj;

vector<ll> ans;
vector<bool> visited;
bool fun(ll node)
{
    if(visited[node])
    {
        bool flag =0;
        vector<ll> ans2;
        for(auto x:ans)
        {
            if(x == node)
                flag = 1;
            if(flag)ans2.push_back(x+1);
        }
        cout<<ans2.size()<<'\n';
        for(auto x:ans2)
            cout<<x<<" ";
        return 1;
    }
    visited[node] = 1;
    ans.push_back(node);
    if(adj[node] != -1)
    {
        if(fun(adj[node]))
            return 1;
            
    }
    ans.pop_back();
    return 0;
}

void solve()
{
    ll n;
    cin>>n;
    adj = vector<ll>(n,-1);
    visited = vector<bool>(n);
    loop(i,n)
    {
        ll temp;
        cin>>temp;
        temp--;
        adj[i] = temp;
    }
    loop(i,n)
    {
        if(!visited[i])
        {
            if(fun(i))
                return;
        }
    }
}


 
int main()
{
    speed;
    //tests
        solve();

}  

