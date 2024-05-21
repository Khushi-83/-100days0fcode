class Solution {
    int[] printKClosest(int[] arr, int n, int k, int x) {
        // code here
        int targetIdx = floorIndexBinarySearch(arr,x);
        int res[] = new int[k];
        
        int left = targetIdx;
        int right = targetIdx+1;
        int i = 0;
        
        if(arr[targetIdx] == x){
            left = targetIdx-1;
        }
        
        while(i < k && left >= 0 && right < arr.length){
            if(x - arr[left] <  arr[right] - x) res[i++] = arr[left--];
            else res[i++] = arr[right++];
        }
        while(i < k && left >= 0) res[i++] = arr[left--];
        while(i < k && right < arr.length)res[i++] = arr[right++];
        
        
        return res;
        
    }
    private int floorIndexBinarySearch(int[] arr,int target){
        int low = 0, high = arr.length-1;
        if(arr[low] > target) return low;
        if(arr[high] < target) return high;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] <= target) low = mid+1;
            else high = mid - 1;
        }
        return high;
    }
}
