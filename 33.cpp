//�� ����һ���Լ�������˼·(���ÿ��һ��Ͱ����ճ��ȥ)
//1.�������
//2.ȷ������˼·(ѡ�����ݽṹ�㷨ʲô��)   ȷ���ܽ���������,Ҳ���ÿ���̫�ิ�Ӷ�
//3.2�ﵽ֮��, ��ʼ���Ǹ��ֽ������������������   Ȼ�󿴿���û�и��Ӷȸ��͵�˼·

//���˺þ��ֿ�ʼ,  д֮ǰ�и����������˼·,û�п����������    Ȼ��ͳ������ٸ�   ����������
// 50.65%   6 ms
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

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int size=nums.size();
		if(size==0){
			return -1;
		}
		if(size==1){
			if(nums[0]==target){
				return 0;
			}else{
				return -1;
			}
		}
		//sort
        int the_end = 0;
		Use_for_quicksort* sorted_array = new Use_for_quicksort[size+10];
		for(;nums[the_end]<nums[the_end+1];++the_end);//������û����ת�����
		int i=0;
		for(int j=the_end+1;j<size;++i,++j){
			sorted_array[i].compare=nums[j];
			sorted_array[i].store_one=j;
		}
		for(int j=0;j<the_end+1;++i,++j){
			sorted_array[i].compare=nums[j];
			sorted_array[i].store_one=j;
		}
		//find_target
		int result=binary_search(sorted_array, 0, size, target);
		if(result==-1){
			return -1;
		}else{
			return sorted_array[result].store_one;
		}	
    }
};