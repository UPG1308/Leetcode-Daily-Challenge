class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(int i: nums) st.insert(i);
        ListNode* temp = new ListNode();
        temp -> next = head;
        ListNode* curr = temp;
        while(curr != NULL and curr -> next != NULL){
            if(st.find(curr -> next -> val) != st.end()) curr -> next = curr -> next -> next;
            else curr = curr -> next;
        }
        return temp -> next;
    }
};
