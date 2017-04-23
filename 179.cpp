//���������,˼����һ�����и�˼·��
//����һ���ȽϺ���,���ԱȽ����������ĸ���ǰ��,Ȼ�����quicksort����������Ÿ���,
//Ȼ��ֱ�ӵ����ַ����������ͺ���

//�Ͱ����Լ��������˼·accept��,������Ϊֱ������, ���Գ���ЩС����
//������С�ڿ����   ����  ���������м�¼

//������ȶԿ��������и�ϰ��һ��,Ȼ���д,˼·�ܺ�
//Ȼ��ͻ�������뵽��string������,���˲�,��Ȼ��,Ȼ���ѧ������   Ȼ���õ�ͦ��
//�Ǹ������ų�����Խ�����ԽҪ�ŵ�ǰ��
//���������ʱʵ�������ѿ�    ��ʱ����һ����

//����
//������֮����гɾ͸���   ��Ϊ����Ҳ�������˼·  ������֪�����ǵ��ٶ�զ��(��������Java��Python��)
//�޴�ĳɾ͸а�   ���������������ѵ���    Ȼ�����Լ��ܿ�Ͱѹؼ���˼·�������    �����ĳɾ͸�
//��һ��,�ٵ��ڿ��Ǽ��ٵ������

/*
//�������˵��ٶ�
//3MS 77.77%
class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> arr;
        for(auto i:num)
            arr.push_back(to_string(i));
        sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        string res;
        for(auto s:arr)
            res+=s;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return  res;
    }
};
*/
//���Լ���˼·��ȫ��ͬ,���������ڿ��ʹ���൱����,���Լ����õ��Լ���д��
//�Ժ�������

//36MS  0.94% 
int compare(int a, int b){                 //�൱��>��
	stringstream input_one;
	input_one<<a;
	stringstream input_two;
	input_two<<b;
	string one = input_one.str();
	string two = input_two.str();
	if((one+two)>(two+one)){
		return a;
	}else{
		return b;
	}
}

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
			if(compare(data[high],middle_data)==data[high]){
				high=high-1;
			}else{
				data[low]=data[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(compare(data[low],middle_data)==middle_data){     //����ԭ��д��������(����û�ĺ�)if(compare(data[low],middle_data)==data[low]){
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
    string largestNumber(vector<int>& nums) {
		quicksort(nums,0,nums.size());
		string result;
		for(int i = nums.size()-1; i>=0; --i){
			stringstream temp;
			temp<<nums[i];
			result += temp.str();
		}
		if(result[0]=='0'){         //���û�뵽     �������������ܼ�
			return "0";
		}
		return result;
    }
};