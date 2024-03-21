#include <iostream>
#include <string>
#include <cmath>
#include <complex>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <complex>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)
 
#define fillArray(n, arr) ll arr[n]; for(ll i=0; i< n; i++) cin>>arr[i]
#define fillVector(n, arr) vector<ll> arr(n);loop(i,n)cin>>arr[i];
#define speed cin.tie(0); cin.sync_with_stdio(0)
#define tests  ll t;cin>>t;Loop(T,t+1)
#define OO 9123372036854775807//9223372036854775807
#define dotProduct(a,b) ((conj(a)*(b)).real())
#define crossProduct(a,b) ((conj(a)*b).imag())
#define rotate0(p,ang) ((p) *exp(complex<long double>(0,ang)))
#define rotate(p,ang,about) (rotate0((p - about),ang)+ about)
#define reflect0(v,m) (conj((v)/(m))*(m))
#define reflect(p,p0,p1) conj((p - p0)/(p1-p0))*(p1-p0)  + p0   // Reflect point p1 around p0p1
const long double PI= 3.141592653589793238462643383279;
using namespace std;
 
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



ll power(ll one, ll two)
{
    if(!two)
        return 1;
    ll temp = power(one, two/2);
    temp *= temp;
    if(two%2)
        temp *= one;
    return temp;
}

vector<vector<ll>> adj;
ll n;
vector<bool> visited;
ll temp;
ll dfs(ll node)
{
    if(visited[node])
        return 0;
    temp += adj[node].size();
    visited[node] = 1;
    ll ans = 1;
    for(auto x:adj[node])
    {
        ans +=dfs(x);
    }
    return ans;
}

void solve()
{
    ll m;
    cin>>n>>m;
    adj = vector<vector<ll>>(n);
    loop(i,m)
    {
        ll one, two;
        cin>>one>>two;
        one--,two--;
        adj[one].push_back(two);
        adj[two].push_back(one);
    }
    visited = vector<bool>(n);
    loop(i,n)
    {
        if(visited[i])
            continue;
        temp = 0;
        ll temp2 = dfs(i);
        if(temp/2 != temp2)
        {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}
int main()
{
    //freopen("business.in", "r", stdin);
    speed;
    //tests
    solve();
}

