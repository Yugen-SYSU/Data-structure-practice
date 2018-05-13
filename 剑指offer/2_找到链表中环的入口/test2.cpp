//Copyright (c) 2018 Tony Chen. All rights reserved.
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == NULL)return NULL;
        ListNode* slow = pHead;
        ListNode* fast = pHead->next;
        //enter the loop
        while(slow != NULL && fast != NULL && slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL)fast = fast->next; 
        }
        //find the length of the loop
        int len = 1;
        if(fast != NULL)fast = fast->next;
        else return NULL;
        
        while(slow != fast)
        {
            len++;
            fast = fast->next;
        }
        //find the entry of the loop
        slow = pHead;
        while(len--)slow = slow->next;
        fast = pHead;
        while(slow != NULL && fast != NULL && slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};
