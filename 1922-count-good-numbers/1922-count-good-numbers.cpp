class Solution {
public:
    const long long mod = 1e9 + 7;

    long long pow(long long x, long long y){
        if(y==0) return 1;
        if(y==1) return x;

        long long half = pow(x,y/2);
        long long full = (half * half) % mod;

        if(y%2==0)
            return full;
        else
            return (x * full) % mod;
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        return (pow(5,even) * pow(4,odd)) % mod;
    }
};