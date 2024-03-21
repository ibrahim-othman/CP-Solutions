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
    int n,q;
    cin>>n>>q;
    vector<set<int>> adj(n);
    int cnt =n;
    loop(i,q)
    {
        int cas;
        cin>>cas;
        if(cas == 1)
        {
            int one, two;
            cin>> one>> two;
            one--,two--;
            cnt -= (adj[one].empty());
            cnt -= (adj[two].empty());
            adj[one].insert(two);
            adj[two].insert(one);
            cout<<cnt<<'\n';
            continue;
        }
        int node;
        cin>>node;
        node--;
        if(adj[node].empty())
        {
            cout<<cnt<<"\n";
            continue;
        }
        cnt++;
        for(auto x:adj[node])
        {
            adj[x].erase(node);
            cnt += (adj[x].empty());
        }
        adj[node].clear();
        cout<<cnt<<'\n';
    }
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
