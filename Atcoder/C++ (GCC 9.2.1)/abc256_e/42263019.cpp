#include <bits/stdc++.h>
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)
#define ll long long
 
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
ll len(ll x)
{
    if(!x)
        return 0;
    return 1 + len(x/10);
}

ll power(ll one, ll two)
{
    if(!two)
        return 1;
    ll temp = power(one, two/2);
    temp *= temp;
    temp %= mod;
    if(two%2)
        temp *= one%mod;
    return temp%mod;
}

ll mn;
ll ans = 0;
ll n;
vector<ll> arr;
vector<ll> crr;
set<ll> st;
set<ll> st2;

void dfs2(ll node, ll parent)
{
    if(node == parent)
    {
        ans += mn;
        return;
    }
    if(parent >= 2e5)
        parent -= 2e5;
    mn = min(mn, crr[node]);
    dfs2(arr[node], parent);
}
void dfs(ll node)
{
    if(st.count(node))
    {
        mn = OO;
        st.clear();
        dfs2(node,node + 2e5);
        return;
    }
    if(st2.count(node))
    {
        st.clear();
        return;
    }
    st.insert(node);
    st2.insert(node);
    dfs(arr[node]);
}


void solve()
{
    cin>>n;
    arr = vector<ll> (n);
    loop(i,n)
        cin>>arr[i];
    loop(i,n)
        arr[i]--;
    crr = vector<ll> (n);
    loop(i,n)
        cin>>crr[i];
    loop(i,n)
        dfs(i);
    cout<<ans;
}


int main()
{
    speed;
    //tests
        solve();
}

