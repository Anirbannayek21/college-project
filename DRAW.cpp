#include<bits/stdc++.h>
using namespace std;

int main()
{
	int totalChoice;
	cout<<"total Dorms: ";
	cin>>totalChoice;
	cout<<endl;
	
	cout<<"number of bad per dorms:- ";
	int numOfbad;
	cin>>numOfbad;
	
	int n;
	cout<<"total students: ";
	cin>>n;
	cout<<endl;
	unordered_map<int,vector<int>>m;
	for(int id=1;id<=n;id++)
	{
		cout<<"preference list for student "<<id<<" :- ";
		vector<int>list;
		for(int j=0;j<totalChoice;j++)
		{
			int x;
			cin>>x;
			list.push_back(x);
		}
		m[id]=list;
		cout<<endl;
	}
	
	unordered_map<int,int>rank;
	
    for (int i = 1; i <=n; i++) {
    	
    	while(true){
        	int num = (rand() % (n - 1 + 1)) + 1;
        	if(rank[num]==0){
        		rank[num] = i;
        		break;
			}
		}
    }
    cout<<"ranks and ids: "<<endl;
    for(int r=1;r<=n;r++)
    {
    	cout<<r<<" "<<rank[r]<<endl;
	}
	cout<<endl;
	
	unordered_map<int,int>allocatedStudent;
	unordered_map<int,int>allocated;
	
	for(int ran=1;ran<=n;ran++)
	{
		int ID = rank[ran];
		for(int choice:m[ID])
		{
			if(allocatedStudent[choice]<numOfbad){
				allocatedStudent[choice]++;
				allocated[ID]=choice;
				break;
			}
		}
	}
	
	cout<<"allocation:- "<<endl;;
	for(int id=1;id<=n;id++)
	{
		
		cout<<id<<" "<<allocated[id]<<endl;
	}
	return 0;
}
