#include<iostream.h>
int main()
{  const int N=5;
   const int M=5;
int a[N][M],b[N*M];
for(int i=0;i<N;i++)
{       for(int j=0;j<M;j++)
        {a[i][j]=random(10);
        cout.width(3);
        cout<<a[i][j]<<' '; }
cout<<endl;
}

// ��������� � ����������
 for(int i=0;i<M;i++)
 for(int j=0;j<N;j++)
 b[i*M+j]=a[j][i];

cout<<endl;
 //���������� � ���������

for(int i=0;i<N*M;i++)
{b[i]=random(10);
cout<<b[i]<<' '; }
cout<<endl;
int t=0;
for(int i=0;i<N;i++)
{       for(int j=0;j<M;j++)
        {a[i][j]=b[i*M+j];
        cout.width(3);
        cout<<a[i][j]<<' '; }
cout<<endl;
}

//�������� ��������
/*for(int i=0;i<N;i++)
       for(int j=0;j<N/2;j++)
       {if(i<(N/2))
        {int x=a[i][j];
        a[i][j]=a[N/2+i][N/2+j];
        a[N/2+i][N/2+j]=x;}
        if(i>=(N/2))
        {int x=a[i][j];
        a[i][j]=a[i-N/2][N/2+j];
        a[i-N/2][N/2+j]=x;
        }
        } */
//���� N-�����.
for(int i=0;i<N;i++)
       for(int j=0;j<N/2;j++)
       {if(i<(N/2))
        {int x=a[i][j];
        a[i][j]=a[N/2+i][N/2+j];
        a[N/2+i][N/2+j]=x;}
        if(i>(N/2))
        {int x=a[i][j];
        a[i][j]=a[i-N/2][N/2+j];
        a[i-N/2][N/2+j]=x;
        }
        }
cout<<endl;
for(int i=0;i<N;i++)
{       for(int j=0;j<M;j++)
        {
        cout.width(3);
        cout<<a[i][j]<<' '; }
cout<<endl;
}




system("pause");
return 0;
}
