#include <bits/stdc++.h>
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)
#define ll long long
 
#define fillArray(n, arr) ll arr[n]; for(ll i=0; i< n; i++) cin>>arr[i]
#define fillVector(n, arr) vector<ll> arr(n);loop(i,n)cin>>arr[i];
#define speed cin.tie(0); cin.sync_with_stdio(0)
#define tests  ll t;cin>>t;Loop(T,t+1)
#define OO 8223372036854775807//9223372036854775807
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
ll len(ll x)
{
    if(!x)
        return 0;
    return 1 + len(x/10);
}

ll power(ll one, ll two)
{
    if(!two)
        return 1;
    ll temp = power(one, two/2);
    temp *= temp;
    temp %= mod;
    if(two%2)
        temp *= one%mod;
    return temp%mod;
}
ll n;
vector<vector<ll>> dp;
vector<pair<ll,ll>> arr;

ll fun(ll indx =0, bool state = 0)
{
    if(indx == n)
        return 0;
    if(dp[indx][state] != -1)
        return dp[indx][state];
    ll mx = fun(indx+1,state);
    if(!state)
        mx = max(mx ,arr[indx].second + fun(indx+1 , arr[indx].first ));
    else if(!arr[indx].first)
        mx = max(mx ,arr[indx].second + fun(indx+1 , arr[indx].first) );
    return dp[indx][state] = mx;
}

void solve()
{
    cin>>n;
    arr = vector<pair<ll,ll>>(n);
    dp = vector<vector<ll>> (n, vector<ll>(2,-1));
    loop(i,n)
        cin>>arr[i].first>>arr[i].second;
    cout<<fun();
}

int main()
{
    speed;
    //tests
    solve();
}

