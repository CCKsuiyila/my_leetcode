//��ʵ�Լ�����˼·��,���ǲ���д,  Ȼ�������ѱ�����ôд,���˵�һ��,���ֱ��˵�˼·�������Լ�����,
//���Ǿ��Լ�д��(��ֽ��д)    �����õ�������  Ȼ����˵�С����  ��accept��
//С���������б�ע
// 3MS   3.15%   
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;   
		if(matrix.empty()){     //��һ��,���ֿյ�vector���鲻����size(),��������
			return result;      //reference binding to null pointer of type 'struct value_type'
		}
        int high = 0;
		int low = matrix.size() - 1;
		int lef = 0;
		int righ = matrix[0].size() - 1;
		while(high<=low&&lef<=righ){              //<= д����<-
			for(int i = lef; i<=righ; ++i){
				result.push_back(matrix[high][i]);
			}
			++high;
			if(high>low){
				return result;
			}
			for(int i = high; i<=low; ++i){
				result.push_back(matrix[i][righ]);
			}
			--righ;
			if(righ<lef){
				return result;
			}
			for(int i = righ; i>=lef; --i){
				result.push_back(matrix[low][i]);
			}
			--low;
			if(low<high){
				return result;
			}
			for(int i = low; i>=high; --i){
				result.push_back(matrix[i][lef]);
			}
			++lef;
		}
		return result;
    }
};