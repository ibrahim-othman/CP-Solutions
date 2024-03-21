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

ll mod = 998244353;
 
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

vector<vector<ll>> dp;
vector<pair<ll,ll>> arr;
ll n;

ll ans =0;
ll fun(ll indx = 0,bool cas=0)
{
    if(indx == n)
        return 1;
    if(dp[indx][cas]!= -1)
        return dp[indx][cas];
    
    ll res = 0;
    if(indx)
    {
        if(!cas)
        {
            if(arr[indx-1].first == arr[indx].first )
                ;
            else
            {
                res += fun(indx+1,0);
                res %= mod;
            }
            if(arr[indx-1].first == arr[indx].second)
                ;
            else
            {
                res += fun(indx+1,1);
                res %= mod;
            }

        }
        else
        {
            if(arr[indx-1].second == arr[indx].second)
                ;
            else
            {
                res += fun(indx+1,1);
                res %= mod;
            }
            if(arr[indx-1].second == arr[indx].first )
                ;
            else
            {
                res += fun(indx+1,0);
                res %= mod;
            }
        }
    }
    else
    {
        res += fun(indx+1,0);
        res %= mod;
        res += fun(indx+1,1);
        res %= mod;
    }
    return dp[indx][cas] = res;

}

void solve()
{
    cin>>n;
    arr = vector<pair<ll,ll>> (n);
    dp = vector<vector<ll>>(n,vector<ll>(2,-1));
    loop(i,n)
        cin>>arr[i].first>>arr[i].second;
    cout<<fun();
}
int main()
{
    //freopen("business.in", "r", stdin);
    speed;
    //tests
    solve();
}

