class Solution {
public:
void merge(vector<int>&nums,int low,int mid,int high){
    int i =low;
    int j= mid+1;
    vector<int>temp;
    while(i<=mid && j<=high){
        if(nums[i]<=nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else{
            temp.push_back(nums[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(nums[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(nums[j]);
        j++;
    }
    for(int k= low;k<=high;k++){
        nums[k]= temp[k-low];
    }
}
int countpairs(vector<int>&nums, int low,int mid,int high){
    int j= mid+1;
    int cnt=0;
    for(int i= low;i<=mid;i++){
   while(j<=high && nums[i]> 2ll* nums[j]){
   j++;
    }
    cnt+=j-(mid+1);
    }
    return cnt;
}


int mergesort(vector<int>&nums,int low, int high){
    if(low>=high) return 0;
    int mid= low+(high-low)/2;
    int cnt=0;
    cnt+=mergesort(nums,low,mid);
    cnt+=mergesort(nums,mid+1,high);
    cnt+=countpairs(nums,low,mid,high);
    merge(nums,low,mid,high);
    return cnt;
}
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergesort(nums,0,n-1);
    }
};