/*
Krishnan krishnamoorthy
400089054
*/
#include<fstream>
#include<iostream>
#include <algorithm> 

using namespace std;
int weights[100][100];
int Vertex[100];
int mincost=2147483644;

 void calculatecost(int Vertex[],int n ) 
{
	int cost=0; 		
		int i=0;
  		while(i<n)
  		{
		
		if(i!=n-1)
		{
  		cost+= weights[Vertex[i]][Vertex[i+1]];
		}
		else
		{
		cost+= weights[Vertex[i]][Vertex[0]];
		}	
		i++;
  		}
			
  		mincost=min(mincost,cost);
  		
}
void exchange(int a, int b);

void TraversePath(int Vertex[], int size, int n) 
{ 
   
    int cost=0;
    if (size == 1) 
    { 
      calculatecost(Vertex,n); 
        return; 
    } 
	int i=0;
  while(i<size)		  
    { 
        TraversePath(Vertex,size-1,n); 
  
      
        if (size%2==1) 
           
  		exchange(0, size-1);
       
        else
           
            	exchange(i, size-1);
	i++;
    } 
} 

void exchange (int a, int b)
{
	int temp=0;
	temp = Vertex[a];
	Vertex[a]= Vertex[b];
	Vertex[b] = temp;
}

int main(int argc, char* argv[])

{
	
if(argc != 3)
 {
 	cout<<"Incorrect number of Arguments"<< endl;
 	return -1;
 }
  fstream input(argv[1]);
  ofstream output(argv[2]);
  
  if(!input)
  {
  	cout<<"Error in opening the input file"<< endl;
  } 
   if(!output)
  {
  	cout<<"Error in opening the output file"<< endl;
  }
   
  int NoOfTestCase;
  input>>NoOfTestCase;
  
  for(int z=0;z<NoOfTestCase;z++)
  {
  	mincost=2147483644;
  	int noOfVetex;
  	input>>noOfVetex;
  
  	bool Visited[noOfVetex];
  
  	for(int i=0;i<noOfVetex;i++)
  	{
  		Vertex[i]=i;
  		Visited[i]=false;
  		
  	}
  	
  	for(int j=0;j<noOfVetex;j++)
  	{
  		for(int x=0;x<noOfVetex;x++)
  		{
		  	weights[j][x]=0;
  		}
  	}
  	int noOfEdges;
  	input>>noOfEdges;
  
  	for(int p=0;p<noOfEdges;p++)
  	{
		int k;
		input>>k;
		int m;
		input>>m;
		int weight;
		input >> weight;
		weights[k][m]=weights[m][k]= weight;  	
  	}
  	int n = noOfVetex;
	calculatecost(Vertex,n) ;

    TraversePath(Vertex, n, n);
	output<<mincost<<endl;
}
    return 0; 
}
 
