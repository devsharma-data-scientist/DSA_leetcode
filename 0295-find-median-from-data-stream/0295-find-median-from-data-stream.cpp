class MedianFinder {
public:
    vector<int> v;

    MedianFinder() {}

    void addNum(int num) {
        auto it = lower_bound(v.begin(), v.end(), num);
        v.insert(it, num);
    }

    double findMedian() {
        int n = v.size();

        if (n % 2)
            return v[n / 2];

        return (v[n/2] + v[n/2 - 1]) / 2.0;
    }
};