void search(int,int,int [][9]);
void checkbyurow(int,int [][9]);
void checkbyucoloumn(int,int [][9]);
void checkbyusquare(int,int,int [][9]);
void checkbyupdown(int,int,int,int [][9]);
int checkbyrow(int,int,int [][9]);
int checkbycoloumn(int,int,int [][9]);
int checkbysquare(int,int,int,int [][9]);
void showtable(int [][9]);
void coloumn(int,int&,int&);
void switchf(int,int&);
void filltable(int a[][9])      //To fill in the shudoku
{
int i,j;
gotoxy(1,3);
cout<<"enter the full shudoku";
for(i=0;i<9;i=i+1)
{
gotoxy(1,4+i);
 for(j=0;j<9;j=j+1)
 {
 gotoxy(1+j,4+i);
 cin>>a[i][j];
 cout<<" ";
 }
}
}


void showtable(int a[][9])       // To display the table
{
int i,j;
gotoxy(1,3);
for(i=0;i<9;i=i+1)
{
 for(j=0;j<9;j=j+1)
 {
 cout<<" "<<a[i][j];
 }
cout<<"\n";
}
}

void shudoku(int s[][9])          //To check the elements by all the ways
{
int d,e,f,k,i,j,l,m,n,o,p,q=0,r,t,u;
while(q!=10)
{
k=0;
l=0;
f=0;
d=0;
r=0;
  while(k!=2)
   {
     for(i=0;i<9;i++)
       {
	 for(j=0;j<9;j++)
	  {
	    if(s[i][j]==0)
	      {
	       search(i,j,s);
	      }
	  }
     }
     k=k+1;
   }

  while(l!=2)
   {
     for(n=0;n<9;n++)
      {
	for(o=0;o<9;o++)
	{
	 if(s[n][o]==0)
	  {
	    for(m=1;m<=9;m++)
	      {
		checkbyupdown(m,n,o,s);
	      }
	  }
	}
      }
    l=l+1;
  }
  while(f!=2)
  {
  for(p=0;p<9;p++)
  {
  checkbyurow(p,s);
  }
  f=f+1;
  }
 while(d!=2)
  {
  for(e=0;e<9;e++)
  {
  checkbyucoloumn(e,s);
  }
  d=d+1;
  }
 while(r!=2)
 {
 for(t=0;t<9;t=t+3)
 {
 for(u=0;u<9;u=u+3)
 {
 checkbyusquare(t,u,s);
 }
 }
 r=r+1;
 }
 q=q+1;
 }
}


void search(int p,int q,int z[][9])     // Search the elements by row coloumn and square
{
int k,a,b,c,d,l,e=0;
for(k=1;k<=9;k++)
{
a=checkbyrow(k,p,z);
b=checkbycoloumn(k,q,z);
c=checkbysquare(k,p,q,z);
if(a==0&&b==0&&c==0)
{
d=k;
e=e+1;
}
}
if(e==1)
{
z[p][q]=d;
// cout<<"check by search";
//cout<<p<<" "<<" "<<q<<z[p][q]<<"\n";
}
}


int checkbycoloumn(int a,int b,int d[][9])    //To check the elements is in the coloumn or not
{
int l,c=0;
for(l=0;l<9;l++)
{
if(a==d[l][b])
{
c=c+1;
}
}
return c;
}

int checkbyrow(int a,int b,int d[][9])      // To check the elements is in the row or not
{
int l,c=0;
for(l=0;l<9;l++)
{
if(a==d[b][l])
{
c=c+1;
}
}
return c;
}



int checkbysquare(int a,int b,int c,int f[][9])  //to check the elements is in the square or not
{
int n,m,i=0,j=0,d=0;
switchf(b,i);
switchf(c,j);
for(n=i;n<i+3;n++)
{
for(m=j;m<j+3;m++)
{
if(a==f[n][m])
{
d=d+1;
}
}
}
return d;
}


