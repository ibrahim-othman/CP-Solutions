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

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m,H,k;
string s;
set<pair<int,int>> st;
map<char,int> mp;
bool fun(int h,int indx =0, int x =0, int y= 0)
{
    if(h < 0)
        return 0;
    if(indx == s.size())
        return 1;
    if(indx && st.count({x,y}) && h < k)
    {
        h = k;
        st.erase({x,y});
    }
    int d = mp[s[indx]];
    return fun(h-1, indx+1, x + dx[d], y + dy[d]);
}

void solve()
{
    cin>>n>>m>>H>>k;
    cin>>s;
    loop(i,m)
    {
        int one, two;
        cin>>one>>two;
        st.insert({one,two});
    }
    if(fun(H))
        cout<<"Yes\n";
    else
        cout<<"No\n";
}
 
int main()
{
    //freopen("business.in", "r", stdin);
    speed;
    mp['U'] = 0;
    mp['D'] = 1;
    mp['R'] = 2;
    mp['L'] = 3;
    //tests
    {
        solve();
    }
    //vector<ll> brr = {2,3};

}  
