class Solution {
public:
    int find_reversed_pairs(vector<int>& nums,int& left,int& right){
        int res = 0,mid = left + (right-left)/2;
        int i = left,j = mid+1;
        for(;i <= mid;i++){
            while(j <= right && (long)nums[i] > 2*(long)nums[j]) {
                res += mid - i + 1;
                j++;
            }
        }
        return res;
    }

    int merge_sort(vector<int>& a, int tmp[], int l, int r){
        if(l >= r) return 0;
        
        int mid = (l + r)>> 1;

        int res = merge_sort(a,tmp,l,mid) + 
                  merge_sort(a,tmp,mid+1,r) + 
                  find_reversed_pairs(a,l,r);
        
        int k = 0, i = l, j = mid + 1;
        while(i <= mid && j <= r){
            if(a[i] <= a[j]) tmp[k++] = a[i++];
            else tmp[k++] = a[j++];
        }
        
        while(i <= mid) tmp[k++] = a[i++];
        while(j <= r) tmp[k++] = a[j++];

        for(int i = l, j = 0; i <= r; i++, j++)
            a[i] = tmp[j];

        return res;
    }


    int reversePairs(vector<int>& nums) {
        if(nums.empty()) return 0;

        int tmp[nums.size()];
        memset(tmp,0,sizeof(tmp));

        return merge_sort(nums,tmp,0,nums.size()-1);
    }
};