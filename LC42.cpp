class Solution {
public:
    int trap(vector<int>& height) {
        int left[height.size()],right[height.size()],combined[height.size()];
        int final[height.size()];
        int max=0,max2=0;
        for(int i=0;i<height.size();i++){
            if(height[i]>max){
                max=height[i];
            }
            left[i]=max;
        }
        int j=height.size()-1;
        for(int i=height.size()-1;i>=0;i--){
            right[j]=max2;
            j--;
            if(height[i]>max2){
                max2=height[i];
            }
        }
        for(int i=0;i<height.size();i++){
            combined[i]=min(right[i],left[i]);
        }
        int sum=0;
        for(int i=0;i<height.size();i++){
            if(combined[i]-height[i]>=0){
                final[i]=combined[i]-height[i];
            }
            else{
                final[i]=0;
            }
        }
        for(int i=0;i<height.size();i++){
            sum+=final[i];
        }
        return sum;
    }
};
