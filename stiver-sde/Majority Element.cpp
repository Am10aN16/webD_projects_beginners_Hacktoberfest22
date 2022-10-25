class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int count =0;
        int ele = nums[0];
        int i =0;
        int n = nums.size();
        while(i<n){
            if(count==0){
                ele = nums[i];
                count++;
                i++;
            }
            else{
                if(nums[i]==ele){
                    count++;
                    i++;
                }
                else if(nums[i]!=ele){
                    count--;
                    i++;
                }
            }
        }
          return ele;
     
    }
     
};