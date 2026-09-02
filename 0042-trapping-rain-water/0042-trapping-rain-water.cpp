class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        vector<int>l(n);
        vector<int>r(n);
        int mxl= height[0];
        int mxr= height[n-1];
        int area=0;
        for(int i=0;i<n;i++){
            mxl = max(mxl,height[i]);
            l[i]=mxl;
        } 
            for(int i=n-1;i>=0;i--){
            mxr = max(mxr,height[i]);
            r[i]=mxr;
        }   
        for(int i=0;i<n;i++){
            area+=(min(l[i],r[i])-height[i]);
        }  
        return area; 
    }
};