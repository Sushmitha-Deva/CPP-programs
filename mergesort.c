#include<stdio.h>



void Merge( int beg , int end);
void MergeSort( int p,int q);

int a[100];

int main() 	
{

		int n;
    printf("\n Enter the size of the array");
    scanf("%d",&n);
		
 		printf("\n Enter the array");
 		
 		for(int i=0; i<n;i++)
 			scanf("%d",&a[i]);
	
		MergeSort( 0,n-1);
	
		printf("\n Sorted array:\n");
		
		for(int i=0; i<n;i++)
 			printf(" %d ",a[i]);
 			
return(0);

}

void MergeSort( int p,int q)
{
	int mid=(p+q)/2;
	
	if(p<q)
	{
			MergeSort(p,mid);
			MergeSort(mid+1,q);
			Merge(p,q);	
	}
				
}


void Merge( int beg , int end)
{
	int mid=(beg+end)/2;
	int i=beg,j=mid +1,k=0;
	int b[100];
	
	while((i<=mid )&& (j<=end))
	{
			if(a[i]<a[j])
				{
				 	b[k]=a[i];
				 	i++;
				}
			else
				{
					b[k]=a[j];
					j++;
				}
		k++;
	}
	
	while(i<=mid)
	{
		b[k]=a[i];
		k++;
		i++;
	}
	while(j<=end)
	{
		b[k]=a[j];
		k++;
		j++;
	}
	
	for(i=beg;i<=end;i++)
		a[i]=b[i-beg];
}






















