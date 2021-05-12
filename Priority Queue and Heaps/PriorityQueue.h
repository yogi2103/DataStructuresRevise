#include<vector>
class PriorityQueue{
	private:
	vector <int> pq;
	public:
		PriorityQueue(){
		}
		
		bool isEmpty(){
			return pq.size()==0;
		}
		
		int getSize(){
			return pq.size();
		}
		
		int getMin(){
			if(!isEmpty()){
				return pq[0];	
			}
			return 0;
		}
		
		void insert(int ele){
			pq.push_back(ele);
			int CI=pq.size()-1;
			int PI=(CI-1)/2;
			if(PI>0){
				while(CI>0){
					swap(pq[PI],pq[CI]);
					CI=PI;
					PI=(CI-1)/2;
				}
			}
		}
		
		void print(){
			for(int i=0;i<pq.size();i++){
				cout<<pq[i]<<" ";
			}
		}
};

int 
