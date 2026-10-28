class Solution {
public:
    void selectionSort(vector<int>&nums){
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            int min_index = i;
            for(int j = i+1; j < n; j++){
                if(nums[j] < nums[min_index]){
                    min_index = j;
                }
            }
            swap(nums[i],nums[min_index]);
        }
    }
    void bubbleSort(vector<int>&nums){
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            bool swaped = false;
            for(int j = 0; j < n-1; j++){
                if(nums[j] > nums[j+1]){
                    swaped = true;
                    swap(nums[j],nums[j+1]);
                }
            }
            if(!swaped){
                return;
            }
        }
    }
    void insertionSort(vector<int>&nums){
        int n = nums.size();
        for(int i = 1; i < n; i++){
            int j = i-1;
            int temp = nums[i];
            while(j >= 0 && nums[j] > temp){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = temp;
        }
    }
    void merge(vector<int>&nums,int s, int mid,int e){
        int n1 = mid-s+1;
        int n2 = e-mid;
        vector<int>L1(n1);
        vector<int>L2(n2);
        for(int i = 0; i < n1; i++){
            L1[i] = nums[s+i];
        }
        for(int i = 0; i < n2; i++){
            L2[i] = nums[mid+1+i];
        }
        int i = 0, j = 0, k = s;
        while(i < n1 && j < n2){
            if(L1[i] <= L2[j]){
                nums[k++] = L1[i++];
            }
            else{
                nums[k++] = L2[j++];
            }
        }
        while(i < n1){
            nums[k++] = L1[i++];
        }
        while(j < n2){
            nums[k++] = L2[j++];
        }

    }
    void mergeSort(vector<int>&nums,int s, int e){
        if(s >= e)return;
        int mid = s+(e-s)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,mid,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        // selectionSort(nums);
        // bubbleSort(nums);
        // insertionSort(nums);
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};