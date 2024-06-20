class Solution {
public:
    int n;
    inline bool f(int force, vector<int>& position, int m){
        int x=position[0], balls=1;
        for(int i=1; i<n && balls<=m; i++){
            if (position[i]-x>=force){
                x=position[i];
                balls++;// put 1 more ball
            }
        }
        return balls>=m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        const int I=position.back()-position[0];
        n=position.size();
        if (n==2) return I;// special case

        int minf=INT_MAX;
        for(int i=1; i<n; i++)
            minf=min(minf, position[i]-position[i-1]);
        if (n==m) return minf;// special case

        int l=minf, r=(I+m-2)/(m-1), mid, best=l;

        while (l<=r) {
            mid=l+(r - l) / 2;
            if (f(mid, position, m)) {
                best = mid; // Update best to mid
                l = mid+1; // Try for a larger distance
            } 
            else 
                r = mid-1; // Try for a smaller distance
        }
        return best;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
