/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int,int>>st;
        int i=0;
        ListNode* her=head;
        int n=0;
        while(her!=NULL){
            her=her->next;
            n++;
        }
        vector<int>ans(n,0);
        ListNode* temp=head;
        while(temp!=NULL){
            if(st.empty()){
                st.push({temp->val,i++});
                
            }
            else{
                if(st.top().first>=temp->val){
                    st.push({temp->val,i++});
                }
                else{
                    while(!st.empty() && temp->val > st.top().first){
                    ans[st.top().second]=temp->val;
                    st.pop();
                    }
                    st.push({temp->val,i++});
                }
            }
            temp=temp->next;
        }
        return ans;
    }
};