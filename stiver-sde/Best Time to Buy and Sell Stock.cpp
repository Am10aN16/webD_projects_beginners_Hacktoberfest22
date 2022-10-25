class Solution {
public:
    int maxProfit(vector<int>& p) {
//         if(prices.size()==1||prices.size()==0){
//             return 0;
//         }
//         int n = prices.size();
//         int min = 111111;
//         int maxi = 0;
//         int k = 0;
//         for(int i =0 ; i<n; i++){
//             if(prices[i]<min){
//                 k = max(maxi-min,k);
//                 min = prices[i];
//                 maxi = 0;
                
//             }
//             else if(prices[i]>maxi){
//                 maxi = prices[i];   
//             }   
//             }
        
 
//     return max(k,maxi-min);
//         int n = p.size();
//         vector<int>v(n,0);
//         v[n-1]= p[n-1];
//         for(int i =n-2;i>=0;i--){
//             v[i]= max(p[i],v[i+1]);
//         }
//         int ans =INT_MIN;
//         for(int i =0 ; i<n ; i++){
//             ans = max(ans,v[i]-p[i]);
//             // cout<<v[i]<<" ";
            
//         }
//         return ans;
        int  profit =0;
        int khareed = 10000;
        int bech = -1;
        for(int i =0 ; i<p.size();i++){
//agr koi value mere khareed se km hai to mai uspe khareedungi
            if(p[i]<khareed){
                profit = max(profit, (bech-khareed));
                khareed = p[i];
                bech =-1;
            }
//agr koi value mere bech se jada hai to mai uspe bechungi
            if(p[i]>bech){
                bech =p[i];
                profit = max(profit ,(bech-khareed));
            }
            
            
        }
        return profit;
           
    }
};