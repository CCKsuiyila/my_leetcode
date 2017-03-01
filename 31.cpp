//�� ����һ���Լ�������˼·(���ÿ��һ��Ͱ����ճ��ȥ)
//1. �������
//2. ȷ������˼·(ѡ�����ݽṹ�㷨ʲô��)   ȷ���ܽ���������,Ҳ���ÿ���̫�ิ�Ӷ�
//3. 2�ﵽ֮��, ��ʼ���Ǹ��ֽ������������������   Ȼ�󿴿���û�и��Ӷȸ��͵�˼·

//����ͦ�Ѷ���     ���������԰�
//����  ����˼·�Լ�û������,�����û������    
//���Ǳ��Ǹ�ʲô�����ڴ����,�ͷ��ڴ�������ס��   ����STL��swap����    Ŀǰ����֪����ɶԭ��
//��������   ���˷���һ��ʱ��    ���ܽ���   �����   ��������thu��toy������Ҫ��������
//��ʵ���������ͬ����ʱ������,��ͽ������Ѷ�
//������quicksort�ǸĹ��Ŀ��Ը�vector�õ�    �Ժ���Ҫ���Ի�����

//���⻹�в����ĵط���    û�취��



//12 ms     61.48% 
//quicksort algotithm
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

#include<algorithm>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(size == 2){
			swap(nums[0],nums[1]);
        }
        if(size!=0&&size!=1&&size!=2){
            int i=size-1;
		    for( ;i>0&&nums[i]<=nums[i-1];--i){}
			
		    if(i==0){
			    quicksort(nums,0,size);
		    }else if(i==size-1){
		        swap(nums[i],nums[i-1]);
		    }else if(i>0&&i<size-1){
		        //���cout<<i;����ɾ
				quicksort(nums,i,size);
				int k=i-1;
				for(;nums[k]>=nums[i];++i)
				cout<<i;//��Ĳ���ɾ    ����֪����ɶԭ��
				swap(nums[k],nums[i]);
			}
        }
		
    }
};