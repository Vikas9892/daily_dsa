class Solution {
public:
int next(vector<int> &v,int k){

    int st=0,en=v.size()-1;
    while(st<=en){
        int mid=st-(st-en)/2;
        if(v[mid]==k){
            return mid;
        }
        if(v[mid]>k && (mid>0 && v[mid-1]<k)){
            return mid;
        }

        if(v[mid]>k){
            en=mid-1;
        }
        else{
            st=st+1;
        }
    }
    return 0;
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans[ans.size()-1]){
                ans.push_back(nums[i]);
            }
            if(nums[i]<ans[ans.size()-1]){
                int ind= next(ans,nums[i]);
                swap(ans[ind],nums[i]);
            }
        }
        return ans.size();
    }
};