class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int low =0;
        int mid =0;
        int high = n-1;
        int i =0;
        // cout<<high<<"//"<<endl;
        while(mid<=high){
           
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            
            else if( arr[mid]==2){
                swap(arr[high],arr[mid]);
                high--;
                
            }
            
            else if(arr[mid]==1){
                mid++;
            }
            // i++;
             // cout<<mid<<" //"<<endl;
        }
        
    }
};