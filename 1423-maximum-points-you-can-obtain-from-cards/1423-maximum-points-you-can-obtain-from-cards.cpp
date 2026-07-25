class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum =0;
        int rsum =0;
        int rindx =cardPoints.size()-1;
        int maxsum =0;
        for(int i=0;i<=k-1;i++){
            lsum+=cardPoints[i];
        }
         maxsum = lsum;
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[rindx];
            rindx--;
            maxsum = max(maxsum,(lsum+rsum));
        }
        return maxsum;
    }
};