#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
check string from i=strlen(a)-1 to 0
check sentence from j= 0 to strlen(b)
j updates to p
*/
int found=0;

int bad_symbol[27]={0};

int horspool(char* a,char* b)
{
	int count=0;
	int comparision=0;
	
	int j = strlen(a)-1;
	int i=j;
	int p=i;
	while(j<strlen(b))
	{
		
		if(a[i]==b[j])
		{
			count++;
			comparision++;
			//printf("comparision=%d,j=%d\n",comparision ,j);
			i--;
			j--;

			if(count==strlen(a))
			{
				found=1;
				return comparision;
			}
		}
		else
		{
			if(b[p]<='z' && b[p]>='a')
				p = p + bad_symbol[b[p]-97+1];
		    else
		    	p=p+strlen(a);
		    
			i = strlen(a)-1;
			j=p;
			count=0;
			comparision++;
			//printf("comparision=%d,j=%d\n",comparision ,j);
		}
		
	}

	return comparision;
}


void make_b_s_s_t(char * a)
{
	for (int i = 0; i < strlen(a)-1; ++i)
	{
		for (int j = 1; j <=26; ++j)
		{
			
			if(a[i]<='z' && a[i]>='a')
			if( (-97+a[i]+1)== j ){
				bad_symbol[j] = strlen(a)-i-1;
				
			}

		}
	}

	for (int i = 1; i <=26 ; ++i)
	{
		if(bad_symbol[i]==0)
			bad_symbol[i]=strlen(a);
	}

}

int main()
{
	int comparision;

	char string[10];
	char* a = &string[0];
	char sentence[20];
	char* b = &sentence[0];

	printf("Enter char to be searched:\n");
    scanf("%s",a);

    printf("Enter sentence :\n");
    scanf("%s",b);

    make_b_s_s_t(a);

    printf("\n");
    for (int i = 1; i <=26 ; ++i)
    {
    	printf("%d\t",bad_symbol[i] );
    }

    comparision=horspool(a,b);

    printf("you entered:%s\n",a );

    printf("ans = %d, found = %d\n", comparision,found);

}
