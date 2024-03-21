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
    int x; 
    cin>>x;
    int n;
    cin>>n;
    map<int,multiset<int>> box;
    map<int,set<int>> card;
    loop(i,n)
    {
        int cas;
        cin>>cas;
        if(cas == 1)
        {
            int car, bo;            
            cin>>car>>bo;
            box[bo].insert(car);
            card[car].insert(bo);

        }
        else if(cas == 2)
        {
            int bo;
            cin>>bo;
            for(auto x:box[bo])
                cout<<x<<" ";
            cout<<"\n";
        }
        else
        {
            int car;
            cin>>car;
            for(auto x:card[car])
                cout<<x<<" ";
            cout<<"\n";
        }
    }
}
int main()
{
    speed;
    {
        solve();
    }
}

