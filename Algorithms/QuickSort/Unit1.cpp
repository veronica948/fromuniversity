#include <conio.h>
#include <iostream.h>
#include <ctime.h>

void swap(int &a, int &b)
{
        int tmp;
        tmp  = a;
        a = b;
        b = tmp;
}

//last
/*
int Findq(int* a, int p, int r)
{
        int x, q;
        x = a[r];
        q = p;
        for (int i=p; i<=r;i++)
                {
	        if (a[i]<=x)
	                {
                        swap(a[i],a[q]);
                        q++;
                	}
                }
        q--;
        return q;
}
*/
//first
/*
int Findq(int* a, int p, int r)
{
        int x, q;
        x = a[p];
        q = r;
        for (int i=r; i>=p;i--)
                {
	        if (a[i]>=x)
	                {
                        swap(a[i],a[q]);
                        q--;
                	}
                }
        q++;
        return q;
}
*/

//middle
/*
int Findq(int* a, int p, int r)
{      int s=(p+r)/2;
        int x, q;
        x = a[s];
        q = p;
        for (int i=p; i<=s;i++)
                {
	        if (a[i]<=x)
	                {
                        swap(a[i],a[q]);
                        q++;
                	}
                }
        s=--q;
        q=r;
        for (int i=r; i>=s;i--)
                {
	        if (a[i]>=x)
	                {
                        swap(a[i],a[q]);
                        q--;
                	}
                }
        q++;
        return q;
}
*/

//random
int Findq(int* a, int p, int r)
{      int s=rand()%(r-p+1)+p;
        int x, q;
        x = a[s];
        q = p;
        for (int i=p; i<=s;i++)
                {
	        if (a[i]<=x)
	                {
                        swap(a[i],a[q]);
                        q++;
                	}
                }
        s=--q;
        q=r;
        for (int i=r; i>=s;i--)
                {
	        if (a[i]>=x)
	                {
                        swap(a[i],a[q]);
                        q--;
                	}
                }
        q++;
        return q;
}
void Quicksort(int *a,int p, int r)
{
        int q;
        if (p < r)
                {
                q = Findq (a, p, r);
                Quicksort (a, p, q-1);
                Quicksort (a, q+1, r);
                }
}
/*
void Bubble(int *a, int n)
{
         for(int i=0;i<n;i++)
                for(int j=n-1;j>i;j--)
                       if (a[j]<a[j-1]) swap(a[j],a[j-1]);
}
*/
void  main()
{
        int *a;
        int n;
        cout<<"Input the number of array elements: "; cin>>n;
        a=new int [n];
        randomize();
        for(int i=0;i<n;i++)
                {
                a[i]=random(100);
                //cout<<" "<<a[i];
                }
        clock_t  start, end;
        start=clock();          //  Quicksort
        Quicksort(a,0,n-1);
        end=clock();

       /* start=clock();          // Bubblesort
        Bubble(a,n);
        end=clock(); */

        cout<<"\nSelected array:\n";

        for(int i=0;i<n;i++)
                {
                cout<<" "<<a[i];
                }
        cout<<"\nProgramm has a time: "<<(end-start)/CLOCKS_PER_SEC<<" sec"<<endl;

        while(!kbhit());
        delete[] a;
}
 