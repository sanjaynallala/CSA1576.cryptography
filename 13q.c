#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 3
int main()
{
    int i,j,k;
    char str[20],str1[20],str2[20];
    int key[N][N],key1[N][N],key2[N][N];
    int mat[N][1],mat1[N][1],mat2[N][1];
    printf("Enter plain text:");
    scanf("%s",str);
    printf("Enter key matrix:\n");
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            scanf("%d",&key[i][j]);
    for(i=0;i<strlen(str);i+=N)
    {
        for(j=0;j<N;j++)
            mat[j][0]=str[i+j]-65;
        for(j=0;j<N;j++)
            for(k=0;k<1;k++)
                mat1[j][k]=0;
        for(j=0;j<N;j++)
            for(k=0;k<N;k++)
                mat1[j][0]+=key[j][k]*mat[k][0];
        for(j=0;j<N;j++)
            mat2[j][0]=mat1[j][0]%26;
        for(j=0;j<N;j++)
            str1[i+j]=mat2[j][0]+65;
    }
    str1[i]='\0';
    printf("Encrypted Cipher Text : %s\n",str1);
    printf("Decrypted Cipher Text : ");
    for(i=0;i<strlen(str);i+=N)
    {
        for(j=0;j<N;j++)
            mat[j][0]=str1[i+j]-65;
        for(j=0;j<N;j++)
            for(k=0;k<1;k++)
                mat1[j][k]=0;
        for(j=0;j<N;j++)
            for(k=0;k<N;k++)
                mat1[j][k]+=key[j][k]*mat[k][k];
        for(j=0;j<N;j++)
            mat2[j][k]=mat1[j][k]%26;
        for(j=0;j<N;j++)
            str2[i+j]=mat2[j][k]+65;
    }
    str2[i]='\0';
    printf("%s\n",str2);
}
