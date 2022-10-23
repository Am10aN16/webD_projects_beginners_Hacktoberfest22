
#include <iostream>
#include <algorithm>
using namespace std;
int pairSum(int *arr, int si, int ei, int num)
{
    int numPair = 0;
    while (si < ei)
    {
        if (arr[si] + arr[ei] < num)
        {
            si++;
        }
        else if (arr[si] + arr[ei] > num)
        {
            ei--;
        }
        else
        {
            int start = arr[si];
            int last = arr[ei];
            if (start == last)
            {
                int total = (ei - si) + 1;
                numPair += (total * (total - 1) / 2);
                return numPair;
            }
            int tempStart = si + 1;
            int tempEnd = ei - 1;
            while (tempStart <= tempEnd && arr[tempStart] == start)
            {
                tempStart += 1;
            }
            while (tempEnd >= tempStart && arr[tempEnd] == last)
            {
                tempEnd -= 1;
            }
            int totalStart = (tempStart - si);
            int totalLast = (ei - tempEnd);
            numPair += (totalStart * totalLast);
            si = tempStart;
            ei = tempEnd;
        }
    }
    return numPair;
}

int tripletSum(int *arr, int n, int num)
{
    sort(arr, arr + n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int pairSumFor = num - arr[i];
        int numPairs = pairSum(arr, (i + 1), (n - 1), pairSumFor);
        count += numPairs;
    }
    return count;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;
        

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}