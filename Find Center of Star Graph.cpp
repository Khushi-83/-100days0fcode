class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        set<int> visit;
        for (auto edge: edges)
        {
            if (visit.find(edge[0]) != visit.end())
                return edge[0];
            if (visit.find(edge[1]) != visit.end())
                return edge[1];
            
            visit.insert(edge[0]);
            visit.insert(edge[1]);
        }

        return 0;
    }
};
