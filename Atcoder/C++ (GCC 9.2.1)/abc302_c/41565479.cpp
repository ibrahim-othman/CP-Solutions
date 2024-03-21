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
#define OO 1000000100//9223372036854775807
#define dotProduct(a,b) ((conj(a)*(b)).real())
#define crossProduct(a,b) ((conj(a)*b).imag())
#define rotate0(p,ang) ((p) *exp(complex<long double>(0,ang)))
#define rotate(p,ang,about) (rotate0((p - about),ang)+ about)
#define reflect0(v,m) (conj((v)/(m))*(m))
#define reflect(p,p0,p1) conj((p - p0)/(p1-p0))*(p1-p0)  + p0   // Reflect point p1 around p0p1
const long double PI= 3.141592653589793238462643383279;
using namespace std;

ll mod = 1e9 + 7;

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

ll n,m;
vector<string> arr;

vector<bool> visited;
bool fun(int prev = -1,int indx = 0)
{
    if(indx == n-1)
        return  1;
    visited[prev] = 1;
    loop(i,n)
    {
        if(visited[i])
            continue;
        int cnt = 0;
        loop(j,m)
        {
            //cout<<arr[prev][j]<<' '<<arr[i][j]<<endl;
            cnt += (arr[prev][j] != arr[i][j]);
        }
        if(cnt != 1)
            continue;
        if(fun(i,indx+1))
            return 1;
    }
    visited[prev] = 0;
    return 0;
}

void solve()
{
    cin>>n>>m;
    arr = vector<string>(n);
    visited = vector<bool>(n);
    loop(i,n)
    {
        cin>>arr[i];
    }
    loop(i,n)
    {
        if(fun(i,0))
        {
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
}
 


 
int main()
{
    //freopen("business.in", "r", stdin);
    speed;
    //tests
    {
        solve();
    }
}
