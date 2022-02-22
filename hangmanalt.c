#include <stdio.h>
#include<string.h>
int main()
{
char a[10] = "sky";
char c[2], b;
int i = 0, j = 0, d = 0, l = 0, e = 0, ch = 2, f = 0;
l = strlen(a);
printf("Guess me : \n");
for(i = 0;i < l;i++)
{
c[i] = '-';
printf("%c", c[i]);
}
printf("\n");
while(d != l)
{
printf("\nEnter a character : ");
scanf("%c", c);
e = d;
for(j = 0;j < l;j++)
{
if(b == a[j])
{
if(b == c[j])
continue;
c[j] = b;
d++;
if(d == l)
printf("\n----You are great---- ");
}
else if(c[j]==0)
{
c[j] = '-';
}
}
e = d;
printf("\n");
for(j = 0;j < l;j++)
{
printf("%c",c[j]);
}
printf("\n");
if(e == f)
{
if(ch == 0)
{
printf("\nSorry you have no more choices ");
break;
}
printf("You have %d choices ",ch);
--ch;
}
f = e;
}
return 0;
}