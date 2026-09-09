class Solution {
public:
    long long countCommas(long long n) {
        long long p=n;
        int cnt=0;
        while(p>0){
            p=p/10;
            cnt++;
        }
        if(cnt<=3){
            return 0;
        }
        if(cnt<=6){
            return n-999;
        }
        long long ans=0;
        int coma;
        coma=(cnt-1)/3;
        ans+=(n-pow(10,(cnt-1))+1)*coma;
        cnt--;
        while(cnt>6){
            coma=(cnt-1)/3;
            ans+=(pow(10,cnt)-pow(10,cnt-1))*coma;
            cnt--;
        }
        ans+=(pow(10,6)-1-999);
        return ans;
    }
};