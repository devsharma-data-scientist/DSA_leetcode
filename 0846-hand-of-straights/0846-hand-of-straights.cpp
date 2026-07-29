class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0) return false;
        sort(hand.begin(),hand.end());
        map<int,int> mpp;
        for(int i=0;i<hand.size();i++){
            mpp[hand[i]]++;
        }
        while(!mpp.empty()){
            int first = mpp.begin()->first;
            for(int i=0;i< groupSize;i++){
                int curr = first + i;
                if(mpp.find(curr) == mpp.end()) return false;
                mpp[curr]--;
                if(mpp[curr] == 0) mpp.erase(curr);
            }
        }
        return true;
    }
};