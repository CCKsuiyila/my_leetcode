//��Ҫ�ĸ��Ӷ�ֻ�п�������͹鲢�����������
//����������ֶ����,���ǵ��б��û���
//ֱ���б�����,Ȼ��������ٻ��б�����

//�ܿ��д����(��vector���������Ļ�����)  Ȼ��Ȼһ��ͨ��,�﷨����û��
//������Ӧ���������װ�   ��Ȼû��д�б��Ŀ�������

//Ȼ���ǽ���  ���������ı�׼����Ӧ���ǹ鲢����(�б��ÿ���������ܻᳬʱ)
//�����ʱ���ù鲢��ռ�ý϶�Ŀռ�,�����б��ʱ����,ֻ��Ҫ����������ռ�.

//�п�һ��Ҫ�Լ����б�Ĺ鲢����дһд.
// 42MS   99.91%
int quicksort(vector<int>& data,int low,int high){
	int partition(vector<int>& data,int low,int high);
	if ((high-low)<1){
		return 0;
	}
	
	int middle=partition(data,low,high-1);
	quicksort(data,low,middle);
	quicksort(data,middle+1,high);
	return 0;
}

int partition(vector<int>& data,int low,int high){
	int backup_low=low;
	int backup_high=high;
	int middle_data=data[low];
	for(;low<high;){
		for(;low<high;){
			if(data[high]>middle_data){
				high=high-1;
			}else{
				data[low]=data[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(data[low]<middle_data){
				low=low+1;
			}else{
				data[high]=data[low];
				high=high-1;
				break;
			}
		}
	}
	int middle=low;
	data[low]=middle_data;
	low=backup_low;
	high=backup_high;
	return middle;
}
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
    ListNode* sortList(ListNode* head) {
		vector<int> data;
		for(ListNode* i = head; i!=NULL; i = i->next){
			data.push_back(i->val);
		}
        quicksort(data,0,data.size());
		int count = 0;
		for(ListNode* i = head; i!=NULL; i = i->next){
			i->val = data[count];
			++count;
		}
		return head;
    }
};