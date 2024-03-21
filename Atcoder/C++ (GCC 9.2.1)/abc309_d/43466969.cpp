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
ll mod =  1e9 + 13;
ll mod2 =  1e9 - 70;
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

ll power(ll one, ll two)
{
    if(!two)
        return 1;
    ll temp = power(one, two/2);
    temp *= temp;
    temp %= mod;
    if(two%2)
        temp *= one;
    return temp%mod;
}
vector<vector<ll>> adj;
ll n1,n2,m;
ll bfs(ll node)
{
    queue<ll> qu;
    vector<bool> visited(n1+n2);
    qu.push(node);
    ll len = 0;
    visited[node] = 1;
    while(qu.size())
    {
        len++;
        ll sz = qu.size();
        loop(i,sz)
        {
            ll cur = qu.front();
            qu.pop();
            for(auto x:adj[cur])
            {
                if(!visited[x])
                {
                    qu.push(x);
                    visited[x] = 1;
                }
                    
            }
        }
    }
    return len;
}

void solve()
{
    cin>>n1>>n2>>m;
    
    adj = vector<vector<ll>>(n1+n2);
    loop(i,m)
    {
        ll one, two;
        cin>>one>>two;
        one--,two--;
        adj[one].push_back(two);
        adj[two].push_back(one);
    }
    cout<< bfs(0) + bfs(n1 + n2-1) - 1;
}

 
int main()
{
    speed;
    //tests
        solve();

}  
