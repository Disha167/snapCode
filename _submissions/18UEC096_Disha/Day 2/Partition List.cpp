//The question appears confusing at first. The follow-up question to ask the interviewer is as mentioned we have to preserve the order & all the nodes greater than x should come 
//after the nodes lesser than x, so will x always be in the middle i.e. before all the nodes greater than x and after all the nodes lesser than x. Here x will be at the place
//it was, not always in the middle. Eg: for input 1->4->3->2->5->2, output will be 1->2->2->4->3->5 i.e. 3 comes after 4 preserving the relative order.
//same as sorting linkedlist with zeroes and ones, we make two lists.
//The approach to solve this using something similar to partition function of quicksort but here instead of returning the sorted linked list, we have to preserve the order. So,
//we simply maintain 2 lists, in one list keep on appending all the nodes lesser than x, and in other list keep on appending the nodes greater than or equal to x and then
//concatenate the two lists.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *lessertail=new ListNode(-1);
    ListNode *lesserhead=lessertail;
    ListNode * greatertail=new ListNode(-1);
    ListNode* greaterhead=greatertail;
    while(A)
    {
        if(A->val<B)
        {
            lessertail->next=A;
            lessertail=lessertail->next;
        }
        else if(A->val>=B)
        {
            greatertail->next=A;
            greatertail=greatertail->next;
        }
        A=A->next;
    }
    ListNode* temp= new ListNode(B);
    lessertail->next=greaterhead->next;
    greatertail->next=NULL;
    return lesserhead->next;
    
    
    
}
