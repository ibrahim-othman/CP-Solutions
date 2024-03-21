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
ll n,m;
vector<string> arr;
vector<vector<bool>> visited;
vector<vector<bool>> dp;

vector<ll> dx = {0,0,1,-1};
vector<ll> dy = {1,-1,0,0};


bool valid(ll x, ll y)
{
    return x >=0 && x < n && y>=0 && y<m;
}

string s = "snuke";
bool dfs(ll x=0, ll y =0, ll indx =0)
{
    indx%= s.size();
    if(arr[x][y] != s[indx])
        return 0;
    if(x == n-1 && y == m-1)
        return 1;
    visited[x][y] = 1;
    loop(i,4)
    {
        ll x2 = x + dx[i];
        ll y2 = y + dy[i];
        if(valid(x2,y2) && !visited[x2][y2] && dfs(x2,y2,indx+1))
            return 1;
    }
    return 0;
}

void solve()
{
    cin>>n>>m;
    arr = vector<string>(n);
    visited = vector<vector<bool>>(n, vector<bool>(m));
    loop(i,n)
        cin>>arr[i];
    if(dfs())
        cout<<"Yes";
    else
        cout<<"No";
}

 
int main()
{
    speed;
    solve();
}  
