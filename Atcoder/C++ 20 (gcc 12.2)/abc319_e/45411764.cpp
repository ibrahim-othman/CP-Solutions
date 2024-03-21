#include <bits/stdc++.h>
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)
#define ll long long
#define fillArray(n, arr) ll arr[n]; for(ll i=0; i< n; i++) cin>>arr[i]
#define fillVector(n, arr) vector<ll> arr(n);loop(i,n)cin>>arr[i];
#define speed cin.tie(0); cin.sync_with_stdio(0)
#define tests  ll t;cin>>t;Loop(T,t+1)
#define OO 9223372036854775807 //9223372036854775807
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
    ll n,x,y;
    cin>>n>>x>>y;
    n--;
    ll m = 8 * 7 * 5 * 3;
    vector<pair<ll,ll>> arr(n);
    loop(i,n)
        cin>>arr[i].first>>arr[i].second;
    
    map<ll,ll> mp;
    loop(i,m)
    {
        ll temp = x+i;
        loop(j,n)
        {
            temp += (arr[j].first - (temp%arr[j].first))%arr[j].first;
            temp += arr[j].second;
        }
        temp += y;
        mp[i] = temp - i;
    }
    ll q;
    cin>>q;
    loop(i,q)
    {
        ll temp;
        cin>>temp;
        cout<<mp[temp%m] + temp<<'\n';
    }


}



 
int main()
{
    speed;
    //tests
        solve();
}  
