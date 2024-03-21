#include <bits/stdc++.h>
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)
#define ll long long
 
#define fillArray(n, arr) ll arr[n]; for(ll i=0; i< n; i++) cin>>arr[i]
#define fillVector(n, arr) vector<ll> arr(n);loop(i,n)cin>>arr[i];
#define speed cin.tie(0); cin.sync_with_stdio(0)
#define tests  ll t;cin>>t;Loop(T,t+1)
#define OO 1e9+10//9223372036854775807
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
vector<ll> cost;
ll parent(ll node)
{
    if(v[node] == node)
        return node;
    return parent(v[node]);
}
ll parentCost(ll node)
{
    if(v[node]== node)
        return 0;
    return cost[node] + parentCost(v[node]);
}
 
ll find(ll smaller ,ll bigger)
{
    if(parent(smaller) != parent(bigger))
        return OO;
    return parentCost(smaller) - parentCost(bigger);
}
void join(ll one , ll two, ll d) 
{
    ll oneParent = parent(one);
    ll twoParent = parent(two);
    ll oneCost = parentCost(one);
    ll twoCost = parentCost(two);
    if(len[oneParent] < len[twoParent])
    {
        swap(one, two);
        swap(oneParent, twoParent);
        swap(oneCost, twoCost);
        d *=-1;
    }
    len[oneParent] += len[twoParent];
    v[twoParent] =  oneParent;
    cost[twoParent] = oneCost - twoCost + d;
}
 

void solve()
{
    ll n,q;
    cin>>n>>q;
    len = vector<ll>(n,1);
    v = vector<ll>(n);
    cost = vector<ll>(n,OO);
    loop(i,n)
        v[i] = i;
    vector<ll> ans;
    loop(i,q)
    {
        ll one,two,w;
        cin>>two>>one>>w;
        one--,two--;
        if(w < 0)
            swap(one,two);
        w = abs(w);
        ll temp = find(one,two);
        if(temp == OO)
            join(one,two,-w);
        else
            if(temp != w)
                continue;
        ans.push_back(i+1);

    }
    for(auto x:ans)
        cout<<x<<" ";
}
 
int main()
{
    speed;
    //tests
    {
        solve();
    }
}
