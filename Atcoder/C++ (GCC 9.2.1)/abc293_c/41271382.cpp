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
#define ll int
 
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
int h,w;
vector<vector<int>> arr;

int cnt = 0;

set<int> st;
void fun(int i =0,int j= 0)
{
    if(i == h-1 && j == w-1)
    {
        if(!st.count(arr[i][j]))
            cnt++;
        return;
    }
    if(st.count(arr[i][j]))
    {
        return;
    }
    st.insert(arr[i][j]);
    if(i < h-1)
        fun(i+1, j);
    if(j < w-1)
        fun(i, j+1);
    st.erase(arr[i][j]);
    
}

void solve()
{
    cin>>h>>w;
    arr = vector<vector<int>>(h);
    loop(i,h)
    {
        loop(j,w)
        {
            int temp;
            cin>>temp;
            arr[i].push_back(temp);
        }
    }
    fun();
    cout<<cnt;
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
