//����������������Ļ�,�϶��ﲻ������ʱ��,   ����Ӧ����ʲô����ķ���
//������ʱ�벻��,�����������Լ��������㷨(�����ǳ�ʱ������)

//���Ǻ�����,��Ȼһ��accept��    ��������quicksort,�⻹������ʱ����
//�ѵ��������Ҫ����������,���������Ļ���Ҫ����ռ䰡     ����һ�°�
//���������Ҫ��Ͱ����   ������Ҫ��������ʱ��,�ռ临�Ӷ�   �����Ļ�����ʵ��������Ҳ���ڿ�����
//���������Բ�����Ȼ��ʲô����˵���,�ѵ��������Լ�ȥ����?  

//����ͨ���˾�������Ͱ������   �´ΰ�
//����,ͻȻ������Ŀ�����кܶవʾ��(�Ǹ�����,int��,����ʱ��ռ�)    ���Լ�̫�Բ���
//������Ϊɶ�ǵ����ҹ���     �����ҹ�����������

//
// 6MS  76.14%
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

class Solution {
public:
    int maximumGap(vector<int>& nums) {
		if(nums.size()<2){
			return 0;
		}
        quicksort(nums,0,nums.size());
		int result = 0;
		for(int i =0; i<nums.size()-1; ++i){
			if(abs(nums[i+1]-nums[i])>result){
				result = abs(nums[i+1]-nums[i]);
			}
		}
		return result;
    }
};