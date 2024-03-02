class Solution {
public:
    void sortColors(vector<int>& nums) {
        int x,i,j;
        for (i=0;i<nums.size();i++)
        {
            for ( j=i+1;j<nums.size();j++){
                if(nums[j]<nums[i]){
                    x=nums[j];
                    nums[j]=nums[i];
                    nums[i]=x;
                }
            }
        }
    }
};
