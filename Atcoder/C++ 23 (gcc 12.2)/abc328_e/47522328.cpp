#include <bits/stdc++.h>
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)
#define ll long long
 
#define fillArray(n, arr) ll arr[n]; for(ll i=0; i< n; i++) cin>>arr[i]
#define fillVector(n, arr) vector<ll> arr(n);loop(i,n)cin>>arr[i];
#define speed cin.tie(0); cin.sync_with_stdio(0)
#define tests  ll t;cin>>t;Loop(T,t+1)
#define OO 1000000100//9223372036854775807
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


vector<ll> v;
vector<ll> len;
ll parent(ll node)
{
    if(v[node] == node)
        return node;
    return v[node] = parent(v[node]);
}
 
void join(ll one , ll two)
{
    ll oneParent = parent(one);
    ll twoParent = parent(two);
    if(len[oneParent] < len[twoParent])
    {
        swap(one, two);
        swap(oneParent, twoParent);
    }
    len[oneParent] += len[twoParent];
    v[twoParent] =  oneParent;
}
 
bool find(ll one ,ll two)
{
    return parent(one) == parent(two);
}

ll ans = OO;

void fun(vector<ll> &brr,vector<vector<pair<ll,ll>>> &adj,vector<pair<pair<ll,ll>,ll>> &arr 
, ll n, ll m,ll k, ll indx=0)
{
    if(!m)
    {
        len = vector<ll>(n+1,1);
        v = vector<ll>(n+1);
        loop(i,n+1)
            v[i] = i;
        ll sum = 0;
        for(auto i:brr)
        {
            if(find(arr[i].first.first, arr[i].first.second))
                return;;
            sum += arr[i].second;
            sum %=k;
            join(arr[i].first.first, arr[i].first.second);
        }
        ans = min(ans, sum);
        return;
    }
    for(ll i = indx; i<n; i++)
    {
        brr.push_back(i);
        fun(brr,adj,arr,n,m-1,k,i+1);
        brr.pop_back();
    }
}

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ans = k;
    vector<vector<pair<ll,ll>>> adj(n);
    vector<pair<pair<ll,ll>,ll>> arr(m);
    loop(i,m)
    {
        ll one, two,w;
        cin>>one>>two>>w;
        one--,two--;
        adj[one].push_back({two,w});
        adj[two].push_back({one,w});
        arr[i] = {{min(one,two),max(one,two)},w};
    }
    vector<ll> brr;
    fun(brr,adj,arr,m,n-1,k);
    cout<<ans<<"\n";
}
 
int main()
{
    speed;
    //tests
    {
        solve();
    }
}
