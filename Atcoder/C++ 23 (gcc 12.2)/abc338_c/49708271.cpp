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
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
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


ll fastPower(ll a, ll b) {
    if(b==0) return 1;
    ll ans = fastPower(a,b/2);
    ans=ans*ans;
    if(b&1)
        return a*ans;
    return ans;
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
void solve()
{
    map<char,ll> mp;
    string s;
    cin>>s;
    for(auto x:s)
        mp[x]++;
    ll mx = 0;
    char ans;
    for(auto x:mp)
    {
        if(x.second > mx)
            ans = x.first;
        mx = max(mx, x.second);
    }
    cout<<ans<<"\n";
}
int main()
{
    speed;
    //tests
        solve();
}


