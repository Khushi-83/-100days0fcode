class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        unordered_map<int,int> mpp;
        int x;
        for(int i=0;i<n;i++)
        {
            x=abs(arr[i]-k);
            mpp[arr[i]]=x;
        }
        int mini=INT_MAX;
        for(auto it:mpp)
        {
            mini=min(it.second,mini);
        }
        vector<int> v;
        for(auto it:mpp)
        {
            if(it.second==mini)
            {
                v.push_back(it.first);
            }
        }
        sort(v.begin(),v.end());
        return v.back();
    } 
};
