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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* curr = head -> next;
        ListNode* headNode = NULL;
        ListNode* nextNode = NULL;
        bool headNodeFound = 0;
        while(curr != nullptr){
            int sum = 0;
            while(curr != nullptr && curr -> val != 0){
                sum += curr -> val;
                curr = curr -> next;
            }
            if(!headNodeFound){
                headNode = new ListNode(sum);
                nextNode = headNode;
                headNodeFound = true;
            }
            else{
                nextNode -> next = new ListNode(sum);
                nextNode = nextNode -> next;
            }
            curr = curr -> next;
        }
        return headNode;
    }
};
