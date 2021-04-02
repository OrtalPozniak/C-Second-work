#include <stdio.h>
#include <string.h>

int menu,x,y,n,i,exist,add,count,counter2,j, arr2[30][30]={{0},{0}},flag=1,counter=0,flag2=1,max_value_index,M=0,index_to_remove,min_index,new_val;
int  arr[30]={0},weight[30]={0},price[30]={0},W,ind=0, tempo[30]={0},g, tempi[30]={0}, indi,prev=0,len=1,temp,f,index_arr[30]={0},b,expensive;
int MM=0;
void PrintMenu();
int Ack(int x, int y);
void permute(int N, int arr[], int index,int last);
void partition(int N, int arr[], int index);
int exist_in_arr(int N, int arr[],int num, int index);
void put_in_arr(int N, int arr[],int num, int index);
void knapsack(int N,int weight[], int price[],int W,int num,int tempo[],int f);
int atzeret(int N);
int last_arr(int arr[],int index, int N);
int combinations(int N,int items[],int price[], int sum,int total,int in, int index_results,int times,int prev);
int replace_ind(int old, int fresh, char direction);
int max_index_in_arr(int arr[], int m, int maxi);
int min_weight_index(int arr[], int m, int mini);
int find_what_to_remove(int weight[], int price[], int m, int mini);
int check_for_better(int weight[], int price[], int maxi, int t,int W, int cost);
int is_ind_exist(int num,int ind);
void copy_to_arr(int arr2[], int arr1[],int from,int until);
void intialize_arr(int arr[], int index);
void sort_arr(int arr[],int num);
void main()
{
		count=0,counter2=0,ind=0;
		PrintMenu();
		scanf("%d",&menu);

		switch(menu)
		{
		case 1:
			printf("Enter parameters X and Y for Ackerman function:\n");
			scanf("%d %d",&x, &y);
			printf("Ack(%d,%d)=%d\n\n",x,y,Ack(x,y));
			main();
			break;
		case 2:
			printf("Enter positive integer greater than 0:\n");
			scanf("%d",&n);
			intialize_arr(arr,0);
			printf("All permutations of numbers (");
			for(i=0; i<n; i++)
			{
					arr[i]= i + 1;
					if(i<n-1)
					printf("%d ", arr[i]);
			}
			printf("%d):\n",arr[n-1]);
			permute(n,arr,n-1,n);
			printf("\n");
			main();
			break;
		case 3:
			printf("Enter positive integer greater than 0:\n");
			scanf("%d",&n);
			while(n<=0)
			{
				printf("Input error! Please try again,\n");
				printf("Enter positive integer greater than 0:\n");
				scanf("%d",&n);
			}
			intialize_arr(arr,0);
			for(i=0; i<n; i++)
				arr[i]=1;
			printf("All partitions of %d:",n);
		for(i=0; arr2[i][0]; i++)
			intialize_arr(arr2[i],0);
			counter=0;
			partition(n,arr,0);
			printf("\n");
			main();
			break;
		case 4:
			intialize_arr(price,1);
			intialize_arr(weight,1);
			intialize_arr(tempo,1);
			intialize_arr(tempi,1);
			printf("Enter number of items in the store:\n");
			scanf("%d",&n);
			printf("Enter the weights of items:\n");
			for(i=1; i<=n; i++)
				scanf("%d",&weight[i]);
			printf("Enter the values of items:\n");
			for(i=1; i<=n; i++)
				scanf("%d",&price[i]);
			printf("Enter maximum weight that thief can take with him:\n");
			scanf("%d",&W);
			f=1;
			knapsack(n,weight,price,W,1,tempo,1);
			main();
			break;
		case 5:
			break;
		default:
			printf("\n");
			main();
			break;
		
		}

		
	  
}

void PrintMenu()
{
	printf("Choose one of the following problems or exit:\n[1] - Run Ackerman function.\n[2] - Run Permutations problem.\n[3] - Run Partitions problem.\n");
	printf("[4] - Run Knapsack problem.\n[5] - Exit.\nEnter your choice:\n");
}
int Ack(int x, int y)
{ //This question was just translated to C language, there isn't much to explain here.
	if((x==0) && (y>=0))
		return y+1;

	else if((x>0) && (y==0))
		return (Ack(x-1,1));
	
	else if((x>0) && (y>0))
		return(Ack(x-1,Ack(x,y-1)));
}

