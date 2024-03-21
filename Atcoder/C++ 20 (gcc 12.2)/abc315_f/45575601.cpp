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

ll mod =  1e9 + 7;

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
ll n;
vector<pair<ll,ll>> arr;
vector<vector<dd>> dp;

dd dis(pair<ll,ll> one, pair<ll,ll> two)
{
    return sqrt((one.first - two.first)*(one.first - two.first) 
    +(one.second - two.second)*(one.second - two.second) );
}
dd fun(ll c ,ll val, ll indx)
{
    if(indx>= n-1)
        return (1ll<<c)/2;
    if(dp[indx][val] != -1)
        return dp[indx][val];
    dd mn = OO;
    loop(i,val+1)
    {
        if(i + 1 + indx >= n)
            break;
        mn = min(mn, fun(c,val-i,indx+i+1)+dis(arr[indx], arr[indx+i+1]));
    }
    return dp[indx][val] = mn;
}

void solve()
{
    cin>> n;
    arr = vector<pair<ll,ll>>(n);
    loop(i,n)
        cin>>arr[i].first>>arr[i].second;
    dd mn = OO;
    loop(i,50)
    {
        dp = vector<vector<dd>>(n, vector<dd>(i+1,-1));
        mn = min(mn, fun(i,i,0));
    }
    cout << setprecision(22);
    cout<<mn;

}



 
int main()
{
    speed;
    //tests
        solve();
}  

