class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, i = 0, j = height.size() - 1;
        while(i < j) {
            ans = max(ans, (j - i) * min(height[i], height[j]));
            
            if(height[i] < height[j]) i++;
            else j--;
        }
        return ans;
    }
};