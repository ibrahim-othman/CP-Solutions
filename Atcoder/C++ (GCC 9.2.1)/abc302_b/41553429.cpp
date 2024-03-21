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

int dx[] = {0,0,-1,1,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,-1,1};

ll n,m;

bool valid(ll i, ll j)
{
    return (i >=0 && j>=0 && i<n && j<m);
}

vector<vector<char>> arr;

string s = "snuke";

stack<pair<ll,ll>> stk;
set<pair<ll,ll>> st;
int indx = 0;
bool dfs(int i,int j, int x, int y)
{
    if(!valid(i,j))
        return 0;
    if(st.count({i,j}))
        return 0;
    if(arr[i][j] != s[indx])
        return 0;
    stk.push({i,j});
    st.insert({i,j});
    indx++;
    if(indx == s.size())
    {
        return 1;
    }
        if(dfs(i+x, j+y,x,y))
            return 1;
    stk.pop();
    st.erase({i,j});
    indx--;
    return 0;
}

void solve()
{
    cin>>n>>m;
    arr = vector<vector<char>> (n);
    loop(i,n)
    {
        string temp;
        cin>>temp;
        for(auto x:temp)
            arr[i].push_back(x);
    }
    stack<pair<ll,ll>> ts;
    bool don = 0;
    loop(i,n)
    {
        loop(j,m)
        {
            loop(k,8)
            {
                indx = 0;
                don = dfs(i,j,dx[k], dy[k]);
                if(don)
                    break;
            }
                if(don)
                    break;
        }
                if(don)
                    break;
    }
    while(stk.size())
    {
        ts.push(stk.top());
        stk.pop();
    }
    while(ts.size())
    {
        cout<<ts.top().first+1<<' '<<ts.top().second+1<<"\n";
        ts.pop();
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
