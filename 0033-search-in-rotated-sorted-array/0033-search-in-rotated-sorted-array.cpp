class Solution {
public:
    int search(vector<int>& arr, int targetValue) {
        if (arr.empty()) return false;
	
        int left = 0;
        int right = arr.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Found the target
            if (arr[mid] == targetValue) {
                return mid;
            }
            
            // Determine which side is sorted
            // Left side is sorted
            if (arr[left] <= arr[mid]) {
                // Check if target is in the sorted left portion
                if (targetValue >= arr[left] && targetValue < arr[mid]) {
                    right = mid - 1;  // Search left
                } else {
                    left = mid + 1;   // Search right
                }
            }
            // Right side is sorted
            else {
                // Check if target is in the sorted right portion
                if (targetValue > arr[mid] && targetValue <= arr[right]) {
                    left = mid + 1;   // Search right
                } else {
                    right = mid - 1;  // Search left
                }
            }
        }
        
        return -1;
    }
};