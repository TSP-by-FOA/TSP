#include<iostream>
#include<string>
#include <bits/stdc++.h> 

using namespace std;
int main()
{
	int no;
	cout<<"Enter no of cities : ";
	cin>>no;
	string cities[(const int)no];
	
	int cost[(const int)no][(const int)no]={0};
	
	
	for(int i=0;i<no;i++)
	{
		cout<<"\nCity "<<i+1<<" : ";
		cin>>cities[i];
	}
	
	
	for(int i=0;i<no;i++)
	{
		for(int j=0;j<no;j++)
		{
			if(i==j)
			{
				continue;
			}
			cout<<"Cost from "<<cities[i]<<" to "<<cities[j]<<" : ";
			cin>>cost[i][j];
		}
	}
	
	
	cout<<"\n\n";
	for(int i=0;i<no;i++)
	{
		cout<<"\n\n";
		for(int j=0;j<no;j++)
		{
			cout<<"  "<<cost[i][j]<<"  ";
		}
	}
	
		
	cout<<"\n";
	
		int s=0;
		do
		{
			cout<<"\nEnter Starting City : ";
			cin>>s;
		
			if(s<=0||s>no)
			{
				cout<<"\nInvalid !!!!! ";
				cout<<"\nEnter between 1 and "<<no-1<<endl;
			}
		}
		while(s<=0||s>no);
		s=s-1;
		vector<int> vertex; 
		
    for (int i = 0; i < no; i++) 
        if (i != s) 
            vertex.push_back(i); 
  
  	int low_path[(const int)(no+1)]={0};


    int min_path = INT_MAX; 
    do { 
  
        int current_pathweight = 0; 
        int path[(const int)(no+1)]={0};
        // find current path cost 
        int k = s; 
        path[0]=s+1;
        for (int i = 0; i < vertex.size(); i++) { 
            current_pathweight += cost[k][vertex[i]]; 
            path[i+1]=vertex[i]+1;
            k = vertex[i]; 
        } 
        current_pathweight += cost[k][s]; 
  
        // modify minimum path cost
        int chk=min_path;
        min_path = min(min_path, current_pathweight); 
        //modify minimum path
        if(min_path!=chk)
		{
			for(int j=0;j<no;j++)
				{
					low_path[j]=path[j];
				}
		}
         
    } while (next_permutation(vertex.begin(), vertex.end())); 
  
  
    cout<<"\nMinimum Cost :" <<min_path;
	cout<<"\nPath : ";
	low_path[no]=s+1;
	for(int i=0;i<=no;i++)
	{
		cout<<low_path[i]<<" ";
	} 
	
	
	return 0;		
}
