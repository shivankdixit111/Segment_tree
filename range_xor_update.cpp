 

#include <bits/stdc++.h>
#pragma GCC optimize("O3") // O3 or we may time out :(
using namespace std; 
// #define SUM(X) accumulate(X.begin(), X.end(), 0LL)


#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;



// lc
#define vi vector<int>
#define vvii vector<vi>
#define vpii vector<pair<int,int>>
#define vs vector<string>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define minpq(a) priority_queue<a,vi,greater<a>> pq
#define maxpq(a) priority_queue<a> pq 
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sall(x) sort(x.begin(), x.end());
#define rall(x) sort(x.rbegin(), x.rend())
#define pb push_back 
#define in insert
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sall(x) sort(x.begin(), x.end());
#define rall(x) sort(x.rbegin(), x.rend())
#define MAX(x) *max_element(x.begin(), x.end())
#define MIN(x) *min_element(x.begin(), x.end())
#define SUM(X) accumulate(X.begin(), X.end(), 0LL)
#define rev(a) reverse(a.begin(), a.end());



template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long 
#define pii pair<int, int>
#define mod1 998244353 
#define mod 1000000007
#define sei set<int>
#define ses set<string>
#define ues unordered_set<string> 
#define MEM(x, y) memset(x, y, sizeof(x))
#define binone(x) __builtin_popcountll(x) 
const int N = 1e5 + 7;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ret return 0
#define endl '\n' // remove for interactives

// ================================== take ip/op like vector,pairs directly!==================================
template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
// ===================================END Of the input module ==========================================
 


class Segtree{
    public:
    vector<int> lazy;
    vvii st;
    
    Segtree(int n) {
        st.resize(4*n,vi(31,0));
        lazy.resize(4*n,0);
    }

    void pull(int idx) {
         rep(bit,0,31) {
            st[idx][bit] = st[2*idx+1][bit] + st[2*idx+2][bit];
         }
    }

    void build(vi &arr, int low, int high, int idx) {
         if(low==high) {
            rep(bit,0,31) {
                if((1<<bit) & arr[low]) st[idx][bit]++;
            }
            return;
         }

         int mid = (low+high)>>1;
         build(arr, low, mid, 2*idx+1);
         build(arr, mid+1, high, 2*idx+2);
         
         pull(idx);
    }

    void propogate(int low, int high, int idx, int val) {
          rep(bit,0,31) {
              if((1<<bit)&val) {
                 st[idx][bit] = (high-low+1) - st[idx][bit];   // reverses the count of bits
              }
          }
             
           if(low!=high) {
                 //propogate updation to children
                lazy[2*idx+1] ^= val;
                lazy[2*idx+2] ^= val;
          }
    }

    void rangeUpdate(int low,int high, int idx, int l, int r, int val) {
          // check if there are any pending lazy updates
          if(lazy[idx]!=0) {
             propogate(low,high,idx,lazy[idx]);
             lazy[idx] = 0;
         }
 
         // if range lies outside
         if (high<l or low>r)
          return ;

         //complete overlap
         if(low>=l and high<=r) {
             propogate(low,high,idx,val);
             return;
         }

         int mid = (low+high)>>1;
         rangeUpdate(low,mid,2*idx+1,l,r,val);
         rangeUpdate(mid+1,high,2*idx+2,l,r,val);

         pull(idx);
    }
 
    
    int query(int low,int high, int idx, int l, int r) {
         // check if there are any pending lazy updates
          if(lazy[idx]!=0) {
             propogate(low,high,idx,lazy[idx]);
             lazy[idx] = 0;
         }

         if(low>=l and high<=r) { //complete overlapping            l...low....high....r
           int ans=0;
           rep(bit,0,31) {
               ans += st[idx][bit] * (1<<bit);
           }
           return ans;
         } 
           // if range lies outside
         if (high<l or low>r)
          return 0;

         int mid = (low+high)>>1;
         int left = query(low,mid,2*idx+1,l,r);
         int right = query(mid+1,high,2*idx+2,l,r);

         return (left + right)%mod;
    }
};

int solve() {
    int n,q;
    cin>>n>>q;

    vi arr(n);
    cin>>arr;

    Segtree seg(n);
    seg.build(arr,0,n-1,0);

   
    while(q--) {
        int type;
        cin>>type;
        if(type==1) {
            //update
            int l,r,val;
            cin>>l>>r>>val;
            l--; r--; //0 based indexing
            seg.rangeUpdate(0,n-1,0,l,r,val);
        } else {
            //query sum
            int l,r;
            cin>>l>>r;
            l--; r--; //0 based indexing
            cout<< seg.query(0,n-1,0,l,r) <<endl;
        }
    }
    cout<<endl;

    ret;
}

 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    // long long t;
    // cin >> t;
    // while (t--)
 
        solve();
 
    return 0;
}