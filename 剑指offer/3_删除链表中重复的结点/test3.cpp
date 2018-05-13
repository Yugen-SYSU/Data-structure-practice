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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        //1. 判断链表是否为空链表或只有一个结点
        if(pHead == NULL || pHead->next == NULL)return pHead;
        ListNode *tmp = pHead->next, *pre = pHead;
        //2、3. 判断链表前两个节点是否为空/相等
        while(tmp->val == pre->val)
        {
            if(tmp->next != NULL)pre = tmp->next;
            else return NULL;
            if(pre->next != NULL)tmp = pre->next;
            else return (pre->val)==(tmp->val)?NULL:pre;
            pHead = pre;
        }
        //开始删除操作
        while(tmp->next != NULL)
        {
            int label = 0;
            while(tmp->next != NULL && tmp->val == tmp->next->val)
            {
                tmp->next = tmp->next->next;
                label = 1;
            }
            tmp = tmp->next;
            if(label == 1)pre->next = tmp;
            else pre = pre->next;
            //4. 退出边界判定
            if(pre == NULL || tmp == NULL)return pHead;
        }
        return pHead;
    }
};
