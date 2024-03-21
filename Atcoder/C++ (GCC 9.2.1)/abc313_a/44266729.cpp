#include <bits/stdc++.h>
#define loop(i, n) for(ll i = 0; i< n; i++)
#define Loop(i, n) for(ll i = 1; i< n; i++)
#define ll long long
#define fillArray(n, arr) ll arr[n]; for(ll i=0; i< n; i++) cin>>arr[i]
#define fillVector(n, arr) vector<ll> arr(n);loop(i,n)cin>>arr[i];
#define speed cin.tie(0); cin.sync_with_stdio(0)
#define tests  ll t;cin>>t;Loop(T,t+1)
#define OO 1223372036854775807//9223372036854775807
#define dotProduct(a,b) ((conj(a)*(b)).real())
#define crossProduct(a,b) ((conj(a)*b).imag())
#define rotate0(p,ang) ((p) *exp(complex<long double>(0,ang)))
#define rotate(p,ang,about) (rotate0((p - about),ang)+ about)
#define reflect0(v,m) (conj((v)/(m))*(m))
#define reflect(p,p0,p1) conj((p - p0)/(p1-p0))*(p1-p0)  + p0   // Reflect poll p1 around p0p1
const long double PI= 3.141592653589793238462643383279;
using namespace std;

ll mod =  1e9 + 13;

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
ll power(ll one, ll two)
{
    if(!two)
        return 1;
    ll temp = power(one, two/2);
    temp *= temp;
    temp %= mod;
    if(two%2)
        temp *= one;
    return temp%mod;
}

#include<bits/stdc++.h>
using namespace std;
 
// Assumed ll size
#define INT_SIZE 32
 
// A Trie Node
struct TrieNode
{
    ll value;  // Only used in leaf nodes
    TrieNode *arr[2];
};
 
// Utility function to create a Trie node
TrieNode *newNode()
{
    TrieNode *temp = new TrieNode;
    temp->value = 0;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}
 
// Inserts pre_xor to trie with given root
void insert(TrieNode *root, ll pre_xor)
{
    TrieNode *temp = root;
 
    // Start from the msb, insert all bits of
    // pre_xor llo Trie
    for (ll i=INT_SIZE-1; i>=0; i--)
    {
        // Find current bit in given prefix
        bool val = pre_xor & (1<<i);
 
        // Create a new node if needed
        if (temp->arr[val] == NULL)
            temp->arr[val] = newNode();
 
        temp = temp->arr[val];
    }
 
    // Store value at leaf node
    temp->value = pre_xor;
}
 
// Finds the maximum XOR ending with last number in
// prefix XOR 'pre_xor' and returns the XOR of this maximum
// with pre_xor which is maximum XOR ending with last element
// of pre_xor.
ll query(TrieNode *root, ll pre_xor)
{
    TrieNode *temp = root;
    for (ll i=INT_SIZE-1; i>=0; i--)
    {
        // Find current bit in given prefix
        bool val = pre_xor & (1<<i);
 
        // Traverse Trie, first look for a
        // prefix that has opposite bit
        if (temp->arr[1-val]!=NULL)
            temp = temp->arr[1-val];
 
        // If there is no prefix with opposite
        // bit, then look for same bit.
        else if (temp->arr[val] != NULL)
            temp = temp->arr[val];
    }
    return pre_xor^(temp->value);
}
 
// Returns maximum XOR value of a subarray in arr[0..n-1]
ll maxSubarrayXOR(vector<ll> & arr,  ll n)
{
    // Create a Trie and insert 0 llo it
    TrieNode *root = newNode();
    insert(root, 0);
 
    // Initialize answer and xor of current prefix
    ll result = INT_MIN, pre_xor =0;
 
    // Traverse all input array element
    for (ll i=0; i<n; i++)
    {
        // update current prefix xor and insert it llo Trie
        pre_xor = pre_xor^arr[i];
        insert(root, pre_xor);
 
        // Query for current prefix xor in Trie and update
        // result if required
        result = max(result, query(root, pre_xor));
    }
    return result;
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    loop(i,n)
        cin>>arr[i];
    ll mx = arr[0];
    for(auto x:arr)
        mx = max(mx, x);
    if(arr[0] == mx)
    {
        Loop(i,n)
        {
            if(arr[i] == mx)
            {
                cout<<1<<"\n";
                return;
            }
        }
        cout<<0<<"\n";
        return;
    }
    cout<<mx-arr[0]+1<<'\n';
}


 
int main()
{
    speed;
    //tests
        solve();

}  
