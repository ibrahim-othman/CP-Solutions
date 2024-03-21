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

int n;
vector<int> v;
vector<int> len;
int parent(int node)
{
    if(v[node] == node)
        return node;
    return v[node] = parent(v[node]);
}
 
void join(int one , int two)
{
    int oneParent = parent(one);
    int twoParent = parent(two);
    if(len[oneParent] < len[twoParent])
    {
        swap(one, two);
        swap(oneParent, twoParent);
    }
    len[oneParent] += len[twoParent];
    v[twoParent] =  oneParent;
}
 
bool find(int one ,int two)
{
    return parent(one) == parent(two);
}
 
void solve()
{
    int m;
    cin>>n>>m;
    ll cnt = 0;
    len = vector<int>(n,1);
    v = vector<int>(n);
    loop(i,n)
        v[i] = i;
    loop(i,m)
    {
        int one, two;        
        char habal;
        cin>>one>>habal>>two>>habal;
        one--,two--;
        if(find(one, two))
            cnt++;
        else
            join(one, two);
    }
    set<int> st;
    for(auto x:v)
        st.insert(parent(x));
    cout<<cnt<<" "<<st.size() - cnt;
        
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
