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
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <complex>
#include <numeric>
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)
#define ll long long
 
#define fillArray(n, arr) ll arr[n]; for(ll i=0; i< n; i++) cin>>arr[i]
#define fillVector(n, arr) vector<ll> arr(n);loop(i,n)cin>>arr[i];
#define speed cin.tie(0); cin.sync_with_stdio(0)
#define tests  ll t;cin>>t;Loop(T,t+1)
#define OO 223372036854775807//9223372036854775807
#define dotProduct(a,b) ((conj(a)*(b)).real())
#define crossProduct(a,b) ((conj(a)*b).imag())
#define rotate0(p,ang) ((p) *exp(complex<long double>(0,ang)))
#define rotate(p,ang,about) (rotate0((p - about),ang)+ about)
#define reflect0(v,m) (conj((v)/(m))*(m))
#define reflect(p,p0,p1) conj((p - p0)/(p1-p0))*(p1-p0)  + p0   // Reflect point p1 around p0p1
const long double PI= 3.141592653589793238462643383279;
using namespace std;
 
ll min(ll one, ll two)
{
    if(one < two)
        return one;
    return two;
}
ll n,m; 
vector<vector<ll>> arr;
vector<vector<ll>> brr;
vector<vector<ll>> dp;
 
void solve()
{
    ll n, q;
    cin>>n>>q;
    set<ll> st;
    queue<ll> qu;
    Loop(i,n+1)
        qu.push(i);
    loop(i,q)
    {
        int cas;
        cin>>cas;
        if(cas == 1)
        {
            st.insert(qu.front());
            qu.pop();
        }
        else if(cas == 2)
        {
            int x;
            cin>>x;
            st.erase(x);
        }
        else
        {
            auto it = st.begin();
            cout<<*it<<"\n";
        }
    }
}

int main()
{
    speed;
    //tests
    {
        solve();
    }
}
