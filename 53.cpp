//һ���ܹؼ�����ʶ   һ��Ҫ�ͱ�������   ����������ʵ��û������
//�����������������,�ͻᷢ�ֱ��˵�˼·   �����˵�˼·Ҳ������΢��˼�뽻����
//��ʱ��leetcode�ľ޴����ƾͷ��ӳ�����   

//����   ���ͻ�÷¡��ѧ��Jay Kadane
//���Ｔʹ���ս���Ǹ���Ҳ���Խ��
//(������ս���Ǹ���,˵��ÿ��Ԫ�ض��Ǹ���,��ôֻ��Ҫ�ҳ��Ǹ����ĸ����ͺ���)

//�����Ǹ������Ĵ����������,Ī������������
// 9 MS   57.56%
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int length = nums.size();
		long long int sum = 0;
		long long int max_sum = -10000000000000;
		for(int i = 0; i<length; ++i){
			sum += nums[i];
			if(sum>max_sum){
				max_sum = sum;
			}
			if(sum<=0){
				sum = 0;
			}
		}
		return max_sum;
    }
};


/*
//����⺮�ٵ�ʱ����������,�������������  ��ʱ���õ�������Ӷ�ΪN^2��˼·
//����������������ô����ʱ��,���ָ��Ӷ�ΪN^2,N^3�Ķ����Ǳ����ƽ���
//���˻��и��Ӷ�ΪN(logN)�ĺ�N��;
//������Ӷ�ΪN^2,���һ������ûͨ��
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int length = nums.size();
		if(length == 0){
			return 0;
		}
		if(length == 1){
			return nums[0];
		}
		int sum = 0;
		int max_sum = -100000000;
        int* sum_array = new int[length+10];
		for(int i = 0; i<length; ++i){
			sum += nums[i];
			sum_array[i] = sum;
			if(sum>max_sum){
				max_sum = sum;
			}
		}
		for(int i = 0; i<length-1; ++i){
			for(int j = i+1; j<length; ++j){
				if(sum_array[j] - sum_array[i]>max_sum){
					max_sum = sum_array[j] - sum_array[i];
				}
			}
		}
		return max_sum;
    }
};
*/