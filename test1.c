//to configure the first 8 GPIO pins of STM32F103
#include<stdio.h>
struct GPIOx_CRH
{
int mode[8];
int cnf[8];
}crh;
void gpiox_mode_set(struct GPIOx_CRH *,int,int);
void gpiox_mode_config_set(struct GPIOx_CRH *,int,int);
void display(struct GPIOx_CRH *);
#define OUTPUT 1
int main()
{
int conf;
int mod;
char ch;
int pin;
printf("Do you want to configure all pins? y for yes,n for no\n");
scanf("%c",&ch);
if(ch=='y')
{
for(int i=1;i<=8;i++)
{
printf("Enter the mode of %d th pin\n",i);
scanf("%d",&mod);
printf("Enter the configuration of %dth pin\n",i);
scanf("%d",&conf);
gpiox_mode_set(&crh,i,mod);
gpiox_mode_config_set(&crh,i,conf);
}
}
else if(ch=='n')
{
printf("Enter the pin to be configured\n");
scanf("%d",&pin);
printf("Enter the mode of %d th pin\n",pin);
scanf("%d",&mod);
printf("Enter the configuration of %dth pin\n",pin);
scanf("%d",&conf);
gpiox_mode_set(&crh,pin,mod);
gpiox_mode_config_set(&crh,pin,conf);
}
else
printf("Wrong choice\n");
display(&crh);
return 0;
}
void gpiox_mode_set(struct GPIOx_CRH *ptr ,int pin_num,int mode)
{
ptr->mode[pin_num-1]=mode;
}

void gpiox_mode_config_set(struct GPIOx_CRH * ptr,int pin_num,int config)
{
ptr->cnf[pin_num-1]=config;
}
void display(struct GPIOx_CRH * ptr)
{
/*for(int i=0;i<8;i++)
{
printf("%d ",ptr->mode[i]);
}
for(int i=0;i<8;i++)
{
printf("%d ",ptr->cnf[i]);
}*/
int reg[32];
int pos=0,i=0;
while(pos<32)
{
switch (ptr-> mode[i])
{
case 0:
{
reg[pos++]=0;
reg[pos++]=0;
break;
}
case 1:
{

reg[pos++]=1;
reg[pos++]=0;
break;
}
case 2:
{
reg[pos++]=0;
reg[pos++]=1;
break;
}
case 3:
{
reg[pos++]=1;
reg[pos++]=1;
break;
}
default:
{
printf("Error\n");
break;
}
}
//for filling config
switch (ptr-> cnf[i])
{
case 0:
{
reg[pos++]=0;
reg[pos++]=0;
break;
}
case 1:
{
reg[pos++]=1;
reg[pos++]=0;
break;
}
case 2:
{
reg[pos++]=0;
reg[pos++]=1;
break;
}
case 3:
{
reg[pos++]=1;
reg[pos++]=1;
break;
}
default:
{
printf("Error\n");
break;
}
}
i++;
}
for(int i=31;i>=0;i--)
{
printf("%d ",reg[i]);
}
printf("\n0x");
//to hex
int j=1;int sum;
pos=31;
int hex[4]={8,4,2,1};
while(j<=8)
{
sum=0;
for(int k=3;k>=0;k--)
sum+=reg[pos--]*hex[k];
//printf("%d",sum);
char h[6]={'A','B','C','D','E','F'};
if(sum>=10)
printf("%c",h[sum%10]);
else
printf("%d",sum);
j++;
}
/*switch(sum)
{
case 10:
{
printf("A");
break;
}
case 11:
{
printf("B");
break;
}
case 12:
{
printf("C");
break;
}
case 13:
{
printf("D");
break;
}
case 14:
{
printf("E");
break;
}
case 15:
{
printf("F");
break;
}
default:
{
printf(
break;
}*/
}
