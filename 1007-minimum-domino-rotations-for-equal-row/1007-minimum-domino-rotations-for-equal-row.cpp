class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        bool top=false,bot=false;
        int n=t.size();
        int a=t[0],bi=b[0];
        int chk1=0,chk2=0;
        for(int i=0;i<n;i++){
            if(t[i]!=a){
                chk1++;
            }
            if(b[i]!=a){
                chk2++;
            }
            if(!(t[i]==a||b[i]==a)){
                top=true;
                chk1=INT_MAX,chk2=INT_MAX;
                break;
            }
        }
        int chk3=0,chk4=0;
        for(int i=0;i<n;i++){
            if(t[i]!=bi){
                chk3++;
            }
            if(b[i]!=bi){
                chk4++;
            }
            if(!(t[i]==bi || b[i]==bi)){
                bot=true;
                chk3=INT_MAX,chk4=INT_MAX;
                break;
            }
        }
        if(top&& bot){
            return -1;
        }
        else{
            int aa=min(chk1,chk2);
            int bb=min(chk3,chk4);
            return min(aa,bb);
        }
    }
};