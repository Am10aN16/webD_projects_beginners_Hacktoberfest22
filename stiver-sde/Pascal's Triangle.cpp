class Solution {
public:
    vector<vector<int>> generate(int n) {
      vector<vector<int>>m; 
        vector<int>v1 ={1};
        vector<int>v2 = {1,1};
        if(n==1){
            m.push_back(v1);
            return m;
        }
        if(n==2){
            m.push_back(v1);
            m.push_back(v2);
            return m;
        }
        m.push_back(v1);
        m.push_back(v2);
        
        while(m.size()<n){
            vector<int>v;
            v.push_back(1);
            int z = m.size();
            vector<int>h = m[z-1];
            for(int i =1 ; i<h.size();i++){
                int a = h[i]+h[i-1];
                v.push_back(a);
            }
            v.push_back(1);
            m.push_back(v);
        }
        return m;
    }
};