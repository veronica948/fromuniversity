package by.bsu.hull;

import by.bsu.Geometry;
import by.bsu.Intersection;

public class ConvexHull {

	private static void sort(int l, int r,Point p[])//соритровка дл€ √рэххема
	{
		
		double sep=p[l + (r - l) / 2].x-p[0].x;
		double len=Geometry.length(p[0].x, p[0].y, p[l + (r - l) / 2].x, p[l + (r - l) / 2].y);
	    int i = l;
	    int j = r;
	    while(i <= j)
	    {

	    	while((p[i].x-p[0].x)/Geometry.length(p[0].x, p[0].y, p[i].x, p[i].y) > sep/len) i++;//сравниваем косинусы текузего вектора с вектором (1,0)
	        while((p[j].x-p[0].x)/Geometry.length(p[0].x, p[0].y, p[j].x, p[j].y) < sep/len) j--;
	        if(i <= j)
	        {
	           Point tmpp=new Point();
	            tmpp.copy(p[i]);
	            p[i].copy(p[j]);
	            p[j].copy(tmpp);
	            i++;
	            j--;
	        }
	    }
	    if (i<r)
	    	sort(i, r,p);

	    if (l<j)
	    	sort(l,j,p);
	}
	public static int graham(Point p[], int resHull[], int n)//√рэххем. в обоих случа€х функции составл€ют массив resHull индексов точек выпуклой оболочки
	{
		int imin=0;
		for (int i=0;i<n;i++)
		{
			if (p[i].y<p[imin].y || (p[i].y==p[imin].y && p[i].x<p[imin].x))
			{
				imin=i;
			}
		}
		Point tmpp=new Point();
		tmpp.copy(p[imin]);
		p[imin].copy(p[0]);
		p[0].copy(tmpp);//помещаем точку минимума в начало
		
		sort(1,n-1,p);//сортируем с первой точки до конца
		int stack[]=new int[n];
		for (int i=0;i<n;i++) stack[i]=-1;
		int last=1;
		stack[0]=0;
		stack[1]=1;
		for (int i=2;i<n;i++)
		{
			if (Intersection.positionRelative(p[i].x, p[i].y, p[stack[last-1]].x, p[stack[last-1]].y, p[stack[last]].x, p[stack[last]].y)==-1)
			{//если точка левее, то добавл€ем еЄ в стек
				last++;
				stack[last]=i;
			}
			else
			{
				stack[last]=-1;//иначе выталкиваем точку из стека
				last--;
				i--;
			}
		}
		int i=0;
		while (stack[i]!=-1)
		{
			resHull[i]=stack[i];
			i++;
		}
		return i;
	}
	
	public static int jarvis(Point p[], int resHull[], int n)
	{
		int imin=0;
		for (int i=0;i<n;i++)//находим минимум
		{
			if (p[i].y<p[imin].y || (p[i].y==p[imin].y && p[i].x<p[imin].x))
			{
				imin=i;
			}
		}
		int nRes=0;
		resHull[nRes++]=imin;
		boolean fl=true;
		boolean orient=true;
		while (fl)
		{
			if (orient)//если не сменили ориентацию
			{
				double maxCos=-2;
				int maxi=0;
				for (int i=0;i<n;i++)
				{
					if (i==resHull[nRes-1]) continue;//если это текуща€ точка то не вычисл€ем
					if ((p[i].x-p[resHull[nRes-1]].x)/Geometry.length(p[i].x, p[i].y, p[resHull[nRes-1]].x, p[resHull[nRes-1]].y)>maxCos
							&& p[i].y>p[resHull[nRes-1]].y)//максимальный косинус и точка выше текущей
					{
						maxCos=(p[i].x-p[resHull[nRes-1]].x)/Geometry.length(p[i].x, p[i].y, p[resHull[nRes-1]].x, p[resHull[nRes-1]].y);
						maxi=i;
					}

				}
				if (maxCos==-2)//не нашли точек выше
				{
					orient=false;//мен€ем ориентацию и переходим в след шагу
					continue;
				}
				resHull[nRes++]=maxi;//добавл€ем точку в результат
			}
			else
			{
				double maxCos=-2;
				int maxi=0;
				for (int i=0;i<n;i++)
				{
					if (i==resHull[nRes-1]) continue;//если это текуща€ точка то не вычисл€ем
					if ((p[resHull[nRes-1]].x-p[i].x)/Geometry.length(p[i].x, p[i].y, p[resHull[nRes-1]].x, p[resHull[nRes-1]].y)>maxCos
							&& p[i].y<p[resHull[nRes-1]].y)//изменили ориентацию
					{
						maxCos=(p[resHull[nRes-1]].x-p[i].x)/Geometry.length(p[i].x, p[i].y, p[resHull[nRes-1]].x, p[resHull[nRes-1]].y);
						maxi=i;
					}

				}
				if (maxi==resHull[0]) return nRes;//дошли до начальной точки
				resHull[nRes++]=maxi;
			}
		}
		return -1;
	}
	
	public static void diameter(Point p[],int start,int end, int n)//не работает пока что 
	{
		int resHull[]=new int[0];
		jarvis(p,resHull,n);
		int cur=0;
		
		
	}
	
}
