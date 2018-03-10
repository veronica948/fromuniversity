package by.bsu;

public class Geometry {
	private static double determinant(double a, double b,double c, double d)
	{
		return a*d-b*c;
	}
	public static void parallelTransport(double x0, double y0, double x[], double y[], double n)//параллельный перенос точек на вектор
	{
		for (int i=0;i<n;i++)
		{		
			x[i]+=x0;
			y[i]+=y0;
		}
	}
	public static void homothety(double x0, double y0, double k, double x[], double y[], double n)//преобразование гомотетии(писал для себя, в задачах не надо)
	{
		for (int i=0;i<n;i++)
		{
			x[i]=k*(x[i]-x0)+x0;
			y[i]=k*(y[i]-y0)+y0;
		}
	}
	
	public static double length(double x1, double y1, double x2, double y2)//длина вектора
	{
		return Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	}
	
	public static double areaConvex(double x[], double y[], double n)//площадь выпуклого многоугольника
	{
		double s=0;
		for (int i=1;i<n-1;i++)
		{
			s+=Math.abs(determinant(x[i]-x[0],y[i]-y[0],x[i+1]-x[0],y[i+1]-y[0]))/2;
		}
		return s;
	}
}
