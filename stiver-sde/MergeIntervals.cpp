class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>>ans;
        vector<int>v=in[0];
        int n = in.size();
        for(int i =1 ; i<n ; i++){
            if(v[1]>=in[i][0]){
                v[1]= max(v[1],in[i][1]);
            }
            else{
                ans.push_back(v);
                v=in[i];
            }
        }
        ans.push_back(v);
       return ans; 
        
    }
};