#include<stdio.h>

struct object{
	int id; //Identity
	int w;//Weight
	int p;//Profit
	float ratio;//Ratio pi/wi
};

struct object item[10],temp;
int W,n,i,j,rem;
float maxp=0,frac,solution[10];

int main(){
	printf("\nCapacity of Knapsack: ");
	scanf("%d",&W);
	printf("\nNumber of Items: \n");
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		printf("\n [Items %c] Profit & Weight: ",i+65);
		scanf("%d %d",&item[i].p ,&item[i].w);
		item[i].id=65+i;
		solution[i]=0;
		item[i].ratio=(float)item[i].p/(float)item[i].w;
	}
	printf("\n----------Entered Data----------\n");
	printf("\nItem \tProfit \tWeight \tRatio\n");
	
	for(i=0;i<n;i++) 
	{
		printf("\n %c \t%d \t%d \t%.3f",item[i].id,item[i].p,item[i].w,item[i].ratio);
	}
	printf("\n");
	
	//Descending Sort
	for(j=1;j<n;j++){
		temp=item[j];
		i=j-1;
		while(i>=0&&item[i].ratio<temp.ratio){
			item[i+1]=item[i];
			i--;
		}
		item[i+1]=temp;
	}
	printf("\n----------Sorted Items----------\n");
	printf("\nItem \tProfit \tWeight \tRatio\n");
	
	for(i=0;i<n;i++) 
	{
		printf("\n %c \t%d \t%d \t%.3f",item[i].id,item[i].p,item[i].w,item[i].ratio);
	}
	printf("\n");
	
	//KnapSack Algorithm
	rem=W; //KnapSack is Empty
	i=0;
	while(rem>0){
		if(item[i].w<=rem){
			maxp+=item[i].p; //Take the whole item
			rem=rem-item[i].w;
			solution[i]=1;
		}else{
			maxp+=((float)item[i].p*(float)rem)/(float)item[i].w; //Take Fraction of Item
			frac=(float)(rem*100)/(float)item[i].w;
			solution[i]=frac;
			rem=0; //KnapSack is now Full		
		}
		i++;
	}
	printf("\n>>>> MaxProfit Obtained: %.3f\n",maxp);
	
	printf("\n>>>> Items Picked: ");
	for(i=0;i<n;i++) 
	{
		if(solution[i]==1){
			printf("%c",item[i].id);
		}else if(solution[i]>1){
			printf("%c(%.2f%%)).",item[i].id,solution[i]);
		}
		printf("\n");
	}
}

