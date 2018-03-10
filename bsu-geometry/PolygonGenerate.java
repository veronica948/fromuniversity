package by.bsu;

import java.util.Random;

public class PolygonGenerate {
	private static boolean leftSidePoint(double x0, double y0, double x1, double y1, double x2, double y2)
	{
		if (Intersection.positionRelative(x0,y0,x1,y1,x2,y2)==1) return false;//проверяем чтобы все точки были левее
		return true;
	}
	private static boolean newSegmentIntersection(double x[], double y[], int i)
	{
		for (int k=0;k<i-2;k++)//проверяем последний отрезок на пересечение с остальными
		{
			if (Intersection.segmentIntersection(x[i], y[i], x[i-1], y[i-1], x[k], y[k], x[k+1], y[k+1])==0)
			{
				return false;
			}
		}
		return true;
	}
	private static boolean lastSegmentIntersection(double x[],double y[],int i)
	{
		for (int k=1;k<i-1;k++)//проверяем
		{
			if (Intersection.segmentIntersection(x[0], y[0], x[i], y[i], x[k], y[k], x[k+1], y[k+1])==0)
			{
				return false;
			}
		}
		return true;
	}
	
	private static boolean leftSidePolygon(double x[],double y[],int i)
	{
		for (int k=1;k<i;k++)//проверяем чтобы все точки были по правую точку от последнего отрезка
		{
			if (Intersection.positionRelative(x[k], y[k], x[0], y[0], x[i], y[i])==-1)
			{
				return false;
			}
		}
		return true;
	}
	
 public static void generateSimple(double x[],double y[], int n)
	{
		Random rand=new Random();
		for (int i=0;i<n;i++)
		{
			x[i]=rand.nextDouble()*Calculation.height;
			y[i]=rand.nextDouble()*Calculation.height;
			if (i<3) continue;
			boolean fl=true;
			while (fl)
			{
				for (int k=0;k<i-2;k++)//проверяем последний отрезок на пересечение с остальными
				{
					if (Intersection.segmentIntersection(x[i], y[i], x[i-1], y[i-1], x[k], y[k], x[k+1], y[k+1])==0)
					{
						x[i]=rand.nextDouble()*Calculation.height;
						y[i]=rand.nextDouble()*Calculation.height;
						k=-1;//генерируем заново и начинаем проверку с начала
					}
				}
				fl=false;
				for (int k=1;k<i-1;k++)//проверяем
				{
					if (Intersection.segmentIntersection(x[0], y[0], x[i], y[i], x[k], y[k], x[k+1], y[k+1])==0)
					{
						x[i]=rand.nextDouble()*Calculation.height;
						y[i]=rand.nextDouble()*Calculation.height;
						k=0;//генерируем заново и начинаем проверку с начала
						fl=true;
					}
				}
			}
		}
	}
	
	public static void generateConvex(double x[],double y[], int n)
	{
		Random rand=new Random();
		for (int i=0;i<n;i++)
		{
			x[i]=rand.nextDouble()*Calculation.height;
			y[i]=rand.nextDouble()*Calculation.height;
			if (i<2) continue;
			boolean fl=true;
			while (fl)
			{
				fl=false;//генерируем точку пока не выполнится 4 условия
				x[i]=rand.nextDouble()*Calculation.height;
				y[i]=rand.nextDouble()*Calculation.height;
				if (!leftSidePoint(x[i],y[i],x[i-2],y[i-2],x[i-1],y[i-1])) fl=true;
				if (!newSegmentIntersection(x,y,i)) fl=true;
				if (!lastSegmentIntersection(x,y,i)) fl=true;
				if (!leftSidePolygon(x,y,i)) fl=true;
			}
		}
	}
}
