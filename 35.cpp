//�� ����һ���Լ�������˼·(���ÿ��һ��Ͱ����ճ��ȥ)
//1.�������
//2.ȷ������˼·(ѡ�����ݽṹ�㷨ʲô��)   ȷ���ܽ���������,Ҳ���ÿ���̫�ิ�Ӷ�
//3.2�ﵽ֮��, ��ʼ���Ǹ��ֽ������������������   Ȼ�󿴿���û�и��Ӷȸ��͵�˼·

//���˼·�ܼ�   ���Ǹı�һ�¶��ֲ���,�ܹ�����Ҳ��������   ��������������з�����һ��С覴�   ���˾ͺ���
//46.58%    6 ms
class Use_for_quicksort{
	public:
		int compare;
		int store_one;
};

//���ֲ���
int binary_search(Use_for_quicksort *data,int low,int high
,int be_searched){
	int high_sign = high;
	for(;low<high;){
		int middle=(low+high)>>1;
		if(be_searched<data[middle].compare){
			high=middle;
		}
		else if(be_searched>data[middle].compare){
			low=middle+1;
		}
		else{
			return middle;
		}
	}
	if(low==high_sign){       //��������
		return high_sign;
	}else{
		if(be_searched<data[low].compare){
			return low;
		}else{
			return low+1;
		}
	}
}

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size=nums.size();
        Use_for_quicksort* sorted_array = new Use_for_quicksort[size+10];
		for(int i=0;i<size;++i){
			sorted_array[i].compare=nums[i];
		}
		int result=binary_search(sorted_array, 0, size, target);
		return result;
    }
};
