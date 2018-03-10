package by.bsu;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.util.Random;

import javax.swing.*; 
public class Calculation extends JFrame{//задача с овцами
	static int height=700;
	static boolean fl=true;
	public static double xCon[],xSim[];//точки простого многоугольника
	public static double yCon[],ySim[];//и выпуклого
	public static int nCon,nSim;//количество вершин
	public static int nSheep;
	public static Sheep sheep[];
	public Calculation()
	{
		setLayout(new FlowLayout());
		setSize(height,height);
		setDefaultCloseOperation(EXIT_ON_CLOSE); 
		setBackground(Color.white);	  


		nCon=7;//устанавливаем необходимые значения
		nSim=9;
		nSheep=100;
		xCon=new double[nCon];
		yCon=new double[nCon];
		xSim=new double[nSim];
		ySim=new double[nSim];
		double centerX=0;
		double centerY=0;
		int maxI = 0,maxJ = 0;
		double diameter;
		do
		{
			PolygonGenerate.generateConvex(xCon, yCon, nCon);//генерируем выпуклый
			diameter=0;
			for (int i=0;i<nCon-1;i++)//находим диаметр
				for (int j=i+1;j<nCon;j++)
				{
					if (Geometry.length(xCon[i], yCon[i], xCon[j], yCon[j])>diameter)
					{
						maxI=i;
						maxJ=j;
						diameter=Geometry.length(xCon[i], yCon[i], xCon[j], yCon[j]);
					}
				}

		}while(Geometry.length(xCon[maxI],yCon[maxI],xCon[maxJ],yCon[maxJ])>700 || 
				Geometry.areaConvex(xCon, yCon, nCon)/(height*height)<0.2);//смотрим чтобы он был достаточно большой

		for (int i=0;i<nCon;i++)//находим его центр
		{
			centerX+=xCon[i];
			centerY+=yCon[i];
		}
		centerX/=nCon;
		centerY/=nCon;
		Geometry.parallelTransport(height/2-centerX, height/2-centerY, xCon, yCon, nCon);//ставим в центр
		boolean fl=true;
		while (fl)//генерируем простой
		{
			fl=false;
			PolygonGenerate.generateSimple(xSim, ySim, nSim);
			centerX=0;
			centerY=0;
			for (int i=0;i<nSim;i++)//находим центр
			{
				centerX+=xSim[i];
				centerY+=ySim[i];
			}
			centerX/=nSim;
			centerY/=nSim;
			Geometry.parallelTransport(height/2-centerX, height/2-centerY, xSim, ySim, nSim);//ставим в центр
			outer:
				for (int i=0;i<nSim;i++)
					for (int j=0;j<nCon;j++)
					{
						if (Intersection.segmentIntersection(xSim[i], ySim[i], xSim[(i+1+nSim)%nSim], ySim[(i+1+nSim)%nSim], 
								xCon[j], yCon[j], xCon[(j+1+nCon)%nCon], yCon[(j+1+nCon)%nCon])==0)//генерируем чтобы не было пересечений в сторонах
						{
							fl=true;
							break outer;
						}
					}
		}
		sheep=new Sheep[nSheep];

		Random rand=new Random();
		for (int i=0;i<nSheep;i++)
		{
			sheep[i]=new Sheep();
			sheep[i].x=rand.nextDouble()*height;
			sheep[i].y=rand.nextDouble()*height;
			if (Intersection.pointConvexRelative(sheep[i].x, sheep[i].y, xCon, yCon, nCon)==0 ||
					Intersection.octanMethod(sheep[i].x, sheep[i].y, xSim, ySim, nSim)==1)
			{//пока точка не попадёт в нужную область
				i--;
				continue;
			}
			double angle=rand.nextDouble()*2*Math.PI;//генерируем вектор скорости
			sheep[i].vX=Math.cos(angle)*5;
			sheep[i].vY=Math.sin(angle)*5;

		}
		setVisible(true);
		double resX[]=new double[nSim];
		double resY[]=new double[nSim];
		

		
		while (true)//поехали
		{
			try
			{
				Thread.sleep(50);
			}
			catch(InterruptedException e) {
				e.printStackTrace();
			}
			this.repaint();
			for (int i=0;i<Calculation.nSheep;i++)
			{
				double x=sheep[i].x;
				double y=sheep[i].y;
				double vX=sheep[i].vX;
				double vY=sheep[i].vY;
				if(vX==0) continue;//пропускаем точки которые уже не двигаются
				for (int j=0;j<nSim;j++)
					if (Intersection.segmentIntersection(x, y, x+vX, y+vY, 
							xSim[j], ySim[j], xSim[(j+1+nSim)%nSim], ySim[(j+1+nSim)%nSim])==0)
					{//пересекло ли внутренный многоугольник
						sheep[i].vX=0;
						sheep[i].vY=0;//останавливаем точку
					}
				if (Intersection.pointConvexRelative(sheep[i].x+sheep[i].vX, sheep[i].y+sheep[i].vY, xCon, yCon, nCon)==0)//пересекло внешний
				{
					for (int j=0;j<nCon;j++)
					{
						if (Intersection.segmentIntersection(x, y, x+vX, y+vY, 
								xCon[j], yCon[j], xCon[(j+1+nCon)%nCon], yCon[(j+1+nCon)%nCon])==0)
						{//если есть пересечение с одной из сторон многоугольника, меняем вектор скорости
							double ab=vX*(xCon[(j+1+nCon)%nCon]-xCon[j])+vY*(yCon[(j+1+nCon)%nCon]-yCon[j]);
							double bb=(xCon[(j+1+nCon)%nCon]-xCon[j])*(xCon[(j+1+nCon)%nCon]-xCon[j])+
									(yCon[(j+1+nCon)%nCon]-yCon[j])*(yCon[(j+1+nCon)%nCon]-yCon[j]);
							sheep[i].vX=2*(ab/bb)*(xCon[(j+1+nCon)%nCon]-xCon[j])-vX;
							sheep[i].vY=2*(ab/bb)*(yCon[(j+1+nCon)%nCon]-yCon[j])-vY;

						}
					}
				}
				Calculation.sheep[i].x+=Calculation.sheep[i].vX;//изменяем координаты овцы
				Calculation.sheep[i].y+=Calculation.sheep[i].vY;
			}
		}

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stu

		new Calculation();

	}
	public void paint(Graphics g)
	{
		g.clearRect(0, 0, height, height);
		for (int i=1;i<nCon;i++)//рисуем сначалы выпуклый
		{
			if (i%6==1) g.setColor(Color.blue);
			if (i%6==2) g.setColor(Color.red);
			if (i%6==3) g.setColor(Color.black);
			if (i%6==4) g.setColor(Color.green);
			if (i%6==5) g.setColor(Color.MAGENTA);
			g.drawLine((int)xCon[i-1], (int)yCon[i-1], (int)xCon[i], (int)yCon[i]);
		}
		g.drawLine((int)xCon[nCon-1], (int)yCon[nCon-1], (int)xCon[0], (int)yCon[0]);

		for (int i=1;i<nSim;i++)//потом прямой
		{
			if (i%6==1) g.setColor(Color.blue);
			if (i%6==2) g.setColor(Color.red);
			if (i%6==3) g.setColor(Color.black);
			if (i%6==4) g.setColor(Color.green);
			if (i%6==5) g.setColor(Color.MAGENTA);
			g.drawLine((int)xSim[i-1], (int)ySim[i-1], (int)xSim[i], (int)ySim[i]);
		}
		g.drawLine((int)xSim[nSim-1], (int)ySim[nSim-1], (int)xSim[0], (int)ySim[0]);
		g.setColor(Color.MAGENTA);

		for (int i=0;i<nSheep;i++)//и овец
		{
			g.drawOval((int)sheep[i].x, (int)sheep[i].y, 3, 3);

		}

	}

}
