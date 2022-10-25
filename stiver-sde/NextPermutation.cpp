class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int  z = INT_MIN;
        for(int i =n-2 ; i>=0;i--){
            if(nums[i]<nums[i+1]){
                z = i;
                break;
            }
        }
        cout<<z<<"ll"<<endl;
        if(z !=INT_MIN){
            for(int i =n-1; i>=0;i--){
                
                if(nums[i]>nums[z]){
                    cout<<"/"<<nums[i]<<endl;
                    int temp = nums[i];
                    nums[i]= nums[z];
                    nums[z]= temp;
                    break;
                }
            }
            sort(nums.begin()+z+1, nums.end());
        }
        
        else{
            reverse(nums.begin(), nums.end());
        }
    
    }
};