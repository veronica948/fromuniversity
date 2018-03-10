package by.bsu;



public class Intersection {
	private static double determinant(double a, double b,double c, double d)
	{
		return a*d-b*c;
	}

	private static int octan(double x, double y)//вычисление октанов
	{
		if (0<y && y<=x) return 1;
		if (0<x && x<y) return 2;
		if (0<-x && -x<=y) return 3;
		if (0<y && y<-x) return 4;
		if (0<-y && -y<=-x) return 5;
		if (0<-x && -x<-y) return 6;
		if (0<x && x<=-y) return 7;
		//if (0<-y && -y<x) 
		return 8;

	}

	public static int lineIntersection(double x1, double y1, double x2, double y2,
			double x3, double y3, double x4, double y4)
	{
		if (Math.abs(determinant(x2-x1,y2-y1,x3-x1,y3-y1))<0.0001 
				&& Math.abs(determinant(x2-x1,y2-y1,x4-x1,y4-y1))<0.0001)
			return 0;
		else if (Math.abs(determinant(x2-x1,y2-y1,x4-x3,y4-y2))<0.0001)
			return 1;
		return -1;//0 - совпадают, 1- параллельны, -1 - пересекаются
	}

	public static int segmentIntersection(double x1, double y1, double x2, double y2,
			double x3, double y3, double x4, double y4)
	{
		if (determinant(x2-x1,y2-y1,x3-x1,y3-y1)*determinant(x2-x1,y2-y1,x4-x1,y4-y1)>0 )
		{
			return 1;//1 - не пересекаются
		}
		else
		{
			if (determinant(x4-x3,y4-y3,x1-x3,y1-y3)*determinant(x4-x3,y4-y3,x2-x3,y2-y3)>0)
				return 1;
		}
		return 0;// 0 - пересекаются
	}

	public static int positionRelative(double x0, double y0, double x1, double y1, double x2, double y2)
	{
		if (determinant(x2-x1,y2-y1,x0-x1,y0-y1)>0) return -1;//левее
		if (determinant(x2-x1,y2-y1,x0-x1,y0-y1)<0) return 1;//правее
		return 0;//на прямой
	}
	public static boolean belongSegment(double x0, double y0, double x1, double y1, double x2, double y2)//лежит ли точка на отезке
	{
		double tx=(x0-x1)/(x2-x1);
		double ty=(y0-y1)/(y0-y1);
		if (Math.abs(tx-ty)<0.00001 && tx>=0 && tx<=1) return true;
		return false;
	}
	public static boolean rayMethod(double x0, double y0, double x[], double y[], int n)//лучевой метод
	{
		double xmin=x[0];
		double ymin=y[0];
		double xmax=x[0];
		double ymax=y[0];
		for (int i=1;i<n;i++)
		{
			if (x[i]<xmin) xmin=x[i];
			if (y[i]<ymin) ymin=y[i];
			if (x[i]>xmax) xmax=x[i];
			if (y[i]>ymax) ymax=y[i];
		}
		if (x0<xmin || x0>xmax || y0<ymin || y0>ymax) return false;

		int counter=0;
		for (int i=0;i<n;i++)
		{//(n+i-1)%n для граничных случаев, чтобы не вышло за пределы массива
			if (segmentIntersection(x[(n+i-1)%n],y[(n+i-1)%n],x[i],y[i],xmin-1,y0,x0,y0)==0) counter++;
			if (belongSegment(x[i],y[i],xmin-1,y0,x0,y0))//если точка лежит на отрезке
			{
				if (!((y[(n+i-1)%n]>y0) && (y[(n+i+1)%n]>y0) || (y[(n+i-1)%n]<y0) && (y[(n+i+1)%n]<y[i-1])))
					counter++;
			}
		}
		if (counter%2==0) return false;
		return true;
	}

	public static int octanMethod(double x0, double y0, double x[], double y[], int n)//октановый метод
	{
		int s=0;
		for (int i=0;i<n;i++)
		{
			int delta;
			delta=octan(x[(n+i-1)%n]-x0,y[(n+i-1)%n]-y0)-octan(x[i]-x0,y[i]-y0);
			if (delta>4) delta=delta-8;
			if (delta<-4) delta=delta+8;
			if (delta==4 || delta==-4)
			{
				if (determinant(x[i]-x0,y[i]-y0,x[(n+i-1)%n]-x0,y[(n+i-1)%n]-y0)>0)
				{
					delta=4;
				}
				else
				{
					if (determinant(x[i]-x0,y[i]-y0,x[(n+i-1)%n]-x0,y[(n+i-1)%n]-y0)<0)
						delta=-4;
					else return 0;//точка на стороне многоугольника
				}
			}
			s+=delta;
		}
		if (s==8 || s==-8) return 1;//в многоугольнике
		if (s==0) return -1;//не в мноогоугольнике
		return -2;//ошибка
	}

	public static int pointConvexRelative(double x0, double y0, double x[], double y[], int n)//проверка принадлежности точки выпуклому многоугольнику
	{
		int startIndex = 0, endIndex = n-1;
		int sepIndex;
		int z = 0;
		while(endIndex - startIndex > 1) //бинарный поиск
		{
			sepIndex = (startIndex + endIndex) / 2;
			if(positionRelative(x0,y0, x[sepIndex], y[sepIndex],x[0],y[0])==-1) 
			{
				endIndex = sepIndex;
			}
			else startIndex = sepIndex;
		}
		if(positionRelative(x0,y0, x[0],y[0],x[n-1],y[n-1])==-1) 
			return 0; 
		if(positionRelative(x0,y0, x[startIndex],y[startIndex],x[endIndex],y[endIndex])==-1) 
			return 1; 
		else 
			return 0;
	}
}
