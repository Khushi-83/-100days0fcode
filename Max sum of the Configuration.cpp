class Solution {
public:
    long long max_sum(int a[], int n) {
            long long s1 = 0;
            long long ts = 0;
            
            for (int i = 0; i < n; i++) {
                s1 += (long long)i * a[i];  
                ts += (long long)a[i];      
            }
            
            long long maxi = s1;
            
            
            for (int i = n - 1; i >= 1; i--) {
                s1 = s1 + ts - (long long)n * a[i];  
                if (maxi < s1) {
                    maxi = s1;
                }
            }
            
            return maxi;
        }
};
