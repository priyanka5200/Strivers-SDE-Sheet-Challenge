class Solution {
public:
    bool bs(vector<vector<int>>& matrix, int target, int r) {
        int m = matrix[0].size();
        int low = 0;
        int high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[r][mid] == target) {
                return true;
            } else if (matrix[r][mid] < target) {
                low = mid + 1;

            } else {
                high = mid - 1;
            }
        }
        return false;
    }
    int rowSearch(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int low = 0;
        int high = matrix.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[mid][0] <= target && matrix[mid][m - 1] >= target) {
                return mid;
            } else if (matrix[mid][0] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = rowSearch(matrix, target);
        if (row == -1)
            return false;
        return bs(matrix, target, row);
    }
};