   
  
   
 #include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vs vector<string>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define pii pair<int,int>
#define mod1 998244353
#define mci map<char,int>
#define vpii vector<pair<int,int>>
#define vvii vector<vector<int>>
#define mod 1000000007
#define sei set<int>
#define ses set<string> 
#define ues unordered_set<string> 
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(),x.end()
#define sall(x) sort(x.begin(),x.end());
#define rall(x) sort(x.rbegin(),x.rend())
#define MAX(x) *max_element(x.begin(),x.end())
#define MIN(x) *min_element(x.begin(),x.end())
#define SUM(X) accumulate(X.begin(),X.end(),0LL)
#define FIND(x,y) binary_search(all(x),y)
#define MEM(x,y) memset(x,y,sizeof(x))
#define binone(x) __builtin_popcountll(x)
#define int long long int
#define pb push_back
#define Test int t;cin>>t;while(t--)
#define in insert
#define ff first 
#define ss second 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define revf(i,a,b) for(int i=b-1;i>=a;i--)
#define mini(a,b,c) min(a,min(b,c))
#define maxi(a,b,c) max(a,max(b,c)) 
#define rev(arr) reverse(arr.begin(),arr.end());
const int N=1e5+7;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define ret return 0
#define endl '\n' //remove for interactives

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

   
  class Segtree{
    public: 
        vector<int> st;

        Segtree(int n) {
            st.resize(4*n);
        }
        void build(vector<int> &arr, int low, int end, int index)
        { // time complexity--> O(n)

            if (low == end)
            {   

                st[index] =  arr[low];
                return;
            }

            int mid = (low + end) / 2; 

            build(arr, low, mid, 2*index+1);
            build(arr, mid + 1, end, 2*index+2);
            st[index] = st[2*index+1] + st[2*index+2];
        }

        void pointupdate(int low, int high, int index, int pos, int value)
        { // time complexity--> O(log n)

            if (low == high)
            {
                st[index] = value;
                return;
            }
            int mid = (low + high) >> 1;

            if (pos >= low and pos <= mid)
                pointupdate(low, mid, 2 * index + 1, pos, value);
            else
                pointupdate(mid + 1, high, 2 * index + 2, pos, value);

            st[index] = (st[2 * index + 1] + st[2 * index + 2])%mod;
        }

        int rangeSum(int low, int high, int index, int l, int r)
        { // time complexity--> O(log n)
            // complete overlap       l........low.........high........r
            if (low >= l and high <= r)
                return st[index];

            // disjoint
            if (l > high or r < low)
                return 0;

            int mid = (low + high) >> 1;
            int leftanswer = rangeSum(low, mid, 2 * index + 1, l, r);
            int rightanswer  = rangeSum(mid + 1, high, 2 * index + 2, l, r);
        
            return (leftanswer + rightanswer)%mod;
        } 
};


  int solve() {
    int n,ans=0;
    cin>>n;

    vi arr(n);
    cin>>arr;

    vi temp = arr;
    sall(temp);

    map<int,vi> mp;
    for(int i=n-1;i>=0;i--) {
      mp[temp[i]].pb(i);
    }
    rep(i,0,n) temp[i] = 0;

    Segtree sg = Segtree(n);
    sg.build(temp,0,n-1,0);

    for(int i=0;i<n;i++) {
      int idx = mp[arr[i]].back();
      mp[arr[i]].pop_back();

      int valuesLessOrEqual = sg.rangeSum(0,n-1,0,0,idx) + 1;
      sg.pointupdate(0,n-1,0,idx, valuesLessOrEqual); 
      ans += valuesLessOrEqual % mod;
      ans %= mod;
    }

    cout<< ans <<endl;
    
    return 0;
  } 
 
  
  
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
      int t;
      cin>>t;
      while(t--)

       solve();  

       ret;
} 