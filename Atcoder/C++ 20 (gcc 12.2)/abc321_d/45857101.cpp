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

ll n,m;

ll bin(ll low, ll high, ll x, ll y , vector<ll> &brr)
{
    if(low == high)
        return low;
    ll mid = (low + high+1)/2;
    if(brr[mid] + x > y)
        return bin(low, mid-1, x,y,brr);
    return bin(mid,high,x,y,brr);
}

void solve()
{
    ll p;
    cin>>n>>m>>p;
    vector<ll> arr(n);
    vector<ll> brr(m);
    loop(i,n)
        cin>>arr[i];
    loop(i,m)
        cin>>brr[i];
    sort(brr.begin(), brr.end());
    ll ans =0;
    vector<ll> prefix(m);
    prefix[0] = brr[0];
    Loop(i,m)
        prefix[i] = brr[i] + prefix[i-1];
    for(auto x:arr)
    {
        if(x + brr[0] > p)
        {
            ans += m*p;
            continue;
        }
        ll temp = bin(0,m-1,x,p,brr);
        ans += prefix[temp];
        ans +=(temp+1)*x;
        ans += (m - temp -1)*p;
    }
    cout<<ans;
}



 
int main()
{
    speed;
    //tests
        solve();
}  

