package by.bsu.hull;

public class Point {
	public double x;
	public double y;
	public double vX;
	public double vY;
	public void copy(Point p)
	{
		x=p.x;
		y=p.y;
		vX=p.vX;
		vY=p.vY;
	}
}
