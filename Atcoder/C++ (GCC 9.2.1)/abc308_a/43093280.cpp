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

struct Fraction {
    ll num, den, indx;
};
 
// Get max of the two fractions
bool maxFraction(Fraction first, Fraction sec)
{
     
    ll a = first.num;
    ll b = first.den;
    ll c = sec.num;
    ll d = sec.den;
 
    // Compute ad-bc
    ll Y = a * d - b * c;
 
    if(Y > 0)
        return 1;
    if(Y < 0)
        return 0;
    return first.indx < sec.indx;
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    vector<ll> brr(n);
    loop(i,n)
    {
        cin>>arr[i];
        cin>>brr[i];
    }
    
    vector<Fraction> crr(n);
    loop(i,n)
    {
        crr[i].num  = arr[i];
        crr[i].den  = arr[i] + brr[i];
        crr[i].indx  = i;
    }
    sort(crr.begin(), crr.end(), maxFraction);
    for(auto x:crr)
        cout<<x.indx+1<<" ";

}

 
int main()
{
    speed;
        solve();
    return 0;
    Fraction one ,two;
    cin>>one.num>>one.den;
    cin>>two.num>>two.den;
    one.den += one.num;
    two.den += two.num;
    one.indx = 0;
    two.indx = 0;
    cout<<maxFraction(one,two);

}  