void permute(int N, int arr[], int index,int last)
{
	int temp,in,min=0,check=0,k,t;

	if(last)
	{
	for(i=0;i<N;i++)
		if((exist_in_arr(0,arr,arr[i],i)))
			check+=1;
		else
			check=0;

	if(check<2) //if a digit appears more than once, the number won't be printed.
	{
	for(i=0; i<N; i++)
		printf("%d ",arr[i]);
	printf("\n");
	}
	}
	counter++;

	
		if(arr[N-1]==N)
			last=N;

		if((arr[N-last]==last) && !(last_arr(arr,N-1,N)))
			last-=1;

		if(N==2)
		{
			temp= arr[N-2];
			arr[N-2]= arr[N-1];
			arr[N-1]=temp;

			for(i=0; i<N; i++)
			printf("%d ",arr[i]);
			printf("\n");
		}
		 
		if(((counter<atzeret(N))&&(N>2))) //According to statistic, each serial with length N has N! options to be ordered.
		{
				temp= arr[N-2];
				arr[N-2]= arr[N-1];
				arr[N-1]=temp;

				for(i=0; i<N; i++)
				printf("%d ",arr[i]);
				printf("\n");

				for(k=0; arr[k]!=last;k++);
				if(arr[k-1]<last) //Promoting the digit standing to the left of a certain digit (the biggest from the right side).
				{
				put_in_arr(N,arr,arr[k-1]+1,k-1); 
				put_in_arr(N,arr,1,k); 
				permute(N,arr,N-1,last);
				}
				
		}
		else
			counter=0;


}
		
