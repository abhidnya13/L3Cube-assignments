#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <mpfr.h>

int compare_int (const void *a, const void *b)
{
  const int *da = (const int *) a;
  const int *db = (const int *) b;

  return (*da > *db) - (*da < *db);
}

int main() {

	int op;
	bool res=0; 
	long int per=100;
	int no, *ptr,*temp,n1,i;
	double n,k,j,pcomp,cnt=0;
	double x;
//	******************************************Calculate original probability ****************************************
	mpfr_t p,t; 
	mpfr_init2(p,100); // declare probability with a pecision of 100 so that smaller probabilities dont get truncated to zero
	mpfr_set_d (p, 1.0, MPFR_RNDD); //initialise p with 1.0
	mpfr_init2(t,100);
	mpfr_set_d (t, 1.0, MPFR_RNDD);
	printf("Enter the number of people :\n"); //Number of people to form a group of
	scanf("%lf",&k);
	printf("Choose :\nLeap Year(1)\nNormal Year(2)\n"); // Choose if its a normal year or a leap year
	scanf("%d",&op);
	if(op=='y')
		n=366;
	else
		n=365;		
	for(i=1;i<=k;i++) //this loop calculates the probability that two people dont have birthdays on the same day
	{
		x=(n-i+1)/n;
		mpfr_mul_d(p, p,x, MPFR_RNDD);
	}
	mpfr_sub(p,t,p,MPFR_RNDD); // 1-probability that no two people have birthdays on the same day
	mpfr_mul_si(p,p,per,MPFR_RNDD); //Percentage
	printf ("Expected Probability in Percentage : ");
	mpfr_printf ("%.64Rf ", p);
    putchar ('\n');
    mpfr_clear(p);
    mpfr_clear(t);
    
//  ****************************************Verification of this paradox**********************************************
    
    printf("Enter the number of trials you want to take :\n"); //number of trials to take to confirm the resultant probaility
    scanf("%d",&no);	
    ptr=(int *)malloc(k*sizeof(int)); //Assign memory space for an array of k people for each test case
    temp=ptr;
    for(j=0;j<no;j++)
    {
    	ptr=temp;
   		res=0;
    	for(i=0,n1=(int)n;i<k;i++,ptr++)
    		*ptr=(rand()%n1)+1; //randomly select nth day from 365/366 days for assigning birthdays
    	ptr=temp;
    	qsort(ptr,k,sizeof(int),compare_int); //sort the array using quick sort
    	ptr=temp;
    	for(i=0;i<k;i++,ptr++)
   	 	{
    		if(*ptr==*(ptr+1)) //comparing if two people have birthdays on the same day
				{
					res=1;  
					break;
				}  		
		}		
		if(res==1)
			cnt++; //increase the count of tests which turned out to be positive from total number of trials
	}
	pcomp = (cnt/no) *100; //percentage of success cases 
	printf("Actual Probability in Percentage : %lf  \n",pcomp);	
	return 0;
}

