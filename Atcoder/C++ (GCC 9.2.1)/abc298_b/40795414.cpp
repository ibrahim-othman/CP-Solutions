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

void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> a = vector<vector<int>> (n, vector<int>(n)),a1 = vector<vector<int>> (n, vector<int>(n)),a2 = vector<vector<int>> (n, vector<int>(n)),a3 = vector<vector<int>> (n, vector<int>(n)),b = vector<vector<int>> (n, vector<int>(n));
    loop(i,n)
    {
        loop(j,n)
        {
            cin>>a[i][j];
        }
    }
    loop(i,n)
    {
        loop(j,n)
        {
            cin>>b[i][j];
        }
    }
    loop(i,n)
    {
        loop(j,n)
        {
            a1[i][j] = a[n-1-j][i];
        }
    }
    loop(i,n)
    {
        loop(j,n)
        {
            a2[i][j] = a1[n-1-j][i];
        }
    }
    loop(i,n)
    {
        loop(j,n)
        {
            a3[i][j] = a2[n-1-j][i];
        }
    }
    bool zero = 1 ,one = 1, two = 1, three = 1;
    loop(i,n)
    {
        loop(j,n)
        {
            if(a[i][j] && (!b[i][j]))
            {
                zero = 0;
            }
            if(a1[i][j] && (!b[i][j]))
            {
                two = 0;
            }
            if(a2[i][j] && (!b[i][j]))
            {
                three = 0;
            }
            if(a3[i][j] && (!b[i][j]))
            {
                one = 0;
            }
        }
    }
    if(one || two || three || zero)
    {
        cout<<"Yes\n";
    }
    else
        cout<<"No\n";
}
int main()
{
    speed;
    {
        solve();
    }
}