void partition(int N, int arr[],int index)
{
	int temp=0, change=0,end,k,counter3=0,counter4=0,flag=1,m,counter5=0,count_similar=0;

	if(arr2[0][0]==0)
		j=0;

		for(i=0; arr[i]; i++)
			temp+=arr[i]; //check if the sum of numbers is equal to N.


		if(temp==N)
		{

		if(j>0)
		{
		for(i=0; arr[i]; i++)
		{
			if(((arr2[j-1][i]==arr[i]))) //check if the array has been changed.
				change++;
			if(arr[i]==arr[0])
			count_similar++;
		}
		end=i;

		}
		if((change!=i)||(j==0))
		{
			if(j>0)
			{
			if((arr[end-1]==2)&&(count_similar==end-1)&&(arr2[j-1][1]!=1))
			{
				copy_to_arr(arr2[j],arr,0,end-1);
				arr2[j][end-1]= 1;
				arr2[j][end]=1;
				j+=1;
			}
			}
			copy_to_arr(arr2[j],arr,0,i);
			j+=1;
		}
		
		}
		
	if(!index)
	{

		for(i=0; arr[i]; i++)
		{
			if((arr[i]==arr[0]) || (!arr[i]))
				counter3++; //check for situations like "22" or "33".

			else if((arr[i]==1))
				counter4++; // check for situations like "221".
			else if(arr[i]==2)
				counter5++;
		}
		end=i;
	}
	else
	{
		counter3=0;
		counter4=0;
		counter5=0;
		end=10;
	}

	if((counter3==end)|| ((counter4==1)&& (counter3==end-1)))
	{
			arr[0]+=1;
			for(i=1; (arr[0]+i)<=N; i++)
				arr[i]=1;
			for(;arr[i];i++)
				arr[i]=0;
			if(arr[N-1])
				arr[N-1]-=1;
			if(arr[0]<=N)
				partition(N,arr,1);
			
	}
	else if((counter4==1)&& (counter5))
	{
		arr[end-1]=1;
		arr[end-2]+=1;
	}

	else if(arr[index])
	{
		for(k=0; arr[k]; k++);

		
		while(arr[index]==arr[index-1])
			index--;

		if(arr[index]<=arr[index-1])
			arr[index]+=1;


			arr[k-1]-=1;


		if((arr[k-1]==0) ||(arr[k-1]==1) )
		{
			for(m=0; arr[m]>1; m++);
			
			if(arr[m]==1)
			{
				if((arr[m+1]==1))
					index= m;
				else if(arr[m-1]<arr[m-2])
					index=m-1;
				else 
					index=m-2;

			}

			else if(arr[m]==0)
			{

					while(arr[m-1]>=arr[m-2])
						m--;

					if((arr[m-1]<arr[m-2]) && (m>1))
						index= m-1;
					
			}

		}
		
		else 
			index+=1;

		if(arr[0]<N)
			partition(N,arr,index);
	
	}
	else if(arr[0]<N)
			partition(N,arr,0);

			for(; j>=0; j--)
			{
				for(i=0;arr2[j][i]; i++)
					printf("%d ",arr2[j][i]);
				printf("\n");
				
			}


 }

 int exist_in_arr(int ind,int arr[],int num, int index)
 { //This function is checking if a certain number is olready exist in the array.
	 if(ind<index)
		 if(arr[ind]==num)
			 return 1;
		 else
			 exist_in_arr(ind+1,arr,num,index);
	 else
		 return 0;
 }
		 
 void put_in_arr(int N, int arr[],int num, int index)
 { //This function responsible for adding a number and after it add all numbers from 1 until N if
	 //they are not allready exist.
	 if(!(exist_in_arr(0,arr,num,index)))
	 {
			arr[index]=num;
			if((index<N-1)&&(num<N))
				put_in_arr(N,arr,num+1,index+1);
			else
				return;
	 }
	 else if(num<N)
		 put_in_arr(N,arr,num+1,index);
	 else if(index<=N-1)
		 put_in_arr(N,arr,1,index);
	 else
		 return;
			 
 }

 int atzeret(int N)
 { //Calculates N! for statistic needs.
	 if(N>1)
		return N*atzeret(N-1);
	 else
		 return 1;
 }

 int last_arr(int arr[],int in, int N)
 {// Checking if a certain array has it's final shape.
	 if((in==0) && (arr[0]==N))
		 return 1;
	 if(arr[in]==arr[in+1]+1)
		 last_arr(arr,in+1,N);
	 else
		 return 0;
	 

 }


 void knapsack(int N,int weight[], int price[],int W,int num,int tempi[],int f)
 {
	 int cost=0,bag,place,nn,shuman;

	 b =min_weight_index(weight,1,500);

	  if(W<=weight[b]) 
		{
			if(weight[b]==W)
			{
				printf("Overall value of items that were stolen is %d:\n",price[b]);
				printf("Item #%d of weight %d and value %d\n\n",b,weight[b],price[b]);
			}
			else
				printf("Overall value of items that were stolen is 0:\n\n");
		}

	  else
	  {


	 if(num<N)
		bag= combinations(N,weight,price,W,weight[num],num+1,num,0,prev);
	 else
		 bag= combinations(N,weight,price,W,weight[N],1,N,0,prev);
	 prev=bag;
	 

	 while(bag)
	 {
		cost+=price[(bag%10)];
		bag/=10;
	 }
	 index_arr[f]=prev;
	 tempi[f]=cost;
	

	 
	 if(num<N)
		 knapsack(N,weight,price,W,num+1,tempi,f+1);
	 else
	 {
		 max_value_index= max_index_in_arr(tempi,1,tempi[1]);
		 if(!(max_value_index))
			 max_value_index=1;

		intialize_arr(tempo,1);
		nn=1;
		 while(index_arr[max_value_index])
		 { //Making an array of indexes from an intiger.
			 tempo[nn]= (index_arr[max_value_index])%10;
			 (index_arr[max_value_index])/=10;
			 nn+=1;
		 }

		 expensive= tempo[1];place=1;cost=0;shuman=0;
		 for(b=1; tempo[b]; b++)
		 { // Finding the most value item in our array.
			if(price[tempo[b]] >= price[expensive])
			{
				expensive= tempo[b];
				place=b;
			}
			cost+=price[tempo[b]];
			shuman+=weight[tempo[b]];
		 }
		 
		 cost-=price[tempo[place]]; //Removing the most value item.
		 expensive= check_for_better(weight,price,expensive,1,W,cost);//looking for more valued item.
		 if(expensive)
			tempo[place]=expensive; //Replacing the index value in the index of the previous most valued item.
		 cost= cost+price[tempo[place]]; //Adding the new most valued item allowed or the previous one.
		 shuman-=weight[tempo[place]];
		 printf("Overall value of items that were stolen is %d:\n",cost);
		 if(cost)
			printf("Items that were stolen are:\n");
			sort_arr(tempo,1); //Sorting the array from the biggest index to the lower.

		 for(n=nn-1;n>0;n--) //Printing the array in reverse so the lower index will appear first.
		 {
			 if(!(exist_in_arr(0,tempo,tempo[n],n)))
			 printf("Item #%d of weight %d and value %d\n",tempo[n],weight[tempo[n]],price[tempo[n]]);
		 }
		 printf("\n");
	 }
	  }}

 int combinations(int N,int items[],int price[], int sum, int total,int in, int index_results,int times,int prev)
 { //Giving all the possible combinations.
	 int val;

	if((total<sum))
	{
		if((total+items[in])<=sum)
		{	/*creating an intiger value so the function type int could return a number 
			contains of digits that representing the value of all the indexes of the items.*/
			total+=items[in];
			index_results*=10;
			index_results+=in;
			if((in<N) && (!(is_ind_exist(index_results,in+1))))
				combinations(N,items,price,sum,total,in+1,index_results,times+1,prev);
			
			else if((in==N) && (!(is_ind_exist(index_results,1))))
				combinations(N,items,price,sum,total,1,index_results,times+1,prev);
			else if(index_results!=prev)
				return index_results;
			
		}
		else if(index_results!=prev)
			return index_results;
		else if(in<=N)
		{
			index_results*=10;
			index_results+=in;
			combinations(N,items,price,sum,total+items[in],in,index_results,times+1,prev);
		}

	}
	else if(total>sum)
	{
		min_index= min_weight_index(weight,1,weight[1]);
		
		if(!min_index)
			min_index=1;

		if(total- items[min_index]<=sum)
			return replace_ind(index_results,min_index,' ');
		else
		{
			index_to_remove= find_what_to_remove(items,price,1,min_index);
			
			if(index_to_remove>10)
			{
				val= replace_ind(index_results,(index_to_remove%10),' ');
				total-=items[index_to_remove%10];
				val= replace_ind(val,(index_to_remove/10),' ');
				total-=items[index_to_remove/10];
				return val;
			}
			else
			{
				val= replace_ind(index_results,index_to_remove,' ');
				total-=items[index_to_remove];
				return val;
			}

			
		}
		
	}

 }

 int replace_ind(int old, int fresh, char direction)
 {
	 int temp,len=1,m;
	 temp=old;

	 if(direction=='L')
	 {
		 while(temp/10)
		 {
			 temp/=10;
			 len*=10;
		 }
		 if(fresh)
			 return ((old%len)*10)+fresh;
		 else
			 return old%len;
	 }
	 else if(direction=='R')
	 {
		 if (fresh)
		 return ((old/10)*10)+fresh;
		 else
			 return old/10;
	 }
	 else
	 {
		 y=old;m=1;
		 while((y%10)!=fresh)
		 {
			 y/=10;
			 m*=10;
		 }
		 y/=10; //remove the index

		 if((y%10)==(old%10))
			 replace_ind(old,0,'R');
		 else
			return (y*m+ (old%m));
		 
	 }
	 
 }

 int max_index_in_arr(int arr[], int m, int maxi)
 {
	 if(!arr[m])
		 return MM;

	 else 
	 {
		 if(arr[m]>maxi)
		 {
			maxi= arr[m];
			MM=m;
			max_index_in_arr(arr,m+1,maxi);
		}
		 else
			 max_index_in_arr(arr,m+1,maxi);
		 
	 }
 }

 int min_weight_index(int weight[], int m, int mini)
 {
	 if(!weight[m]) 
		return M;
	 

	 else 
	 {
		 if(weight[m]<mini)
		 {
			mini= weight[m];
			M=m;
			min_weight_index(weight,m+1,mini);
		 }
		 else
			 min_weight_index(weight,m+1,mini);
		 
	 }
 }

 int find_what_to_remove(int weight[], int price[], int m, int mini)
 {
	 int new_min, next_val,more;

	 new_min= weight[m];
	 new_min= min_weight_index(weight,m,weight[m]);

	 if(weight[new_min]== weight[mini])
		new_min = find_what_to_remove(weight,price,m+1,mini);

	 else
	 {

		 next_val= min_weight_index(weight,m+1,weight[new_min]);

		 if(weight[next_val]> weight[new_min]+weight[mini])
		 {
			 if(price[new_val]>price[new_min]+price[mini])
				return (mini*10 + new_min);
			 else
				 return new_val;
		 }
		 else
		 {
			 if(price[new_val]>=price[new_min]+price[mini])
				 return (mini*10 + new_min);
			 else if(price[new_val]< price[new_min]+price[mini])
				 return new_val;
		 }
	 }
	 
 }

 int check_for_better(int weight[], int price[], int maxi,int t,int W, int cost)
 {

	 if(t!=maxi)
	 {
		if(((price[t]>price[maxi]) && ((weight[t]+cost)<=W)))
			maxi=t;
		 else if((price[t]==price[maxi])&&(weight[t]<weight[maxi]))
			 maxi=t;
	 }


	 	if(weight[t+1])
			check_for_better(weight,price,maxi,t+1,W,cost);
		else
			return maxi;
	
 }
	
int is_ind_exist(int num,int ind)
{
	if((num%10)==ind)
		return 1;
	else if(!num)
		return 0;
	else
		is_ind_exist(num/10,ind);
}

void copy_to_arr(int arr2[], int arr1[],int from,int until)
{
	if(from==until)
		return;
	else
	{
		arr2[from]=arr1[from];
		copy_to_arr(arr2,arr1,from+1,until);
	}
}


void intialize_arr(int arr[], int index)
{
	if(!(arr[index]))
		return;
	else
	{
		arr[index]=0;
		intialize_arr(arr,index+1);
	}
}

void sort_arr(int arr[],int num)
{
	if(!(arr[num]))
		return;

	if(arr[num]<arr[num+1])
	{
		temp=arr[num];
		arr[num]= arr[num+1];
		arr[num+1]= temp;
	}

	sort_arr(arr,num+1);
}

	