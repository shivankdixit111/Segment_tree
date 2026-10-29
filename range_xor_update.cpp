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
