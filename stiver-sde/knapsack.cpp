#include<bits/stdc++.h>
using namespace std;
int moreoptimise(vector<int>weight,vector<int>value,int n,int capacity){
    vector<int>curr(capacity+1,0);
    for(int i=weight[0];i<=capacity;i++){
         if(weight[0]<=capacity){
            curr[i]=value[0];
        }else{
            curr[i]=0;
        }
    }for(int index=1;index<n;index++){
       for(int w=capacity;w>=0;w--){
        int include=0;
        if(weight[index]<=w){
        include=value[index]+curr[w-weight[index]];
    }
        int exclude=curr[w];
    int ans=max(include,exclude);
    curr[w]=ans;
       }
    }return curr[capacity];
}
int main(){
vector<int>weight={1,2,4,5};
vector<int>value={5,4,8,6};
int capacity=5;
cout<<moreoptimise(weight,value,3,capacity);
return 0;
}