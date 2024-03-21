#include <bits/stdc++.h>
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)
#define ll long long
 
#define fillArray(n, arr) ll arr[n]; for(ll i=0; i< n; i++) cin>>arr[i]
#define speed cin.tie(0); cin.sync_with_stdio(0)
#define tests  ll t;cin>>t;Loop(T,t+1)
#define OO 9223372036854775807
#define dotProduct(a,b) ((conj(a)*(b)).real())
#define crossProduct(a,b) ((conj(a)*b).imag())
#define rotate0(p,ang) ((p) *exp(complex<double>(0,ang)))
#define rotate(p,ang,about) (rotate0((p - about),ang)+ about)
#define reflect0(v,m) (conj((v)/(m))*(m))
#define reflect(p,p0,p1) conj((p - p0)/(p1-p0))*(p1-p0)  + p0   // Reflect poll p1 around p0p1
const long double pi= 3.141592653589793238462643383279;
const long double eps= 1e-8;
using namespace std;
int n,m;
int x;
vector<int> arr;
vector<int> brr;
vector<bool> dp;
vector<bool> crr;

bool fun(int indx = 0)
{
    if(indx == x)
        return 1;
    if(indx > x)
        return 0;
    if(dp[indx])
        return 0;
    

    if(crr[indx])
        return 0;
    dp[indx] = 1;
    loop(i,n)
    {
        if(fun(indx + arr[i]))
            return 1;
    }
    return 0;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<bool> arr(n+1);
    loop(i,m)
    {
        int temp;
        cin>>temp;
        arr[temp] = 1;
    }
    stack<int> st;
    Loop(i,n+1)
    {
        if(arr[i])
            st.push(i);
        else
        {
            cout<<i<<' ';
            while(st.size())
            {
                cout<<st.top()<<' ';
                st.pop();
            }
        }
    }
    while(st.size())
    {
        cout<<st.top()<<' ';
        st.pop();
    }
}

int main()
{
    speed;
    solve();
}
