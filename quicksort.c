#include<stdio.h>


int a[200];

 void QuickSort(int ,int);
 int Partition(  int , int);

int main()
{
	int i,j,n;
	
	printf("\n Enter the size");
	scanf("%d",&n);
	
	
	printf("\n ENter %d Integers",n);
	
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	
	QuickSort(0,n-1);
   
   	
   	printf("\n Sorted array\n");
    for(i=0;i<n;i++)
	printf("%d ",a[i]);
	
   return(0);
}


void QuickSort(int p , int q)
{
	int j;
	
	if(p<q)
	{
		j=Partition( p, q);
		QuickSort(p,j-1);
		QuickSort(j+1,q);
	}


}

int Partition( int beg ,int end)
{
	int pivot=a[beg];
	
	int i=beg, j=end ,temp;
	
	while(i<=j)
	{
		while((a[i]<=pivot) && (i<=end))
			i++;
		
		while( (a[j]>pivot) && (j>=beg))
			j--;
		
		//swap a[i] and a[j]
		
		if(i<j)
		{	
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		
	}	
	
	//swap pivot and a[j];
		temp=a[beg];
		a[beg]=a[j];
		a[j]=temp;
	
	return (j);	
}







