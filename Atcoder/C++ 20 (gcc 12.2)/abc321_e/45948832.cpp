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

ll bin(ll low, ll high, ll n,ll x, ll k)
{
    if(low > high)
        return -1;
    ll mid = (low + high+1)/2;
    bitset<64> b = mid;
    int indx = 64 -k;
    ll temp = x;
    for(int i= k-1; i>=0; i--)
    {
        temp*=2;
        if(b[i])
            temp++;
    }
    if(temp >n)
        return bin(low,mid-1,n,x,k);
    if(low == high)
        return low;
    return bin(mid,high,n,x,k);
}

void solve()
{
    ll n,x,k;
    cin>>n>>x>>k;
    ll ans = 0;
    while(x)
    {
        __int128 temp = x;
        bool good = 1;
        loop(i,k-1)
        {
            temp *= 2;
            if(temp > 1e18)
            {
                good = 0;
                break;
            }
        }
        if(good)
            ans += bin(0,((1ll<<k)-1),n,x,k)+1;
        temp = x;
        good = 1;
        loop(i,k-3)
        {
            temp *= 2;
            if(temp > 1e18)
            {
                good = 0;
                break;
            }
        }
        if(good && x>1 &&k>1)
            ans -= bin(0,((1ll<<(k-2))-1),n,x,k-2)+1;
        x/=2;
        k--;
        if(k <0)
            break;
    }
    cout<<ans<<"\n";
}



 
int main()
{
    speed;
    tests
        solve();
}  

