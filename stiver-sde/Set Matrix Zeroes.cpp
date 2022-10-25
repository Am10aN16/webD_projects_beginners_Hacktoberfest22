class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        vector<int>r;
        vector<int>c;
        int n = a.size();
        int m = a[0].size();
        for(int i =0 ; i<n ; i++){
            for(int j =0 ;j<m ; j++){
                if(a[i][j]==0){
                    r.push_back(i);
                    c.push_back(j);
                }
            }
            
        }
        for(int i =0 ; i<n ; i++){
            for(int j =0 ;j<m ; j++){
                int x = count(r.begin(),r.end(),i);
                int y = count(c.begin(),c.end(),j);
                if(x!=0 || y!=0){
                   a[i][j]=0;
                }
            }
            
        }
        
    }
};