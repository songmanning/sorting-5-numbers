#include <stdio.h>

int max(int x,int y){
    if(x>=y) return x;
    else     return y;
}
int min(int x,int y){
    if(x>=y) return y;
    else     return x;
}

int main(int argc, const char * argv[]) {
    printf("Please input 5 integers：\n");
    int i;
    char ch='a';
    int num[5];//存储输入的5个整数 num[5]={a,b,c,d,e}
    for(i=0;i<5;i++){
        printf("%c=",ch);
        ch++;
        scanf("%d",&num[i]);
    }
    
    int a[2]={ max(num[0],num[1]) , min(num[0],num[1]) }; //数组a[]存储a,b比较结果; a[0]=max(a,b), a[1]=min(a,b)
    int b[2]={ max(num[2],num[3]) , min(num[2],num[3]) }; //数组b[]存储c,d比较结果; b[0]=max(c,d), b[1]=min(c,d)
    
    //用 max(a,b) 与 max(c,d) 比较
    int c[4];//存储a,b,c,d比较结果，c[0]>=c[1]>=c[2],c[0]>=c[3]
    if(a[0]>=b[0]){
        c[0]=a[0]; c[1]=b[0]; c[2]=b[1]; c[3]=a[1];
    }else{
        c[0]=b[0]; c[1]=a[0]; c[2]=a[1]; c[3]=b[1];
    }
    
    //将e正确插入到 有序序列c[0]>=c[1]>=c[2] 中，得到有序序列d[4]
    int d[4];
    int res[5];//存储得到的正确结果，从大到小排列5个数
    if(num[4]>=c[1]){
        if(num[4]>=c[0]){
            d[0]=num[4]; d[1]=c[0]; d[2]=c[1]; d[3]=c[2];
        }else{
            d[0]=c[0]; d[1]=num[4]; d[2]=c[1]; d[3]=c[2];
        }
    }else{
        if(num[4]>=c[2]){
            d[0]=c[0]; d[1]=c[1]; d[2]=num[4]; d[3]=c[2];
        }else{
            d[0]=c[0]; d[1]=c[1]; d[2]=c[2]; d[3]=num[4];
        }
    }
    
    //c[3]插入d[]有序序列中
    if(d[2]>=c[3]){
        if(d[3]>=c[3]){
            res[0]=d[0]; res[1]=d[1]; res[2]=d[2]; res[3]=d[3]; res[4]=c[3];
        }else{
            res[0]=d[0]; res[1]=d[1]; res[2]=d[2]; res[3]=c[3]; res[4]=d[3];
        }
    }else{
        if(d[1]>=c[3]){
            res[0]=d[0]; res[1]=d[1]; res[2]=c[3]; res[3]=d[2]; res[4]=d[3];
        }else{
            res[0]=d[0]; res[1]=c[3]; res[2]=d[1]; res[3]=d[2]; res[4]=d[3];
        }
    }
    
    printf("The result is ");
    for(i=0;i<4;i++){
        printf("%d≥",res[i]);
    }
    printf("%d \n",res[4]);
    return 0;
}
