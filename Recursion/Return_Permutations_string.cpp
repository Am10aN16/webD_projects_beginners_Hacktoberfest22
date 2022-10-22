#include<bits/stdc++.h>
#include <string>
using namespace std;


#include <string>
using namespace std;
void swap(char &x, char &y)
{
    char temp;
    temp = x;
    x = y;
    y = temp;
}

int permutation(string s, int l, int r, string output[])
{
    int i;
    static int j = 0, count = 0;
    if (l == r)
    {
        output[j] = s;
        j++;
        count++;
    }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((s[l]), (s[i]));
            permutation(s, l + 1, r, output);
            swap((s[l]), (s[i]));
        }
    }
    return count;
}

int returnPermutations(string input, string output[]){
  

    int len = input.length() - 1;
    return permutation(input, 0, len, output);
}


int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
