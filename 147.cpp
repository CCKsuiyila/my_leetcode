//�о�Ҳ���Ǻ��ѵ�����    ͵��һ��,ֱ�������ð�
//�ܿ��ó���,����һ��С����,�ͺ�����accept��
//�ۻ�����ʵ����Ҫ��
//��������⻹��ԭ�������,û�н����ⲿ����ռ�
//49MS   58.69%
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
		if(head==NULL||head->next==NULL){
			return head;
		}
		ListNode* current = head->next;
		ListNode* head_sorted = head;
		head_sorted->next = NULL;
		for(;current!=NULL;){
			ListNode* temp = current;
			current = current->next;			//
			if(temp->val<head_sorted->val){
				temp->next = head_sorted;
				head_sorted = temp;
				continue;
			}
			ListNode* i = head_sorted;
			for(;i->next!=NULL&& i->next->val< temp->val; i = i->next);
			temp->next = i->next;
			i->next = temp;
		}
		return head_sorted;
    }
};