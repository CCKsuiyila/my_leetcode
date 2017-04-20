//������ҫ֮����½׶ε�һ����������
//�տ�ʼ����Ǹ�˼·����鷳    ���ն�û������
//Ȼ��ͻȻ�����һ��˼·,�о����ܼ�     ������,����3���Ӿ�accept��
//��˼·����Ҫ��
//45MS     8.07%
int quicksort(vector<Interval>& data,int low,int high){
	int partition(vector<Interval>& data,int low,int high);
	if ((high-low)<1){
		return 0;
	}
	
	int middle=partition(data,low,high-1);
	quicksort(data,low,middle);
	quicksort(data,middle+1,high);
	return 0;
}

int partition(vector<Interval>& data,int low,int high){
	int backup_low=low;
	int backup_high=high;
	Interval middle_data=data[low];
	for(;low<high;){
		for(;low<high;){
			if(data[high].start>middle_data.start){
				high=high-1;
			}else{
				data[low]=data[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(data[low].start<middle_data.start){
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
     vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		intervals.push_back(newInterval);
		if(intervals.size()<=1){
			return intervals;
		}
		quicksort(intervals, 0 ,intervals.size());
		vector<Interval> result;
		result.push_back(intervals[0]);
		for(int i = 1,j = 0;i<intervals.size();++i){
			if(intervals[i].start<=result[j].end&&intervals[i].end>=result[j].start){
				Interval temp(min(result[j].start,intervals[i].start),max(result[j].end,intervals[i].end));
				result.pop_back();
				result.push_back(temp);
				while(j>=1&&result[j].start<=result[j-1].end&&result[j].end>=result[j-1].start){
					Interval temp(min(result[j].start,intervals[j-1].start),max(result[j].end,intervals[j-1].end));
					result.pop_back();
					result.pop_back();
					result.push_back(temp);
					--j;
				}
			}else{
				result.push_back(intervals[i]);
				++j;
			}
		}
		return result;
    }
}; 

















/*
//�о�������������һ��56   Ȼ��ӵ㶫���ͺ���
int quicksort(vector<Interval>& data,int low,int high){
	int partition(vector<Interval>& data,int low,int high);
	if ((high-low)<1){
		return 0;
	}
	
	int middle=partition(data,low,high-1);
	quicksort(data,low,middle);
	quicksort(data,middle+1,high);
	return 0;
}

int partition(vector<Interval>& data,int low,int high){
	int backup_low=low;
	int backup_high=high;
	Interval middle_data=data[low];
	for(;low<high;){
		for(;low<high;){
			if(data[high].start>middle_data.start){
				high=high-1;
			}else{
				data[low]=data[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(data[low].start<middle_data.start){
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		if(intervals.size()==0){
			vector<Interval> result_2;
			result_2.push_back(newInterval);
			return result_2;
		}
		if(intervals.size()>=2){
			quicksort(intervals, 0 ,intervals.size());
		}
		vector<Interval> result;
		result.push_back(intervals[0]);
		for(int i = 1,j = 0;i<intervals.size();++i){
			if(intervals[i].start<=result[j].end&&intervals[i].end>=result[j].start){
				Interval temp(min(result[j].start,intervals[i].start),max(result[j].end,intervals[i].end));
				result.pop_back();
				result.push_back(temp);
				while(j>=1&&result[j].start<=result[j-1].end&&result[j].end>=result[j-1].start){
					Interval temp(min(result[j].start,intervals[j-1].start),max(result[j].end,intervals[j-1].end));
					result.pop_back();
					result.pop_back();
					result.push_back(temp);
					--j;
				}
			}else{
				result.push_back(intervals[i]);
				++j;
			}
		}
		
		vector<Interval> result_2;
		int a=0;
		int b=0;
		while(a<result.size()&&newInterval.start>result[a].end){
			++a;
		}
		--a;
		while(b<result.size()&&newInterval.end>=result[b].start){
			++b;
		}
		--b;
		if(a==result.size()-2){    //�������
			result.push_back(newInterval);
			return result;
		}
		for(int i=0;i<=a;++i){
			result_2.push_back(result[i]);
		}
		if(a==result.size()-1){
			result_2.push_back(newInterval);
			return result_2;
		}
		Interval temp(min(newInterval.start,result[a+1].start),max(newInterval.end,result[b].end));
		result_2.push_back(temp);
		
		for(int i=b+1;b<result.size();++i){
			result_2.push_back(result[i]);
		}
		return result_2;
    }
};
*/