#include<bits/stdc++.h>
using namespace std;
bool splitArray(int *input, int size,int start=0,int sum1=0,int sum2=0) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int n=size;
    if(start==n)
        return sum1==sum2;
    if(input[start]%5==0)
        sum1=sum1+input[start];
    else if(input[start]%3==0)
        sum2=sum2+input[start];
    else
        return splitArray(input,n,start+1,sum1+input[start],sum2)||splitArray(input,n,start+1,sum1,sum2+input[start]);
  return splitArray(input, n, start + 1, sum1, sum2);
}




int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}
