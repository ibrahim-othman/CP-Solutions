#include <bits/stdc++.h>
#define ll long long
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)

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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
const long double PI= 3.141592653589793238462643383279;
using namespace std;
ll mod =  1e9+7;//998244353;

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
    return (one/g * two);
}


ll power(ll a, ll b) {
    if(b==0) return 1;
    ll ans = power(a,b/2);
    ans*=ans;
    ans %= mod;
    if(b&1)
        ans *= (a%mod);
    return ans%mod;
}


template<typename T>
ostream& operator<<(ostream& os,vector<T> &arr)
{
    for(auto x:arr)
        os<<x<<" ";
    os<<"\n";
    return os;
}
template<typename T>
istream& operator>>(istream& os,vector<T> &arr)
{
    for(auto &x:arr)
        os>>x;
    return os;
}

ll inv(ll x)
{
    return power(x%mod,mod-2);
}


void solve(ll t)
{
    ll n,A,B;
    cin>>n>>A>>B;
    ll N = n;
    if(A > n)
    {
        cout<<"No\n";
        return;
    }
    n-= A;
    if(B > n*(min(n,(N+1)/2)))
        cout<<"No\n";
    else
        cout<<"Yes\n";
}
int main()
{
    speed;
    tests
    solve(0);
}
