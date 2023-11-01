/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* printListReversingly(struct ListNode* head) {
	int len=0;
    int* arr=(int*)malloc(sizeof(int)*1000);
    int* p=arr;
    while (head!=NULL) {
        *p=head->val;
        head=head->next;
        p++;len++;
    }
    int* res=(int*)malloc(sizeof(int)*len);
    int* pr=res;
    for (int i=0;i<len;i++) {
    	p--;*pr=*p;pr++;
	}
    return res;
}
