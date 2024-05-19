class Solution{
public:
    int findPeakElement(vector<int>& a) 
    {
        int n=a.size();
        int highest=a[0];
        for(int i=1;i<n;i++){
            if(a[i]>highest) highest=a[i];
            else{
                break;
            }
        }
        return highest;  //TC: O(n) SC:O(1)
    }
};
