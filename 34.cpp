//�� ����һ���Լ�������˼·(���ÿ��һ��Ͱ����ճ��ȥ)
//1.�������
//2.ȷ������˼·(ѡ�����ݽṹ�㷨ʲô��)   ȷ���ܽ���������,Ҳ���ÿ���̫�ิ�Ӷ�
//3.2�ﵽ֮��, ��ʼ���Ǹ��ֽ������������������   Ȼ�󿴿���û�и��Ӷȸ��͵�˼·

//�ܿ����˼·��,�ܿ��д������   Ȼ��������   �����˰���  ������==д����=   ����   
// 5.11%   18 ms
class Use_for_quicksort{
	public:
		int compare;
		int store_one;
};

//���ֲ���
int binary_search(Use_for_quicksort *data,int low,int high
,int be_searched){
	
	for(;low<high;){
		int middle=(low+high)>>1;
		if(be_searched<data[middle].compare){
			high=middle;
		}
		else if(be_searched>data[middle].compare){
			low=middle+1;
		}
		else{
			for(;be_searched==data[middle].compare;middle=middle-1);
			middle=middle+1;
			return middle;
		}
	}
	return -1;
}

class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		int size=nums.size();
        Use_for_quicksort* sorted_array = new Use_for_quicksort[size+10];
		for(int i=0;i<size;++i){
			sorted_array[i].compare=nums[i];
		}
		int my_begin=binary_search(sorted_array, 0, size, target);
		int my_end=my_begin;
		if(my_begin==-1){
			vector<int> result;
			result.push_back(my_begin);
			result.push_back(my_end);
			return result;
		}else{
			for(;sorted_array[my_end].compare==target;++my_end);  //��������
			--my_end;
			vector<int> result;
			result.push_back(my_begin);
			result.push_back(my_end);
			
			return result;
		}
    }
};