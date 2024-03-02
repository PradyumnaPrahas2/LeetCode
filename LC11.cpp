class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int left=0,right=height.size()-1;
        while(left<right){
            int x=min(height[left],height[right]);
            int a2=-x*(left-right);
            area=max(area,a2);
            if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return area;
    }
};