void checkbyupdown(int a,int b,int c,int d[][9])
{
int p,q,r,t,u,v,y,w=0,x=0;
u=checkbyrow(a,b,d);
v=checkbycoloumn(a,c,d);
y=checkbysquare(a,b,c,d);
coloumn(c,w,x);
p=checkbycoloumn(a,w,d);
q=checkbycoloumn(a,x,d);
coloumn(b,w,x);
r=checkbyrow(a,w,d);
t=checkbyrow(a,x,d);
if(p!=0&&q!=0&&r!=0&&t!=0&&u==0&&v==0&&y==0)
{
 d[b][c]=a;
//  cout<<"check by updown";
// cout<<b<<" "<<c<<d[b][c]<<"\n";
}
}



void checkbyurow(int a,int z[][9])
{
int k,l,d,f,p,q,r;
for(k=1;k<=9;k++)
{
f=0;
p=checkbyrow(k,a,z);
 if(p==0)
  {
   for(l=0;l<9;l++)
   {
   if(z[a][l]==0)
    {
     q=checkbycoloumn(k,l,z);
     r=checkbysquare(k,a,l,z);
     if(q==0&&r==0)
     {
     d=l;
     f=f+1;
     }
    }
   }
  if(f==1)
  {
  z[a][d]=k;
//   cout<<"check by urow";
//  cout<<a<<" "<<" "<<d<<z[a][d]<<"\n";
  }
 }
}
}
void checkbyucoloumn(int a,int z[][9])
{
int k,l,d,f=0,p,q,r;
for(k=1;k<=9;k++)
{
f=0;
p=checkbycoloumn(k,a,z);
 if(p==0)
  {
  for(l=0;l<9;l++)
   {
    if(z[l][a]==0)
    {
     q=checkbyrow(k,l,z);
     r=checkbysquare(k,l,a,z);
     if(q==0&&r==0)
     {
     d=l;
     f=f+1;
     }
    }
   }
  if(f==1)
  {
  z[d][a]=k;
//   cout<<"check by ucoloumn";
//  cout<<d<<" "<<" "<<a<<z[d][a]<<"\n";
  }
 }
}
}
void checkbyusquare(int a,int b,int z[][9])
{
int k,h,c,i,j,d,e,f,g;
 for(k=1;k<=9;k++)
 {
 h=0;
 c=checkbysquare(k,a,b,z);
 if(c==0)
 {
   for(i=a;i<=a+2;i++)
   {
   for(j=b;j<=b+2;j++)
   {
   if(z[i][j]==0)
   {
   d=checkbyrow(k,i,z);
   e=checkbycoloumn(k,j,z);
   if(d==0&&e==0)
   {
    f=i;
    g=j;
    h=h+1;
   }
   }
   }
   }
 }
 if(h==1)
 {
 z[f][g]=k;
// cout<<"check by usquare";
// cout<<f<<" "<<g<<" "<<z[f][g]<<"\n";
 }
 }
}


void switchf(int t,int &k)    //to check where to start the search
{
switch(t)
{
case 0:
case 1:
case 2: k=0;
	break;
case 3:
case 4:
case 5: k=3;
	break;
case 6:
case 7:
case 8: k=6;
	break;
}
}
void coloumn(int a,int &u,int &v)         // To Specify and check which group of coloumn it is
{
 switch(a)
 {
 case 0: u=1;
	 v=2;
	 break;
 case 1: u=0;
	 v=2;
	 break;
 case 2: u=0;
	 v=1;
	 break;
 case 3: u=4;
	 v=5;
	 break;
 case 4: u=3;
	 v=5;
	 break;
 case 5: u=3;
	 v=4;
	 break;
 case 6: u=7;
	 v=8;
	 break;
 case 7: u=6;
	 v=8;
	 break;
 case 8: u=6;
	 v=7;
	 break;
 }
}
