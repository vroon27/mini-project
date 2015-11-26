#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<string.h>
void main()
{
  char a[10],ad[10],label[10],opcode[10],operand[10],symbol[10],ch,d[3]="**";  int st,diff,i,address,add,len,actual_len,finaddr,prevaddr,j=0;
  char mnemonic[15][15]={"LDA","STA","LDCH","STCH"};
