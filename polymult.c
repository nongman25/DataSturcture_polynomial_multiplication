#include <stdio.h>

#define MAX_DEGREE_A 9
#define MAX_DEGREE_B 9
#define MAX_TERM_NUM_A 3
#define MAX_TERM_NUM_B 3


void print_mult_sequence(int ,int);
int main()
{
   int a,b;
   printf("insert term_num A\n");
   scanf("%d",&a);

   printf("insert term_num B\n");
   scanf("%d",&b);

   printf("a= %d, b= %d\n",a,b);
   print_mult_sequence(a,b);
}

void print_mult_sequence(int a, int b)
{
   for(int i=a+b; i>=0;i--)
   {
      int depts= a+b-i;
      for(int j=depts; j>=0;j--)
      {
         if((a-j)>=0&&(b-depts+j)>=0)
         {
            printf("comepare a[%d] with b[%d]\n",(a-j),(b-depts+j));
         }
      }
   }


}