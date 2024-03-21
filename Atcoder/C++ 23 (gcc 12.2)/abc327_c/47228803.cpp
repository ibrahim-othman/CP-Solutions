#include <bits/stdc++.h>
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
ll mod =  998244353;
 
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
ll gcd(ll one, ll two)
{
    if(!two)
        return one;
    return gcd(two, one%two);
}

ll lcm(ll one, ll two)
{
    ll g = gcd(one, two);
    return (one * two)/g;
}



void solve()
{
    ll n=  9;
    vector<vector<ll>> arr(n, vector<ll>(n));
    loop(i,n)
        loop(j,n)
            cin>>arr[i][j];
    loop(i,n)
    {
        set<ll> st;
        loop(j,n)
            st.insert(arr[i][j]);
        if(st.size() < n)
        {
            cout<<"No\n";
            return;
        }
        st.clear();
        loop(j,n)
            st.insert(arr[j][i]);
        if(st.size() < n)
        {
            cout<<"No\n";
            return;
        }
    }
    loop(i,3)
    {
        loop(j,3)
        {
            set<ll> st;
            loop(k,3)
            {
                loop(l,3)
                {
                    st.insert(arr[k+i*3][l+i*3]);
                }
            }
            if(st.size() <n)
            {
                cout<<"No\n";
                return;
            }
        }
    }
    cout<<"Yes\n";
}
 
int main()
{
    speed;
    //tests
    {
        solve();
    }
}
