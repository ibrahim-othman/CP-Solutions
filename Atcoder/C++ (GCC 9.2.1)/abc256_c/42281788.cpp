#include <bits/stdc++.h>
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)
#define ll long long
 
#define fillArray(n, arr) ll arr[n]; for(ll i=0; i< n; i++) cin>>arr[i]
#define fillVector(n, arr) vector<ll> arr(n);loop(i,n)cin>>arr[i];
#define speed cin.tie(0); cin.sync_with_stdio(0)
#define tests  ll t;cin>>t;Loop(T,t+1)
#define OO 9223372036854775807//9223372036854775807
#define dotProduct(a,b) ((conj(a)*(b)).real())
#define crossProduct(a,b) ((conj(a)*b).imag())
#define rotate0(p,ang) ((p) *exp(complex<long double>(0,ang)))
#define rotate(p,ang,about) (rotate0((p - about),ang)+ about)
#define reflect0(v,m) (conj((v)/(m))*(m))
#define reflect(p,p0,p1) conj((p - p0)/(p1-p0))*(p1-p0)  + p0   // Reflect poll p1 around p0p1
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
ll len(ll x)
{
    if(!x)
        return 0;
    return 1 + len(x/10);
}

ll power(ll one, ll two)
{
    if(!two)
        return 1;
    ll temp = power(one, two/2);
    temp *= temp;
    temp %= mod;
    if(two%2)
        temp *= one%mod;
    return temp%mod;
}

vector<ll> rows(3);
vector<ll> cols(3);
vector<ll> row(3);
vector<ll> col(3);
vector<vector<ll>> arr(3, vector<ll>(3));

ll ans =0;

void dfs(ll ij = 0)
{
    ll i = ij/2;
    ll j = ij%2;
    if(ij == 4)
    {
        
        loop(ii,2)
        {
            arr[ii][2] = (rows[ii] - row[ii]);
            if(arr[ii][2] < 1)
                return;
            col[2]+= arr[ii][2];
        }
        loop(ii,3)
        {
            arr[2][ii] = (cols[ii] - col[ii]);
            if(arr[2][ii] < 1)
                return;
        }
        ll sum =0;
        loop(ii,3)
            sum += arr[2][ii];
        if(sum == rows[2])
            ans++;
        return;
    }
    Loop(ii,30)
    {
        arr[i][j] = ii;
        row[i] += ii;
        col[j] += ii;
        dfs(ij+1);
        col[2] = 0;
        row[i] -= ii;
        col[j] -= ii;
    }

    
}


void solve()
{
    loop(i,3)
        cin>>rows[i];
    loop(i,3)
        cin>>cols[i];
    dfs();
    cout<<ans;

}


int main()
{
    speed;
    //tests
        solve();
}

