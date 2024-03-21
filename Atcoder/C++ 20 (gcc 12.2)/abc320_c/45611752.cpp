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

void solve()
{
    ll n = 3;
    ll m;
    cin>>m;
    vector<string>arr(n);
    vector<set<char>> sts(n);
    loop(i,n)
    {
        cin>>arr[i];
        loop(j,m)
            sts[i].insert(arr[i][j]);
    }
    ll ans = OO;
    vector<ll> brr = {0,1,2};

    do
    {
        loop(i,10)
        {
            bool bad = 0;
            loop(j,n)
                if(!sts[j].count(i+'0'))
                    bad = 1;
            if(bad)
                continue;
            ll indx = 0;
            ll temp = 0;
            loop(j,3)
            {
                while(arr[brr[j]][indx] != i + '0')
                {
                    indx++;
                    temp++;
                    indx %= m;
                }
                indx++;
                temp++;
                indx %= m;
            }
            if(indx == m)
                continue;
            ans = min(ans, temp-1);
        }
    }
    while(next_permutation(brr.begin(), brr.end()));
    if(ans == OO)
        cout<<"-1\n";
    else
        cout<<ans;
}



 
int main()
{
    speed;
    //tests
        solve();
}  

