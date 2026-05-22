/* 
   Returns the leftmost index in range [l..r]
   whose value is <= required_value 
*/
class Segtree {
    public:
        vector<int> st;
        Segtree(int n) {
            st.resize(4*n, 0);
        }

       void update(int low, int high, int idx, int pos, int val) {
           if(low == high) { 
              st[idx] = val;
              return;
           }
           int mid = (low + high)>>1;
           if(pos <= mid) {
              update(low, mid, 2*idx+1, pos, val);
           } else {
              update(mid+1, high, 2*idx+2, pos, val);
           }
           st[idx] = min(st[2*idx+1], st[2*idx+2]);
       }

       int query(int low, int high, int idx, int l, int r, int val) { 
           // l..low..high..r
           if(high<l or r<low) return -1;
           if(st[idx] > val) return -1;
           if(low==high) return low;
           
           int mid = (low + high)>>1;
           int index = query(low, mid, 2*idx+1, l, r, val);
           if(index==-1) {
               index = query(mid+1, high, 2*idx+2, l, r, val);
           } 
           return index;
       }
};
