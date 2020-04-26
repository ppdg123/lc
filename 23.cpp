#include <iostream>
#include <queue>
#include <vector>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
bool operator < (ListNode l , ListNode r) {
    return l.val > r.val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         priority_queue<ListNode> q;
         for (int i = 0;  i < lists.size(); ++i) {
	     if (lists[i] != NULL)
	         q.push(*lists[i]);
	 }
	 ListNode * cur = &head;
	 while(!q.empty()) {
	     ListNode * tmp = new ListNode(q.top().val);
	     tmp->next = q.top().next;
	     cur->next = tmp;
	     q.pop();
	     cur = cur->next;
	     if (cur->next != NULL) {
	         q.push(*(cur->next));
	     }
	 }
	 return head.next;
    }
    ListNode head;
};
int main(){
    return 0;
}
