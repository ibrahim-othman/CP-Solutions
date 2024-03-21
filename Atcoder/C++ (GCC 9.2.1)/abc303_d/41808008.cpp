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
#define reflect(p,p0,p1) conj((p - p0)/(p1-p0))*(p1-p0)  + p0   // Reflect point p1 around p0p1
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

vector<vector<ll>> dp;
vector<pair<ll,bool>> arr;
ll x,y,z;
ll n;

ll fun(ll indx = 0, ll cas = 0)
{
    bool sav = cas;
    if(indx == n)
        return 0;
    if(dp[indx][cas] != -1)
        return dp[indx][cas];
    ll mn =OO;
    ll temp =(x) * arr[indx].first;
         
    if(cas != arr[indx].second)
        temp = y* arr[indx].first;
    mn = min(mn, fun(indx+1,cas) + temp);
    

    ll temp2 = z;
    cas = (!cas);
    temp2 +=(x) * arr[indx].first;
    if(cas != arr[indx].second)
        temp2 =z+ y* arr[indx].first;

    mn = min(mn, fun(indx+1,cas) + temp2);
    return dp[indx][sav] = mn;
}

void solve()
{
    string s;
    cin>>x>>y>>z>>s;
    char temp = 'a';
    ll cnt = 0;
    for(auto x:s)
    {
        if(temp !=x)
        {
            arr.push_back({cnt,temp != 'a'});
            cnt = 0;
            temp = x;
        }
        cnt++;
    }
    arr.push_back({cnt, temp != 'a'});
    n = arr.size();
    dp = vector<vector<ll>> (n, vector<ll>(2,-1));
    cout<<fun();
}
 
int main()
{
    //freopen("business.in", "r", stdin);
    speed;
    //tests
    {
        solve();
    }
    //vector<ll> brr = {2,3};

}  
