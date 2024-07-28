#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int maxArea(vector<int>& height) {
        // int m = height.size();
        // int ret = 0;
        // for(int i = 0 ; i < m ; i++ )
        // {
        //     for(int j = 0 ; j < m ; j++)
        //     {
        //         ret =max(ret,min(height[i],height[j])*(j-i)) ;
        //     }
        // }
        // return ret;
        int last = height.size() - 1;
        int first = 0;
        int ret = 0;
        while (first <= last)
        {
            ret = max(ret, min(height[first], height[last]) * (last - first));
            if (height[last] >= height[first])
            {
                first++;
            }
            else
            {
                last--;
            }
        }
        return ret;
    }
};