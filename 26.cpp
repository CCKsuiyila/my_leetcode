/*
//���ò��²�����Ŀ,�о�����˵�����   ����Ҳ�е�ԭ������ΪӢ�ﲻ��ĸ���
//�տ�ʼ��ΪֻҪ��length�ͺ���  ���...  ��֪���˼�������Ҫ�ı������.
//Ȼ��˼��һ��  �ܿ��и��뷨    �����Ǻ�ȷ��   ��д��ȥ���Կ�   
//Ȼ����������   ��һ������nums[i] = -100;  �ڶ�����0�ĳ���-100  Ȼ��͹���
//������˵,����ⲻ��   ���������˫ָ������   ���ӶȲ�����n��ƽ����(ǰ���ϵ����С��1��)

// 29 ms    51.00%
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 0){
			return 0;
		}
		int temporary = nums[0];
		int length = size;
		int null_index=0;
		for(int i = 1; i<size; ++i){
			if(nums[i]==temporary){
				length = length-1;
				nums[i] = -100;
			}else{
				temporary = nums[i];
				for(int j = null_index;j<i;++j){
				    if(nums[j]==-100){
				        nums[j]=nums[i];
						nums[i] = -100;
				        null_index = j+1;
				        break;
				    }
				}
			}
		}
		return length;
    }
};
*/

//����stl
//���˰���  �о�˵�Ķ����Ǻ����    ֱ����������   Ȼ��͹���    
//�Ժ���˽�һ��STL   ������   �������ø���ɶ  ����Ҹ�ר�Ž���STL����վ(�����Ǹ�Ӣ�ĵ�)



//32 ms   40.91
#include<algorithm>  
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int length = unique(nums.begin(),nums.end())-nums.begin();
		return length;
    }
};