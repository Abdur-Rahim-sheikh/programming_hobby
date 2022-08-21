# given a 2D sorted matrix need to find the the value efficiently.
leet_code problem (details)[https://leetcode.com/problems/search-a-2d-matrix-ii/]
below code has O(max(m,n)) complexity.
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int height = matrix.size(),col=matrix[0].size()-1,row=0;
        while(row<height and col>=0){
            int val = matrix[row][col];
            if(val==target) return true;
            else if(val<target) row++;
            else col--;
        }
        return false;
    }
};
```