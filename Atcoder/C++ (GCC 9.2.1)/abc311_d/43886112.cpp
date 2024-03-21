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

vector<ll> dx = {0,0,1,-1};
vector<ll> dy = {1,-1,0,0};

vector<string> arr;
ll n,m;

set<pair<ll,ll>> st,visited;


void dfs(ll x = 1,ll y = 1)
{
    if(visited.count({x,y}))
        return;
    visited.insert({x,y});
    st.insert({x,y});
    loop(i,4)
    {
        ll x2 = x, y2 = y;
        while(1)
        {
            x2+= dx[i];
            y2+= dy[i];
            if(arr[x2][y2] == '#')
                break;
            st.insert({x2,y2});
        }
        dfs(x2-dx[i],y2 - dy[i]);
    }
}

void solve()
{
    cin>>n>>m;
    arr = vector<string>(n);
    loop(i,n)
        cin>>arr[i];
    dfs();
    cout<<st.size();
}


 
int main()
{
    speed;
    //tests
        solve();

}  

