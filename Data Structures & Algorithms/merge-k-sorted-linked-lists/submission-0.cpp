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
struct CompareNode{
    bool operator()(ListNode* const& p1, ListNode* const &p2){
        return p1->val > p2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*>, CompareNode> minHeap;

        for(ListNode* node : lists){
            if(node != nullptr){
                minHeap.push(node);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(!minHeap.empty()){
            ListNode* minNode = minHeap.top();
            minHeap.pop();

            curr->next = minNode;
            curr = curr->next;

            if(minNode->next != nullptr){
                minHeap.push(minNode->next);
            } 
        }

        ListNode* resultHead = dummy->next;
        delete dummy;

        return resultHead;
    }
};
