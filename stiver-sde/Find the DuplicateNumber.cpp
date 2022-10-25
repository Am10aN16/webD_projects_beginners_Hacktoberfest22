class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        map<int,int>m;
            int ans;
        for(int i =0 ; i<arr.size();i++){
            if(m[arr[i]]==0){
                m[arr[i]]++;
            }
            else{
                ans = arr[i];
                return arr[i];