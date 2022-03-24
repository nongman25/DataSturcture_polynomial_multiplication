#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DEGREE_A 9
#define MAX_DEGREE_B 9
#define MAX_TERM_NUM_A 3
#define MAX_TERM_NUM_B 3
#define MAX_TERM_NUM_D 8

typedef struct
{
   int degree;
   int* coef;
} coef_poly;

typedef struct
{
   int coef;
   int expo;
} term;

void print_mult_sequence(int ,int);
void print_coef_poly(coef_poly*);

int main()
{
   coef_poly A;
   A.coef = (int*) malloc(sizeof(int)*(MAX_DEGREE_A+1));

   coef_poly B;
   B.coef = (int*) malloc(sizeof(int)*(MAX_DEGREE_B+1));

   term* D = (term*) malloc(sizeof(term)*MAX_TERM_NUM_D);

   int coef_tmp, expo_tmp;

   for(int i=0; i<MAX_TERM_NUM_A; i++)
   {
      printf("polynomial A의 '%d' 번째 항 입력 (계수 지수) 형식으로 입력\n" ,i+1);
      scanf("%d %d",&coef_tmp,&expo_tmp);
      A.coef[expo_tmp] = coef_tmp;
      A.degree= (A.degree<expo_tmp) ? expo_tmp: A.degree;
      fflush(stdin);
   }

   for(int i=0; i<MAX_TERM_NUM_B; i++)
   {
      printf("polynomial B의 '%d' 번째 항 입력 (계수 지수) 형식으로 입력\n" ,i+1);
      scanf("%d %d",&coef_tmp,&expo_tmp);
      B.coef[expo_tmp] = coef_tmp;
      B.degree= (B.degree<expo_tmp) ? expo_tmp: B.degree;
      fflush(stdin);
   }

   printf("A 다항식\n");
   print_coef_poly(&A);
   printf("B 다항식\n");
   print_coef_poly(&B);

}

void print_coef_poly(coef_poly* A)
{
   int count =3;
   for(int i=A->degree; i>=0; i--)
   {
      if(A->coef[i])
      {
         printf("%dX^%d ",A->coef[i], i);
         if(--count>0)
            printf(" + ");
      }
   }
   printf("\n");
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