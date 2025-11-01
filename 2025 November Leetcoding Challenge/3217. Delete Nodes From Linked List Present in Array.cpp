class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st(nums.begin(), nums.end());
        ListNode* temp = new ListNode();
        temp -> next = head;
        ListNode* curr = NULL;
        curr = temp;
        while(curr != NULL){
            ListNode* nextNode = curr -> next;
            while(nextNode != NULL && st.count(nextNode -> val)){
                nextNode = nextNode -> next;
            }
            curr -> next = nextNode;
            curr = curr -> next;
        }

        return temp -> next;
    }
};
