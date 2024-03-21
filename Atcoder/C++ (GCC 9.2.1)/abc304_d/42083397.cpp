#include <bits/stdc++.h>
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)
#define ll long long
 
#define fillArray(n, arr) ll arr[n]; for(ll i=0; i< n; i++) cin>>arr[i]
#define fillVector(n, arr) vector<ll> arr(n);loop(i,n)cin>>arr[i];
#define speed cin.tie(0); cin.sync_with_stdio(0)
#define tests  ll t;cin>>t;Loop(T,t+1)
#define OO 9223372036854775807//9223372036854775807
#define dotProduct(a,b) ((conj(a)*(b)).real())
#define crossProduct(a,b) ((conj(a)*b).imag())
#define rotate0(p,ang) ((p) *exp(complex<long double>(0,ang)))
#define rotate(p,ang,about) (rotate0((p - about),ang)+ about)
#define reflect0(v,m) (conj((v)/(m))*(m))
#define reflect(p,p0,p1) conj((p - p0)/(p1-p0))*(p1-p0)  + p0   // Reflect poll p1 around p0p1
const long double PI= 3.141592653589793238462643383279;
using namespace std;
ll mod =  1073741824;
 
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


ll mult(ll one, ll two, ll m)
{
    if(!two)
        return 0;
    ll temp = mult(one, two/2,m);
    temp += temp;
    temp %= m;
    if(two%2)
        temp += one %m;
    return temp%m;
}

ll power(ll one, ll two, ll m)
{
    if(!two)
        return 1;
    ll temp = power(one, two/2,m);
    temp = mult(temp,temp,m);
    temp %= m;
    if(two%2)
        temp = mult(temp,one,m);
    return temp%m;
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    ll N;
    cin>>N;
    vector<pair<ll,ll>> arr(N);
    loop(i,N)
        cin>>arr[i].first>>arr[i].second;
    set<ll> h,v;
    ll A;
    cin>>A;
    loop(i,A)
    {
        ll temp;
        cin>>temp;
        v.insert(temp);
    }
    ll B;
    cin>>B;
    loop(i,B)
    {
        ll temp;
        cin>>temp;
        h.insert(temp);
    }
    map<pair<ll,ll>,ll> mp;
    map<ll,ll> dis1;
    ll indx = 1;
    for(auto x:v)
    {
        dis1[x] = indx;
        indx++;
    }
    map<ll,ll> dis2;
    indx = 1;
    for(auto x:h)
    {
        dis2[x] = indx;
        indx++;
    }
    for(auto x:arr)
    {
        auto it1 = v.upper_bound(x.first);
        //it1--;
        auto it2 = h.upper_bound(x.second);
        //it2--;
        mp[{dis1[*it1], dis2[*it2]}]++;
        //cout<<distance(v.begin(), it1)<<" "<<distance(h.begin(), it2)<<endl;
    }
    ll mx = 0;
    ll mn = N;
    if(mp.size() < (A+1) * (B + 1))
        mn = 0;
    for(auto x:mp)
    {
        mn = min(mn, x.second);
        mx = max(mx, x.second);
    }
    cout<<mn<<" "<<mx;
}
int main()
{
    speed;
    //tests
        solve();
}
