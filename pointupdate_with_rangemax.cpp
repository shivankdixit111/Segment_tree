 class Segtree{
    public: 
        vector<int> st;
        int n;

        Segtree(int n) {
            st.resize(4*n);
            this->n = n;
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
            st[index] = max(st[2*index+1] , st[2*index+2]);
        }

        void update2(int low, int high, int index, int pos, int value)
        { // time complexity--> O(log n)

            if (low == high)
            {
                st[index] = value;
                return;
            }
            int mid = (low + high) >> 1;

            if (pos >= low and pos <= mid)
                update2(low, mid, 2 * index + 1, pos, value);
            else
                update2(mid + 1, high, 2 * index + 2, pos, value);

            st[index] = max(st[2 * index + 1] , st[2 * index + 2]);
        }

        int query2(int low, int high, int index, int l, int r)
        { // time complexity--> O(log n)
            // complete overlap       l........low.........high........r
            if (low >= l and high <= r)
                return st[index];

            // disjoint
            if (l > high or r < low)
                return 0;

            int mid = (low + high) >> 1;
            int leftanswer = query2(low, mid, 2 * index + 1, l, r);
            int rightanswer  = query2(mid + 1, high, 2 * index + 2, l, r);
        
            return max(leftanswer , rightanswer);
        } 
        int query(int l, int r) return query2(0,n-1,0,l,r);
        void update(int pos, int val) return update2(0,n-1,0,pos,val);
}; 
 
