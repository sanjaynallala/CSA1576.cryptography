#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k=0;
    char str[20],key[20],str1[20],str2[20];
    printf("Enter plain text:");
    scanf("%s",str);
    printf("Enter key:");
    scanf("%s",key);
    for(i=0;i<strlen(str);i+=2)
    {
        if(str[i+1]=='\0')
        {
            str[i+1]='x';
            str[i+2]='\0';
        }
        if(str[i]==str[i+1])
        {
            str[i+1]='x';
            str[i+2]='\0';
        }
    }
    for(i=0;i<strlen(str);i+=2)
    {
        for(j=0;j<strlen(key);j++)
            if(key[j]==str[i])
                break;
        if(j==strlen(key))
            j--;
        str1[k++]=key[j];
        for(j=0;j<strlen(key);j++)
            if(key[j]==str[i+1])
                break;
        if(j==strlen(key))
            j--;
        str1[k++]=key[j];
    }
    str1[k]='\0';
    printf("Encrypted Cipher Text : %s\n",str1);
}
