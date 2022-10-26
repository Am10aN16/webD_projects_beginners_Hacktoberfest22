//Sorting 0s 1s and 2s using DNF(Dutch National Flag Algorithm)
//Code:-
void sort012(int *arr, int n)
{
   int low=0;
    int mid=0;
    int high=n-1;
    
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else if(arr[mid]==2){
                swap(arr[mid],arr[high]);
                high--;
            }
        }
 }
//This code will sort 0s 1s and 2s given in input as any random order
