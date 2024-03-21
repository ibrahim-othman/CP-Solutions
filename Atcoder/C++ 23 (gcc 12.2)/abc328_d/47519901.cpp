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
    string s;
    cin>>s;
    ll n = s.size();
    vector<ll> arr(n);
    loop(i,n)
        arr[i] = i+1;
    vector<ll> crr(n);
    loop(i,n)
        crr[i] = i-1;
    arr[n-1] = -1;
    vector<bool> brr(n);
    for(int i =0; i!= -1&& arr[i]!= -1 &&arr[arr[i]] != -1;)
    {
        ll j = i;
        if(s[i] == 'A'&&
        s[arr[i]] =='B'&&
        s[arr[arr[i]]]=='C')
        {
            brr[i] = 1;
            brr[arr[i]] = 1;
            brr[arr[arr[i]]] = 1;
            if(arr[arr[arr[i]]]!=-1)
                crr[arr[arr[arr[i]]]] = crr[i];
            if(crr[i] > -1 && s[crr[i]]== 'A')
            {
                i = crr[i];
                arr[i] = arr[arr[arr[j]]];
            }
            else if(crr[i]>-1 && crr[crr[i]] > -1 && s[crr[crr[i]]]== 'A' && s[crr[i]]== 'B')
            {
                i = crr[crr[i]];
                arr[arr[i]] = arr[arr[arr[j]]];
            }
            else
            {
                i = arr[arr[arr[i]]];
                continue;
            }
        }
        else
            i = arr[i];
    }
    loop(i,n)
        if(brr[i])
            continue;
        else
            cout<<s[i];

}
 
int main()
{
    speed;
    //tests
    {
        solve();
    }
}
