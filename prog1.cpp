#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
  char a[10],ad[10],label[10],opcode[10],operand[10],symbol[10],ch,fnm[15],ab[15];
  int st,diff,diff1,i,address,address1,add,len,alen,finaddr,prevaddr,j=0;
  char mnemonic[15][15]={"LDA","STA","LDCH","STCH","ADD","SUB","MUL","DIV","J","JSUB"};
  int locctr=0x0,start,l,c=0x0,k=0,bol=0,rt,g,cv;
  char code[15][15]={"00","0C","50","54","28","29","3A","3B","3E","3F"};
  FILE *fp1,*fp2,*fp3,*fp4;
  printf("ENTER THE PROGRAM FILE NAME  : \n");
  scanf("%s",&fnm);
  fp1 = fopen("addressed.txt","w"); 
  fp3 = fopen(fnm,"r");
  if(fp3==NULL)
  {
      printf("FILE NAME DOES NOT EXIST\n");
      printf("_____________________________\n");
exit(1);
  }
  for(i=0;i<11;i++)
  printf("-------");
  printf("--");
 printf("\n|\t\t\t\tINPUT FILE:\t\t\t\t      |\n");
 for(i=0;i<11;i++)
  printf("-------");
  printf("--\n\n");
  ch=fgetc(fp3);

int df=0;
  for(i=0;i<10;i++)
  printf("___");
  printf("\n");
  for(i=0;ch!=EOF;i++)
  {df++;
   printf("%c",ch);


   ch=fgetc(fp3);
  }
 rewind(fp3);
 for(i=0;i<10;i++)
  printf("---");
  printf("\n");
  for(i=0;i<10;i++)
  printf("___");
printf("\n\n\tSTART OF PASS 1 \n");
for(i=0;i<10;i++)
  printf("---");

