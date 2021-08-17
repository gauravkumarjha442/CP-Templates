#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
 
const long long SZ = 1e5 + 7;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
const long long MOD = 998244353;
long long opnmbr = 1;
 
#define ll                  long long
#define int                 long long int
#define ld                  long double
 
#define pll                 pair<ll, ll>
#define vi                  vector<ll>
#define mi                  map<ll, ll>
#define umi                 unordered_map<ll, ll>
 
#define sz(x)               (ll)x.size()
#define endl                "\n"
 
#define pb                  push_back
#define F                   first
#define S                   second
#define mp(x,y)             make_pair(x,y)
#define all(a)              a.begin(),a.end()
#define rall(a)             a.rbegin(),a.rend()
#define rev(a)              reverse(all(a))
#define unq(a)              a.erase(std::unique(all(a)),a.end());

#define lbd(a,x)            ll(lower_bound(all((a)),(x)) - (a).begin())
#define ubd(a,x)            ll(upper_bound(all((a)),(x)) - (a).begin())
#define decimal(x)          cout << fixed << setprecision(x)
 
#define max(a,b)            ((a > b) ? a : b)
#define min(a,b)            ((a < b) ? a : b)
 
#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define dbg(x)              cout<<#x<<"="<<(x)<<endl;
#define dbg2(x,y)           cout<<#x<<"="<<(x)<<" "<<#y<<"="<<(y)<<endl;
#define dbg3(x,y,z)         cout<<#x<<"="<<(x)<<" "<<#y<<"="<<(y)<<" "<<#z<<"="<<(z)<<endl;
#define dbg4(x,y,z,w)       cout<<#x<<"="<<(x)<<" "<<#y<<"="<<(y)<<" "<<#z<<"="<<(z)<<" "<<#w<<"="<<(w)<<endl;
 
#define IOS                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
#define fr(i,a,b)           for(ll i=a;i<b;i++)
#define rf(i,a,b)           for(ll i=a;i>=b;i--)
 
#define mem0(X)             memset((X), 0, sizeof((X)))
#define mem1(X)             memset((X), -1, sizeof((X)))
#define setbits(x)          __builtin_popcountll(x)
 
#define yes()               cout<<"YES"<<endl
#define no()                cout<<"NO"<<endl
#define err()               cout<<"===========\n";
#define errA(A)             for(auto i:A) cout<<i<<" ";cout<<"\n";
#define err1(a)             cout<<#a<<" "<<a<<"\n"
#define err2(a,b)           cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<"\n"

#define fbo               find_by_order
#define ook               order_of_key

using namespace std;
template<typename T>
using oset = __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

/*
    find_by_order() - Returns an iterator to the k-th largest element (counting from zero)
    order_of_key()  - The number of items in a set that are strictly smaller than our item
    Rest same as set
*/
 
ll power(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1) ans = (ans * a) % mod;
        b = b / 2;
        a = (a * a) % mod;
    }
    return ans;
}
 
/* GCD and LCM of two numbers */
 
ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
 
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
 
/* Prime Numbers Sieve Method */
 
const long long nod = 1000000;
vector<char> is_prime(nod+1, true);
 
vector<int> prime;
 
void sieve(){
 
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= nod; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= nod; j += i)
            is_prime[j] = false;
                     }
              }
 
     for(int i=0;i<=nod;i++)
     {
         if(is_prime[i])
           prime.push_back(i);
 
     }
 
 }
 
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

 struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;
 
    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }
 
    void init(int n) {
        data.assign(n + 1, -1);
        components = n;
    }
 
    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }
 
    int get_size(int x) {
        return -data[find(x)];
    }
 
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
 
        if (x == y)
            return false;
 
        if (-data[x] < -data[y])
            swap(x, y);
 
        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};

  void solve()
  {
      
      ciii(n,m1,m2);

      union_find uf1(n);
      union_find uf2(n);

      for(int i=0;i<m1;i++)
      {
          cii(a,b);
          a--; b--;

          uf1.unite(a,b);
      }

      for(int i=0;i<m2;i++)
      {
          cii(a,b);
          a--; b--;

          uf2.unite(a,b);
      }

      vector<pair<int , int>> ans;

      for(int a=0;a<n;a++)
      {
         for(int b=a+1;b<n;b++)
         {
              if(uf1.find(a) !=uf1.find(b) && uf2.find(a)!=uf2.find(b))
              {
                  ans.pb({a,b});

                  uf1.unite(a,b);
                  uf2.unite(a,b);
              }
         }
      }

      cout<<ans.size()<<endl;

      for(auto z : ans)
      {
          cout<<z.F+1<<" "<<z.S+1<<endl;
      }

  }

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

signed main(){

     IOS;
     #ifndef ONLINE_JUDGE
     freopen("input.txt" , "r" , stdin); freopen("output.txt" , "w" , stdout);
     #endif

    int t = 1;
    //cin >> t;
  
    for(int t1=1;t1<=t;++t1){
        //cout << "Case #" << t1 << ": ";
        solve();
        //cout << '\n';
    }
  return 0;
}