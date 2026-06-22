class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;

        if(a > 0){
            pq.push({a,'a'});
        }
        if(b > 0){
            pq.push({b,'b'});
        }
        if(c > 0){
            pq.push({c,'c'});
        }

        string ans;

        while(!pq.empty()){
            auto p1 = pq.top();
            pq.pop();

            int n = ans.size();

            if(n >= 2 && ans[n-1] == p1.second && ans[n-2] == p1.second){
                if(pq.empty()){
                    break;
                }

                auto p2 = pq.top();
                pq.pop();

                ans.push_back(p2.second);
                p2.first--;

                if(p2.first > 0){
                    pq.push(p2);
                }

                pq.push(p1);
            }
            else{
                ans.push_back(p1.second);
                p1.first--;

                if(p1.first > 0){
                    pq.push(p1);
                }
            }
        }

        return ans;
    }
};