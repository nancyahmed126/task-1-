# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

#define M 2
#define N 2

int A [M][N];
int B [M][N];
int C [M][N];

struct v {
 int i;
 int j; 
};

void *sum(void *param);

int main() {
    
     
     int a,b;
     for (a=0;a<2;a++){
       for (b=0;b<2;b++){
           scanf("%d",&A[a][b]);
     }
  }
   
     int h,k;
     for (h=0;h<2;h++){
       for (k=0;k<2;k++){
            scanf("%d",&B[h][k]);
     }
  }

     int i,j;
     for(i=0; i<M ; i++) {
        for(j=0; j<N; j++) {
           struct v *data =(struct v*) malloc(sizeof(struct v));
           data->i=i;
           data->j=j;

           pthread_t tid;
           pthread_create(&tid,NULL,sum,data);
           pthread_join(tid,NULL);
        
        }
     }
    for (i=0;i<M;i++){
        for(j=0;j<N;j++){
           printf("%d\n", C[i][j]);
        }
        printf("\n");
     }
}


void *sum(void*param) {
  struct v *data =param;
  C[data->i][data->j] = A[data->i][data->j] + B[data->i][data->j];
  pthread_exit(0);
}    












       
  





 


