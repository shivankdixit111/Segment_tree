

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

bool isprime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
bool ischar(char ch)
{
    if (ch >= 'a' and ch <= 'z')
        return true;
    return false;
}
bool isdigit(char ch)
{
    if (ch >= '0' and ch <= '9')
        return true;
    return false;
}
bool vowel(char ch)
{
    if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u')
        return true;
    return false;
}
bool conso(char ch)
{
    if (!vowel(ch))
        return true;
    return false;
}
bool issort(vi &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}
 

vi findfactor(int n)
{
    vi factor;

    for (int i = 2; i <= n; i++)
    {

        while (n % i == 0)
        {
            n /= i;
            factor.pb(i);
        }
    }

    return factor;
}
vi finddivisor(int n)
{
    vi ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.pb(i);
            if (i != n / i)
            {
                ans.pb(n / i);
            }
        }
    }
    return ans;
}
int sumofdigit(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
bool ispower2(int n)
{
    if (n == 0)
        return true;
    return !(n & (n - 1));
}
bool isperfectsq(int n)
{

    int sq = sqrtl(n);
    if (sq * sq == n)
        return true;
    return false;
}
vi findprime(int n)
{
    vi prime(n + 1, 0);
    vi ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = i;
            }
        }
    }
    rep(i, 2, n + 1) if (!prime[i]) ans.pb(i);
    return ans;
}
bool isdiv(int n)
{
    if (n == 2)
        return true;
    for (int i = 2; i < (100005); i++)
    {
        if (n % i == 0)
            return true;
    }
    return false;
}
int f(int n)
{
    int x = 1;
    while (x <= n)
    {
        x *= 2;
    }
    return x;
}
int power(int x, int y)
{
    int ans = 1;
    while (y)
    {
        if (y & 1)
        {
            ans = (ans * x) ;
        }
        x = (x * x) ;
        y = y / 2;
    }
    return ans;
}
int findgcd(int a, int b)
{
    if (b == 0)
        return a;
    return findgcd(b, a % b);
}
int factorial(int n)
{
    int f = 1;
    rep(i, 1, n + 1) f *= i;
    return f;
}
bool issame(vi &a, vi &b)
{
    rep(i, 0, a.size())
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

vector<int> z_function(string s)
{   
    int n = s.size();
    vector<int> z(n);
    // cout<<s<<endl;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        // finding count of length with trivial algorithm
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        } 
    }
    return z;
}

  vector<int> manacher_odd(string s) {
    int n = s.length();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0LL, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
     }
     return vector<int>(begin(p) + 1, end(p) - 1);
   }

vector<int> search_pattern(string text, string pattern)
{
    string s = "";
    for (int i = 0; i < pattern.length(); i++)
        s += text[i];
    vector<int> ans;
    if (s == pattern)
        ans.push_back(1); // 1 based indexing
    int cnt = 0;
    int k = pattern.length();
    for (int i = pattern.length(); i < text.length(); i++)
    {
        s[cnt] = ' ';
        cnt++;
        pattern = ' ' + pattern;
        s.push_back(text[i]);
        if (s == pattern)
        {
            ans.push_back(i - k + 2);
        }
    }
    return ans;
}

vector<int> prefix_function(string s)
{   
    // Longest suffix that matches with prefix
    // lps array is used in kmp

    int n = s.length();

    vector<int> prefix(n, 0);
    int i = 0, j = 1;

    while (j < n)
    {
        if (s[i] == s[j])
        {
            i++;
            prefix[j] = i;
            j++;
        }
        else
        {
            if (i != 0)
            {
                i = prefix[i - 1];
            }
            else
            {
                j++;
            }
        }
    }
    return prefix;
}
bool ispal_arr(vi &arr, int i, int j)
{
    while (i < j)
    {
        if (arr[i] != arr[j])
            return false;
        i++;
        j--;
    }
    return true;
}

//----------------------- String Hashing --------------------------------------------//
#define MAXLEN 100010

constexpr uint64_t modd = (1ULL << 61) - 1;

const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (modd / 3) + (modd / 3);

uint64_t base_pow[MAXLEN];

int64_t modmul(uint64_t a, uint64_t b){
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t res = (l & modd) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    res = (res & modd) + (res >> 61);
    res = (res & modd) + (res >> 61);
    return res - 1;
}

void init(){
    base_pow[0] = 1;
    for (int i = 1; i < MAXLEN; i++){
        base_pow[i] = modmul(base_pow[i - 1], base);
    }
}

struct PolyHash{
    /// Remove suff vector and usage if reverse hash is not required for more speed
    vector<int64_t> pref, suff;

    PolyHash() {}

    template <typename T>
    PolyHash(const vector<T>& ar){
        if (!base_pow[0]) init();

        int n = ar.size();
        assert(n < MAXLEN);
        pref.resize(n + 3, 0);
        suff.resize(n + 3, 0);

        for (int i = 1; i <= n; i++){
            pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
            if (pref[i] >= mod) pref[i] -= mod;
        }

         for (int i = n; i >0; i--){
            suff[i] = modmul(suff[i+1], base) + ar[i - 1] + 997;
            if (suff[i] >= mod) suff[i] -= mod;
        }

    }

    PolyHash(const char* str)
        : PolyHash(vector<char> (str, str + strlen(str))) {}
   
    PolyHash(const std::string& str)
        : PolyHash(vector<char>(str.begin(), str.end())) {}

    uint64_t get_hash(int l, int r){
        int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
        return h < 0 ? h + mod : h;
    }

    uint64_t rev_hash(int l, int r){
        int64_t h = suff[l +1] - modmul(base_pow[r - l + 1], suff[r+2]);
        return h < 0 ? h + mod : h;
    }
}; 
 

//--------------------- Segment Tree ------------------------------------------------//
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

            st[index] = max(st[2 * index + 1] , st[2 * index + 2]);
        }

        int rangeMax(int low, int high, int index, int l, int r)
        { // time complexity--> O(log n)
            // complete overlap       l........low.........high........r
            if (low >= l and high <= r)
                return st[index];

            // disjoint
            if (l > high or r < low)
                return 0;

            int mid = (low + high) >> 1;
            int leftanswer = rangeMax(low, mid, 2 * index + 1, l, r);
            int rightanswer  = rangeMax(mid + 1, high, 2 * index + 2, l, r);
        
            return max(leftanswer , rightanswer);
        } 
};


int solve() {
    int n,q;
    cin>>n>>q;
    
    vi arr(n);
    cin>>arr;

    Segtree sg(n);
    sg.build(arr,0,n-1,0);
 
    while(q--) {
        int type;
        cin>>type;

        if(type==1) {
            //update
            int pos,val;
            cin>>pos>>val;
            pos--;

            sg.pointupdate(0,n-1,0,pos,val);
        } else {
            // rangesum
            int l,r;
            cin>>l>>r;
            l--; r--;

            cout<< sg.rangeMax(0,n-1,0,l,r) <<endl;
        }
    }    

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