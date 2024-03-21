#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)

#define fillArray(n, arr) ll arr[n]; for(ll i=0; i< n; i++) cin>>arr[i]
#define fillVector(n, arr) vector<ll> arr(n);loop(i,n)cin>>arr[i];
#define speed cin.tie(0); cin.sync_with_stdio(0)
#define tests  ll t;cin>>t;Loop(T,t+1)
#define OO 1223372036854775807//9223372036854775807
#define dotProduct(a,b) ((conj(a)*(b)).real())
#define crossProduct(a,b) ((conj(a)*b).imag())
#define rotate0(p,ang) ((p) *exp(complex<long double>(0,ang)))
#define rotate(p,ang,about) (rotate0((p - about),ang)+ about)
#define reflect0(v,m) (conj((v)/(m))*(m))
#define reflect(p,p0,p1) conj((p - p0)/(p1-p0))*(p1-p0)  + p0   // Reflect point p1 around p0p1
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
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

ll power(ll x,ll y)
{
    if(!y)
        return 1;
    ll temp = power(x,y/2);
    if(y&1)
        return temp*x;
    return temp;
}
//-1 -1 -1 -1 -1 -1 -1 4


void solve()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    loop(i,n)
        cin>>arr[i];
    auto bin = [&](auto&& self,auto&& check ,ll low = 0, ll high = 1e16)
    {
        if(low == high)
            return low;
        ll mid = (low + high)/2;
        if(check(mid))
            return self(self,check,low,mid);
        return self(self,check,mid+1,high);
    };
    auto check = [&](ll temp)
    {
        for(auto x:arr)
        {
            temp += x;
            if(temp < 0)
                return false;
        }
        return true;
    };
    ll temp = bin(bin,check);
    for(auto x:arr)
        temp +=x;
    cout<<temp;
}
int main()
{
    speed;
    //tests
    solve();
}
