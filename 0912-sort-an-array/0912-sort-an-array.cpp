class Solution {
public:
    void merge(vector<int>& arr,int s,int e,int mid){
    int leftlength = mid-s+1;
    int rightlength = e-mid;

    int *leftarray = new  int[leftlength];
    int *rightarray = new  int[rightlength];
    int index = s;

    for(int i=0;i<leftlength;i++){
        leftarray[i] = arr[index];
        index++;
    }
    for(int i=0;i<rightlength;i++){
        rightarray[i] = arr[index];
        index++;
    }

    int i=0;
    int j=0;
    int mainIndexarray=s;

    while(i<leftlength && j<rightlength){
    if(leftarray[i]<rightarray[j]){
        arr[mainIndexarray] = leftarray[i];
        i++;
        mainIndexarray++;
    }
    else{
        arr[mainIndexarray] = rightarray[j];
        j++;
        mainIndexarray++;
        
    }
    }

    
    while(i<leftlength){
        arr[mainIndexarray] = leftarray[i];
        i++;
        mainIndexarray++;
    }
    while(j<rightlength){
        arr[mainIndexarray] = rightarray[j];
        j++;
        mainIndexarray++;       

    }    
  delete[] leftarray;
  delete[] rightarray;
}

void mergesort(vector<int>& arr,int s, int e){
    if(s>=e){
        
        return;
    }
    

    int mid = (s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);

    merge(arr,s,e,mid);
    


}

vector<int> sortArray(vector<int>& nums) {
    // int arr[] = {10,90,80,40,50,60,70,20,30};
    int s=0;
    int size = nums.size();
    int e=size-1;
    mergesort(nums,s,e);
    return nums;
}
    
};