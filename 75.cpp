//�о��ܼ򵥵�����   ֱ�������ð�
//ȷʵ��ͦ�򵥵�   ����ֱ��������,���˺ö�С����  �˷���һ��ʱ��
// 3MS    26.67%
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0;
		int white = 0;
		int blue = 0;
		for(int i = 0; i < nums.size();++i){
			if(nums[i]==0){
				++red;
			}else if(nums[i]==1){
				++white;
			}else{
				++blue;
			}
		}
		int index = 0;
		for(int i = 0; i < red ;++i){     //��������   �տ�ʼû��i  ����i < red��i�õ���index
			nums[index]=0;
			++index;
		}
		for(int i = 0; i < white ;++i){    //
			nums[index]=1;
			++index;
		}
		for(int i = 0; i < blue ;++i){    //
			nums[index]=2;
			++index;
		}
		return;
    }
};