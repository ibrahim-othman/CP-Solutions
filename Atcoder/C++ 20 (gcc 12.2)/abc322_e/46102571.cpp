#include <bits/stdc++.h>
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)
#define ll long long
#define dd long double
#define fillArray(n, arr) ll arr[n]; for(ll i=0; i< n; i++) cin>>arr[i]
#define fillVector(n, arr) vector<ll> arr(n);loop(i,n)cin>>arr[i];
#define speed cin.tie(0); cin.sync_with_stdio(0)
#define tests  ll t;cin>>t;Loop(T,t+1)
#define OO 1223372036854775807 //9223372036854775807
#define dotProduct(a,b) ((conj(a)*(b)).real())
#define crossProduct(a,b) ((conj(a)*b).imag())
#define rotate0(p,ang) ((p) *exp(complex<long double>(0,ang)))
#define rotate(p,ang,about) (rotate0((p - about),ang)+ about)
#define reflect0(v,m) (conj((v)/(m))*(m))
#define reflect(p,p0,p1) conj((p - p0)/(p1-p0))*(p1-p0)  + p0   // Reflect poll p1 around p0p1
const long double PI= 3.141592653589793238462643383279;
using namespace std;

ll mod =998244353;

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

ll dp(ll indx, ll n, ll k, ll p , vector<ll> &costs, vector<vector<ll>> &arr, map<pair<ll,vector<ll>>,ll> &mp, vector<ll> current)
{
    vector<ll> temp;
    for(auto x:current)
        temp.push_back(min(p,x));
    if(indx == n)
    {
        for(auto x:current)
            if(x < p)
                return OO;
        return 0;
    }
    if(mp.count({indx,temp}))
        return mp[{indx,temp}];
    ll mn = OO;
    mn = min(mn, dp(indx+1,n,k,p,costs,arr,mp,current));
    loop(i,k)
        current[i] += arr[indx][i];
    mn = min(mn, costs[indx] + dp(indx+1,n,k,p,costs,arr,mp,current));
    loop(i,k)
        current[i] -= arr[indx][i];
    return mp[{indx,temp}] = mn;
}

void solve()
{
    ll n,k,p;
    cin>>n>>k>>p;
    vector<ll> costs(n);
    vector<vector<ll>> arr(n, vector<ll>(k));
    loop(i,n)
    {
        cin>>costs[i];
        loop(j,k)
            cin>>arr[i][j];
    }
    map<pair<ll,vector<ll>>,ll> mp;
    vector<ll> temp(k);
    ll temp2 = dp(0,n,k,p,costs,arr,mp,temp);
    if(temp2 == OO)
        cout<<"-1";
    else
        cout<<temp2;
}



 
int main()
{
    speed;
    //tests
        solve();
}  

