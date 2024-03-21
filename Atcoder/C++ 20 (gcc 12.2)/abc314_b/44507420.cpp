#include <bits/stdc++.h>
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)
#define ll long long
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



void solve()
{
    ll n;
    cin>>n;
    vector<set<ll>> arr(n);
    loop(i,n)
    {
        ll m;
        cin>>m;
        loop(j,m)
        {
            ll temp;
            cin>>temp;
            arr[i].insert(temp);
        }
    }
    ll x;
    cin>>x;
    ll mn = OO;
    loop(i,n)
    {
        if(arr[i].count(x))
            mn = min(mn, arr[i].size());
    }
    if(mn == OO)
    {
        cout<<"0\n";
        return;
    }
    vector<ll> ans;
    loop(i,n)
    {
        if(arr[i].count(x) && arr[i].size() == mn)
            ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(auto x:ans)
        cout<<x+1<<" ";

}


 
int main()
{
    speed;
    //tests
        solve();

}  
