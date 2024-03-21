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

ll check(ll x, ll base)
{
    ll temp = x/base;
    ll ans = 0;
    while(temp)
    {
        ans += temp;
        temp /=base;
    }
    return ans;
}

ll bin(ll low, ll high, ll base, ll power)
{
    if(low == high)
        return low;
    ll mid = (low + high)/2;
    if(check(mid, base) >= power)
    {
        return bin(low, mid, base, power);
    }
    return bin(mid+1, high,base,power);
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


map<ll,ll> mp;
ll calcFact(ll x)
{
    if(x == 1)
        return 1;
    ll a;
    if(mp.count(x))
        return a = mp[x];
    
    
    for(ll i =2; i*i <= x; i++)
    {
        if(x%i == 0)
        {
            a =  calcFact(x/i) +1;

            return mp[x] = a;
        }
    }
    return mp[x] =2;
}

ll solve(ll N)
{
    ll n = N;

    ll ans = 0;
    vector<ll> arr(n+1);
    for(ll i = 1; i<=n; i++)
    {
        for(ll j = i; j<=n; j+=i )
        {
            arr[j]++;
        }
    }
    //arr[1]++;
    for(int i= 2; i<=n; i++);
        //arr[i]+=2;
    Loop(i,n)
    {
        ans += arr[i] * arr[n-i];
    }
    return ans;
}
ll solve2(ll N)
{
    ll n = N;
    ll ans =0;
    Loop(i,n)
    {
        Loop(j,n)
        {
            Loop(k,n)
            {
                Loop(l,n)
                {
                    ans += (i*j + k*l) == n;
                }
            }
        }
    }
    return ans;
}
int main()
{
    //freopen("business.in", "r", stdin);
    speed;
    //tests
    ll n;
    cin>>n;
    cout<<solve(n);
    //cout<<solve(9)<<" "<<solve2(9);
}

