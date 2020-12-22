#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int fib(int n) {
   int i, j;
   if (n<2)
      return n;
   else {
      #pragma omp task shared(i)
      i=fib(n-1);
      #pragma omp task shared(j)
      j=fib(n-2);
      #pragma omp taskwait
      return i+j;
   }
}

void factfibo(int fibNum) {
    int divisor = 2;

    if (fibNum <= 5) {
        printf("%d", fibNum);

    } else {
        while (fibNum != 1) {

            if (fibNum % divisor == 0) {
                printf("%d ", divisor);
                fibNum = fibNum / divisor;

                if (fibNum != 1)
                    printf("x ");

            } else {
                divisor++;
            }
        }
    }
}



int main(int argc, char **argv){
   int valor = 2;
   int n, result;

   char *a = argv[1];
   n = atoi(a);
   
   #pragma omp parallel
   {
      #pragma omp single
      {
          for(size_t i = 0; i<=n;i++)
          {
              //result = fib(n);
              
              result= fib(i);
              printf("fibonacci de (%d) %d =",i,result);
              if(result<5)
              {
                  printf("%d\n",result); 

              }else
              {
                  while (result != 1)
                  {
                      if(result%valor==0)
                      {
                          printf("%d",valor);
                          result=result/valor;
                          if (result != 1)
                          {
                              printf("X");
                          }
                          
                      }else
                      {
                          valor++;
                      }
                      
                  }

                  valor = 2;
                  printf("\n");
                  
              }
              //factfibo(result);

             // result2= factfibo(result);
              //printf("FIB(%d) = %ld\n", i,result2);
          }
          
      }

      
   }
   //printf("Result is %d\n", result);
}
