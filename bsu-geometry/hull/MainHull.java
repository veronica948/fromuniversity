package by.bsu.hull;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.util.Random;

import by.bsu.Geometry;
import by.bsu.PolygonGenerate;

import javax.swing.JFrame;

public class MainHull extends JFrame{
	static int height=700;
	static boolean fl=true;
	public static double x[],y[];
	public static int n=10;
	public static int nRes;
	public static int resHull[];
	public static Point p[];
	public MainHull()
	{
		setLayout(new FlowLayout());
		setSize(height,height);
		setDefaultCloseOperation(EXIT_ON_CLOSE); 
		setBackground(Color.white);	  
		n=10;
		resHull=new int[n];
		x= new double[n];
		y=new double[n];
		p=new Point[n];
		Random rand=new Random();
		for (int i=0;i<n;i++)
		{
			p[i]=new Point();//генерируем точки с векторами скорости
			p[i].x=100+rand.nextDouble()*(height-300);
			p[i].y=100+rand.nextDouble()*(height-300);
			double angle=rand.nextDouble()*Math.PI;
			p[i].vX=Math.cos(angle)*5;
			p[i].vY=Math.sin(angle)*5;
		}
		this.repaint();
		setVisible(true);
		
		while (true)//анимация
		{
			try
			{
				Thread.sleep(50);
			}
			catch(InterruptedException e) {
				e.printStackTrace();
			}
			this.repaint();//перерисовываем всё
			double len=0;
			nRes=ConvexHull.graham(p, resHull, n);//строим выпуклую оболочку
			for (int i=1;i<nRes;i++)//считаем длину
			{
				len+=Geometry.length(p[resHull[i]].x, p[resHull[i]].y, p[resHull[i-1]].x, p[resHull[i-1]].y);
			}
			len+=Geometry.length(p[resHull[0]].x, p[resHull[0]].y, p[resHull[nRes-1]].x, p[resHull[nRes-1]].y);
			System.out.println(len);
			if (len>1200)//если длина превысила константу меняем вектора скорости точек выпуклой оболочки
			{
				for (int i=0;i<nRes;i++)
				{
					p[resHull[i]].vX*=-1;
					p[resHull[i]].vY*=-1;
				}
			}
			for (int i=0;i<n;i++)
			{
				p[i].x+=p[i].vX;
				p[i].y+=p[i].vY;
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new MainHull();



	}
	public void paint(Graphics g)
	{
		g.clearRect(0, 0, height, height);

		for (int i=0;i<n;i++)
		{
			g.setColor(Color.black);
			g.drawOval((int)p[i].x-2, height-(int)p[i].y-2, 4, 4);
			
		}

		g.setColor(Color.green);
		for (int i=0;i<nRes;i++)//выделяем точки оболочки и рисуем её
		{
			g.drawOval((int)p[resHull[i]].x-5, height-(int)p[resHull[i]].y-5, 10, 10);
			g.drawLine((int)p[resHull[i]].x, height-(int)p[resHull[i]].y,(int) p[resHull[(i+1+nRes)%nRes]].x, height-(int)p[resHull[(i+1+nRes)%nRes]].y);
		}

	}
	

}
