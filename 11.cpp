//����˼·  2��forѭ��Ӧ�ÿ��Խ������   ��ξͲ�ֽ��д��
//ȷʵд�����ܿ�,���Ҽ����ݿ��Թ�,����48/49��ʱ��,���Ի��øĽ�,�����Ż�������,���ǲ���   ��Ҫ��˼·��
//������˵�˼·   ����   ����һʱ������Ϊɶ   ��  ������˵�Ҳ������Congratulations, you've just unlocked a solution! 

//19ms     49.82%    ˵�����и���Ч��
class Solution {
public:
    int maxArea(vector<int>& height) {
        int j = height.size() - 1;
		int i = 0;
		int water = 0;
		int temp = 0;
		while(i<j){
			temp = (j-i)*((height[i]<=height[j])?(height[i]):(height[j]));
			if(temp>water){
				water = temp;
			}
			(height[i]<=height[j])?(++i):(--j);
		}
		return water;
    }
};


/*
//�Լ��ĳ�ʱ��  2��forѭ��
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
		int result1 = 0;
		int result2 = 0;
		int water = 0;
		for(int i = 0; i < n-1; ++i){
			for(int j = i+1,difference = 1; j<n ; ++j,++difference){
				int temp = difference*((height[i]<=height[j])?(height[i]):(height[j]));
				if(temp>water){
					result1 = i;
					result2 = j;
					water = temp;
				}
			}
		}
		return water;
    }
};
*/