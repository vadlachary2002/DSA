
int* getMax(int operations_count, char** operations, int* result_count) {
    int i,*arr,top=-1,*m,y=0;
    arr=(int *)malloc(sizeof(int)*100000);
    m=(int *)malloc(sizeof(int)*100000);
    for(i=0;i<operations_count;i++){
        int a;
        a=*(*(operations+i)+0)-48;
        //printf("%d \n",a);
        if(a==1){
            int sum=0,k=2,l=strlen(*(operations+i));
            while(k<l){
                sum+=(*(*(operations+i)+k)-48)*pow(10,l-k-1);
                k++;
            }
            if(top==100000){
                printf("top exceeded\n");
            }else{
                top++;
                *(arr+top)=sum;
            
                printf("num=%d \n",sum);
            }
            
        }else if(a==2){
            if(top>=0){
                top--;
            }
            
        }else{
            int ma=-1000,k=top+1,mk=0;
            printf("top=%d\n",top);
            while(mk<k){
                if(*(arr+mk)>ma){
                    ma=*(arr+mk);
                }
                mk++;
            }
            *(m+y)=ma;
            y++;
        }
    }
    *result_count=y;
    return m;
}

