//����þ�,�ֿ�ʼ��ֽ��д��
//���˼·,��ֽ��д�ú�,�ᵽ������,���˼���С�﷨����,Ȼ��ͨ����152������(��300����)
//Ȼ��˲�䷢�����Լ����⿼�Ǽ���
//���Ǻܿ��ָ������ǿ��ǵ�����,����˸����Ͻ����㷨.  ����ֻͨ����168������
//�ڶ���(�����ڵڶ���)���������볭��һ��,���ֻ���û���߼��ϵĴ���,���ǿ�ʼ�鿴�������������
//����û������ɶ����   ���û�취,ֻ�ܵ���һ����   �ܿ췢������������   �޸ĺ��ͨ����
//ͨ��֮����,�Լ��ķ�����ʵ���ܽ��֪��,����û���ǵ��������.

//���������˷���ʱ���    �Ͻ��Ի����ǿ   ���ջ��ǵ�����.
//������˼·��û�����

// 9 ms   64.84%
class Solution {
public:
	int findTheLow(vector<int>& height,int from,int size){
		for(;(from+1)!=size&&height[from+1]<=height[from];++from);
		return from;
	}
	int findTheHigh(vector<int>& height,int from,int size){
		for(;(from+1)!=size&&height[from+1]>=height[from];++from);
		return from;
	}
    int trap(vector<int>& height) {
        int sum = 0;
		int now = 0;
		int size = height.size();
		if(size<3){
			return 0;
		}
		int* high_array = new int[10000];
		high_array[0]=now;
		int high_count=1;
		for(;now!=size-1;++high_count){
			int low = findTheLow(height, now, size);
			/*
			if(low==size-1){     //���������168��accepted
				return 0;
			}
			*/
			high_array[high_count] = findTheHigh(height, low, size);
			now=high_array[high_count];
		}
		cout<<high_count;
		for(int low=0,high=high_count-1;low!=high;){
			int standard;
			if(height[high_array[low]]<=height[high_array[high]]){
				standard = height[high_array[low]];
				for(int j=high_array[low]+1;j!=high_array[high];++j){
					if(standard>height[j]){
						sum+=standard-height[j];
						height[j]=standard;
					}
				}
				int m=low+1;
				for(;m!=high&&height[high_array[m]]<=height[high_array[low]];++m);
				low=m;
			}else{
				standard = height[high_array[high]];
				for(int j=high_array[low]+1;j!=high_array[high];++j){
					if(standard>height[j]){
						sum+=standard-height[j];
						height[j]=standard;
					}
				}
				int m=high-1;
				for(;m!=low&&height[high_array[m]]<=height[high_array[high]];--m);
				high=m;
			}
		}
		return sum;
    }
};


//����ԭ���ٿ�����һ�������
/*
//�� ����һ���Լ�������˼·(���ÿ��һ��Ͱ����ճ��ȥ)
//1.�������
//2.ȷ������˼·(ѡ�����ݽṹ�㷨ʲô��)   ȷ���ܽ���������,Ҳ���ÿ���̫�ิ�Ӷ�
//3.2�ﵽ֮��, ��ʼ���Ǹ��ֽ������������������   Ȼ�󿴿���û�и��Ӷȸ��͵�˼·

class Solution {
public:
	int findTheLow(vector<int>& height,int from,int size){
		for(;(from+1)!=size&&height[from+1]<=height[from];++from);
		return from;
	}
	int findTheHigh(vector<int>& height,int from,int size){
		for(;(from+1)!=size&&height[from+1]>=height[from];++from);
		return from;
	}
    int trap(vector<int>& height) {
        int sum = 0;
		int now = 0;
		int size = height.size();
		if(size<3){
			return 0;
		}
		//���M��״
		int low = findTheLow(height, now, size);
		int high = findTheHigh(height, low, size);
		if(low==now){
			now=high;
		}
		while(now!=size-1){
			int low = findTheLow(height, now, size);
			int high = findTheHigh(height, low, size);
			if(low==size-1){
				return sum;
			}
			int lower;
			if(height[now]<=height[high]){
				lower = height[now];
			}else{
				lower = height[high];
			}
			for(int i = now+1;i!=high;++i){
				if(lower>height[i]){
					sum+=lower-height[i];
				}
			}
			now=high;
		}
		return sum;
    }
};
*/