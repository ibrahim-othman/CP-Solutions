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
void solve()
{
    ll n;
    cin>>n;
    ll N = 1e6 + 10;
    vector<bool> arr(N+100);
    vector<ll> primes;
    for(int i=2; i<=N; i++)
    {
        if(arr[i])
            continue;
        primes.push_back(i);
        for(int j =i*2; j<N; j+=i)
        {
            arr[j] = 1;
        }
    }
    primes.pop_back();
    N = primes.size();
    ll ans = 0;
    for(int i=0; i<N; i++)
    {
        ll temp1 = primes[i];
        if(temp1 > n)
            break;
        ll temp2 =temp1 * primes[i];
        if(temp2 > n)
            break;
        for(int j = i+1; j<N; j++)
        {
            ll temp3 = temp2 * primes[j];
            if(temp3 > n)
                break;
            for(int k = j+1; k<N; k++)
            {
                ll temp4 = temp3 * primes[k];
                if(temp4 > n)
                    break;
                ll temp5 = temp4 * primes[k];
                if(temp5 > n)
                    break;
                ans++;
            }
        }
    }
    cout<<ans;

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
