//ë�ſο��˿�,���˸�˼·   ���ϻ���ֱ�������ð�
//��������,�����Լ���������û���������
//Ȼ����ݴ����������һ�����,һ���޸�,Ҳû����þ�accept��
//��  ��������Ŀ�������һ��ĺ�ֱ�Ӿ�������

//����
//���˱��˵�˼·,�Լ���˼·���Ҳ�����  Ȼ�����һ��,������˺ö�
//���ǲ��Ե�����ʱ���ԭ��һ��,ԭ���������������Ǳ�����һ��,��Ӧ��û�����͸��Ӷ��˰�
//�����������˷���ʱ��   ��ϵͳ�������㷨����
//ѧ���˸�ϵͳ��sort������  ���Ǹ���ϵͳ��sort֮��Ч����Ȼû�����

//������hash�濴���ܲ��ܼ���
//hash��д�˺þ�ûд����   ���ž�����ͨ����Ա�͸߼�����Ա֮��蹵��,����ͻ����?
//�ٵ����һ��Ҫ�㶨���
class Solution {
public:
    int hIndex(vector<int>& citations) {
		int array[10000]={0};
		int max = 0;
		for(int i = 0;i<citations.size();++i){
			if(citations[i]>max){
				max = citations[i];
			}
			++array[citations[i]];
		}
		int count = 0;
		int i = max;
		for(;i>1&&i>=count; ){
			--i;
			count += array[i];
		}
		cout<<array[2];
		if(i==max){
			return max;
		}else{
			return count;
		}
    }
};

/*
//����֮���е�о�
// 3MS 26.60 %
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());
        int i = 0;
		for(; i<citations.size()&&citations[i]>=i+1; ++i);
		return i;
    }
};
*/

/*
// 3MS 26.60 %
//������������
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
			if(data[high]<=middle_data){    //����о�<=��<����Ч
				high=high-1;
			}else{
				data[low]=data[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(data[low]>=middle_data){     //ͬ��
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
    int hIndex(vector<int>& citations) {
        quicksort(citations, 0, citations.size());
        int max = 0;
		for(int i = 0; i<citations.size(); ++i){
			if(i+1>=citations[i]&&citations[i]>max){
				max = citations[i];
			}
			if(citations[i]>=i+1&&i+1>max){
			    max = i+1;
			}
		}
		return max;
    }
};
*/