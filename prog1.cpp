#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
  char a[10],ad[10],lab[10],op_code[10],operand[10],symb[10],ch,file_name[15],ab[15];
  int st,diff,diff1,i,address,address1,add,length,alength,final_addr,prev_addr,j=0;
  char mnem[15][15]={"LDA","STA","LDCH","STCH","J","JSUB"};
  int loc_count=0,start,l,c=0,k=0,bol=0,rt,g,cv;
  char code[15][15]={"10","FF","01","85","3E","4J"};
  FILE *fp1,*fp2,*fp3,*fp4;
  printf("ENTER THE PROGRAM FILE NAME  : \n");
  scanf("%s",&file_name);
  fp1 = fopen("addressed.txt","w");  //file will be generated with address
  fp3 = fopen(file_name,"r");
  if(fp3==NULL)
  {
      printf("FILE NAME DOES NOT EXIST\n");

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

fp2=fopen("symb_Tab.txt","w");
  fscanf(fp3,"%s%s%s%X",lab,op_code,operand,&address);

    if(strcmp(operand,"START")==0)
    {
            start=address;
            loc_count=start;
            prev_addr=loc_count;
            c=address;
        fprintf(fp1,"%s\t%s\t%X\n",op_code,operand,address);
    }
    else
        loc_count=0x0;
fscanf(fp3,"%s%s%s",lab,op_code,operand);
int h=0;
for(h;strcmp(op_code,"END")!=0;h++)
  {
      if(strcmp(lab,"**")!=0)
        fprintf(fp2,"%s\t%X\n",lab,loc_count);

        if(strcmp(op_code,"BYTE")==0)
            {
                fprintf(fp1,"%X\t%s\t%s\t%s\t\n",address,lab,op_code,operand);
                length=strlen(operand);
                address+=length-3;
                loc_count+=length-3;
            }
            else if(strcmp(op_code,"RESB")==0)
           {
                fprintf(fp1,"%X\t%s\t%s\t%s\n",address,lab,op_code,operand);
                address+=(atoi(operand));   //string arg into integral value
                loc_count+=(atoi(operand));
           }
    else if (strcmp(op_code,"RESW")==0||strcmp(op_code,"WORD")==0)
    {
        fprintf(fp1,"%X\t%s\t%s\t%s\n",address,lab,op_code,operand);
        address+=(3*(atoi(operand)));
         loc_count+=(3*(atoi(operand)));
    }
   else if (strcmp(op_code,"LDA")==0||strcmp(op_code,"STA")==0||strcmp(op_code,"LDCH")==0||strcmp(op_code,"STCH")==0||strcmp(op_code,"ADD")==0||strcmp(op_code,"SUB")==0||strcmp(op_code,"MUL")==0||strcmp(op_code,"DIV")==0||strcmp(op_code,"J")==0||strcmp(op_code,"JSUB")==0)
   {
      fprintf(fp1,"%X\t%s\t%s\t%s\n",address,lab,op_code,operand);
       address+=3;
       loc_count+=3;
   }
   else
   {
       printf("\t\t\t\t\n\n\n\nINVALID!!!!!\n\n\n\n");              //error checked for input file
       exit(1);
   }
   fscanf(fp3,"%s%s%s",lab,op_code,operand);
  }
  fprintf(fp1,"%X\t%s\t%s\t%s\n",address,lab,op_code,operand);
  l=address;
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  printf("\n");
  for(i=0;i<12;i++)
  printf("___");
    printf("\nMIDDLEWARE FILE  : AFTER ADRESSING |\n");
for(i=0;i<12;i++)
  printf("---");
printf("\n");
for(i=0;i<12;i++)
  printf("___");
  printf("\n");
  fp1=fopen("addressed.txt","r");
  ch=fgetc(fp1);
  while(ch!=EOF)
  {
   printf("%c",ch);
   ch=fgetc(fp1);
  }
  fclose(fp1);
  for(i=0;i<12;i++)
  printf("---");
  printf("\n\nTHE lengthGTH OF THE PROGRAM IS : %X",l-c);  //ADDRESSING DONE IN MEDIATOR FILE
    //AFTER ADDRESING :

printf("\n\nsymb TABLE CREATED\n");
for(i=0;i<11;i++)
  printf("_______");
  printf("__");
  printf("\n|\t\t\t\tsymb TABLE :\t\t\t\t       |");
for(i=0;i<11;i++)
  printf("-------");
  printf("--");
  printf("\n");

for(i=0;i<15;i++)
  printf("_");
  printf("\n");
  fp2=fopen("symb_Tab.txt","r");
  ch=fgetc(fp2);
  for(h=0;ch!=EOF;h++)
  {
   printf("%c",ch);
   ch=fgetc(fp2);
  }
fclose(fp2);
for(i=0;i<15;i++)
  printf("-");
  printf("\n");
  for(i=0;i<15;i++)
  printf("-");
printf("\n\nEND OF PASS 1");
printf("\n\nSTART OF PASS 2 \n");
 fp1 = fopen("Result.txt","w");
  fp2 = fopen("symb_tab.txt","r");
  fp3 = fopen("addressed.txt","r");
  fp4 = fopen("ObjCode.txt","w");

  fscanf(fp3,"%s%s%s",lab,op_code,operand);

  for(h=0;strcmp(op_code,"END")!=0;h++)
  {
   prev_addr=address;
   fscanf(fp3,"%X%s%s%s",&address,lab,op_code,operand);
  }

  final_addr=address;
  fclose(fp3);

 fp3=fopen("addressed.txt","r");

  fscanf(fp3,"%s%s%s",lab,op_code,operand);
  if(strcmp(op_code,"START")==0)
  {
   fprintf(fp1,"\t%s\t%s\t%s\n",lab,op_code,operand);
   fprintf(fp4,"H^%s^00%s^0021\n",lab,operand);
   fscanf(fp3,"%X%s%s%s",&address,lab,op_code,operand);
   st=address;
   diff=prev_addr-st;
    fprintf(fp4,"T^00%X^%X",address,diff);
  }
  for(h=0;strcmp(op_code,"END")!=0;h++)
  {
   if(strcmp(op_code,"BYTE")==0)
   {
    fprintf(fp1,"%X\t%s\t%s\t%s\t",address,lab,op_code,operand);
    length=strlen(operand);
    alength=length-3;
    fprintf(fp4,"^");
    for(i=2;i<(alength+2);i++)
    {
     itoa(operand[i],ad,16);    //convert integral value to null terminated string with given base here 16
     fprintf(fp1,"%s",ad);
     fprintf(fp4,"%s",ad);
    }
    fprintf(fp1,"\n");
   }
   else if(strcmp(op_code,"WORD")==0)
   {
    length=strlen(operand);
    itoa(atoi(operand),a,10);
    fprintf(fp1,"%X\t%s\t%s\t%s\t00000%s\n",address,lab,op_code,operand,a);
    fprintf(fp4,"^00000%s",a);
   }
   else if((strcmp(op_code,"RESB")==0)||(strcmp(op_code,"RESW")==0))
    fprintf(fp1,"%X\t%s\t%s\t%s\n",address,lab,op_code,operand);
   else
   {
   for(g=0;strcmp(op_code,mnem[j])!=0;g++)
     j++;
    if(strcmp(operand,"COPY")==0)
     fprintf(fp1,"%X\t%s\t%s\t%s\t%s0000\n",address,lab,op_code,operand,code[j]);
    else
    {
     rewind(fp2);
     fscanf(fp2,"%s%X",symb,&add);

for(rt=0;strcmp(operand,symb)!=0;rt++)
       fscanf(fp2,"%s%X",symb,&add);
     fprintf(fp1,"%X\t%s\t%s\t%s\t%s%X\n",address,lab,op_code,operand,code[j],add);
     fprintf(fp4,"^%s%X",code[j],add);
    }
   }
   fscanf(fp3,"%X%s%s%s",&address,lab,op_code,operand);
  }
  fprintf(fp1,"%X\t%s\t%s\t%s\n",address,lab,op_code,operand);
  fprintf(fp4,"\nE^00%X",st);

  for(i=0;i<11;i++)
  printf("-------");
  printf("--");
  printf("\n\tMIDDLEWARE FILE IS CONVERTED INTO OBJECT CODE");
printf("\n\n\t\t\tEND OF PASS 2\n");
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);
   for(i=0;i<11;i++)
  printf("-------");
  printf("--");

  for(i=0;i<12;i++)
  printf("  ");
  printf("_______________");
  printf("\n\t\t\tOUTPUT FILE :\n");
  for(i=0;i<12;i++)
  printf("  ");
  printf("-------------\n");
  fp1=fopen("Result.txt","r");
  ch=fgetc(fp1);
  int bv;
  for(i=0;i<11;i++)
  printf("____");
printf("\n");
  for(bv=0;ch!=EOF;bv++)
  {
   printf("%c",ch);
   ch=fgetc(fp1);
  }
  for(i=0;i<11;i++)
  printf("____");
  printf("\n");
for(i=0;i<11;i++)
  printf("----");
  printf("\n Object Code File content:\n");
  for(i=0;i<11;i++)
  printf("_____");
  printf("\n");
  fp4=fopen("ObjCode.txt","r");
  ch=fgetc(fp4);

  for(bv=0;ch!=EOF;bv++)
  {
   printf("%c",ch);
   ch=fgetc(fp4);
  }printf("\n");
  for(i=0;i<11;i++)
  printf("_____");
  printf("\n");
  fclose(fp1);
  fclose(fp3);
  fclose(fp4);
  char fg;
  fg=getchar();
  getchar();
  return 0;
}


