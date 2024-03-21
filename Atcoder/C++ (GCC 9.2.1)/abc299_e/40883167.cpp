#include <iostream>
#include <string>
#include <cmath>
#include <complex>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <complex>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)
#define ll long long
 
#define fillArray(n, arr) ll arr[n]; for(ll i=0; i< n; i++) cin>>arr[i]
#define speed cin.tie(0); cin.sync_with_stdio(0)
#define tests  ll t;cin>>t;Loop(T,t+1)
#define OO 9203372036854775807
#define dotProduct(a,b) ((conj(a)*(b)).real())
#define crossProduct(a,b) ((conj(a)*b).imag())
#define rotate0(p,ang) ((p) *exp(complex<double>(0,ang)))
#define rotate(p,ang,about) (rotate0((p - about),ang)+ about)
#define reflect0(v,m) (conj((v)/(m))*(m))
#define reflect(p,p0,p1) conj((p - p0)/(p1-p0))*(p1-p0)  + p0   // Reflect point p1 around p0p1
const long double pi= 3.141592653589793238462643383279;
ll mod =  998244353;
const long double eps= 1e-8;
using namespace std;


ll max(ll one, ll two)
{
    if(two > one)
        return two;
    return one;
}

ll min(ll one, ll two)
{
    if(two < one)
        return two;
    return one;
}

ll power(ll one , ll two)
{
    if(!two)
        return 1;
    ll temp = power(one, two/2);
    temp %= mod;
    temp *= temp;
    temp %= mod;
    if(two%2)
        temp *= one;
    return temp%mod;
}


int n,m;
vector<vector<int>> adj;
vector<bool> color;
void bfs(int node, int d)
{
vector<bool> visited(n);
    queue<int> qu;
    qu.push(node);
    loop(i,d)
    {
        int sz = qu.size();
        if(qu.empty())
            break;
        loop(j,sz)
        {
            int curr = qu.front();
            visited[curr] = 1;
            qu.pop();
            color[curr] = 0;
            for(auto x:adj[curr])
            {
                if(visited[x])
                    continue;
                qu.push(x);
            }
        }
    }

}
bool bfs2(int node, int d)
{
    vector<bool> visited(n);
    queue<int> qu;
    qu.push(node);
    loop(i,d)
    {
        int sz = qu.size();
        if(qu.empty())
            break;
        loop(j,sz)
        {
            int curr = qu.front();
            visited[curr] = 1;
            qu.pop();
            if(color[curr])
            {
                return 0;
            }
            for(auto x:adj[curr])
            {
                if(visited[x])
                    continue;
                qu.push(x);
            }
        }
    }
    bool flag = 0;
    while(!qu.empty())
    {
        flag = flag || color[qu.front()];
        qu.pop();
    }
    return flag;
}
void solve()
{
    cin>>n>>m;
    adj = vector<vector<int>>(n);
    color = vector<bool>(n,1);
    loop(i,m)
    {
        int one, two;        
        cin>>one>>two;
        one--,two--;
        adj[one].push_back(two);
        adj[two].push_back(one);
    }
    int k;
    cin>>k;
    map<int,int> mp;
    loop(i,k)
    {
        int p,d;        
        cin>>p>>d;
        p--;
        mp[p] = d;
        bfs(p,d);
    }
    for(auto x:mp)
    {
        if(!bfs2(x.first, x.second))
        {
            cout<<"No\n";
            return;
        }
        
    }
    cout<<"Yes\n";
    for(auto x:color)
        cout<<x;
}
int main()
{
    speed;
    {
        solve();
    }
}


