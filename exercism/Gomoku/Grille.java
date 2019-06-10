import java.awt.*;
import java.awt.Graphics;
import java.awt.Image;

public class Grille extends Panel
{
  int longueur;
	int largeur;
	int dX;
	int dY;
	Morpion root;
  Image bufferedImage;
  Graphics BIg;
  Grille (Morpion rootclass)
	{
	  super();
		root=rootclass;
		setBackground(Color.orange);
	}
  public void update(Graphics g)
  {
	  paint (g);
	}
	public void dessin()
	{
		repaint();
	}

	public void paint (Graphics g)
	{
		Dimension cadre;
   	bufferedImage =createImage(root.size().width-2*(root.insets().left), root.size().height-(root.insets().top)-(root.insets().bottom));
    BIg=bufferedImage.getGraphics();
    cadre=this.size();

		largeur=cadre.height/20;
		longueur=cadre.width/20;
		dY=(cadre.height%20)/2;
		dX=(cadre.width%20)/2;
		for (int x=0; x<20; x++)
	  {
		  for (int y=0; y<20; y++)
    	{
    	 BIg.setColor(Color.black);
    								
	     BIg.drawLine(x*longueur+dX, (y*largeur)+(largeur/2-1)+dY,	(x*longueur)+(longueur-1)+dX, (y*largeur)+(largeur/2-1)+dY);
			 BIg.drawLine(x*longueur+(longueur/2-1)+dX,y*largeur+dY,	x*longueur+(longueur/2-1)+dX, y*largeur+(largeur-1)+dY); 
			    		
			 BIg.setColor(Color.orange);			
			 BIg.drawLine(dX, (y*largeur)+(largeur/2-1)+dY, (longueur/2-1)+dX, (y*largeur)+(largeur/2-1)+dY);
		   BIg.drawLine((longueur*19)+(longueur/2-1)+dX, (y*largeur)+(largeur/2-1)+dY, longueur*20+dX, (y*largeur)+(largeur/2-1)+dY);
			 BIg.drawLine(x*longueur+(longueur/2-1)+dX,dY, x*longueur+(longueur/2-1)+dX, (largeur/2-1)+dY); 
			 BIg.drawLine(x*longueur+(longueur/2-1)+dX, 19*largeur+(largeur/2-1)+dY, x*longueur+(longueur/2-1)+dX, 19*largeur+(largeur-1)+dY); 
			    			    	
    	}
	  }
	 	for (int x=0; x<root.coupCourant; x++)
		{	

		  if (root.pos[root.coupX[x]][root.coupY[x]]==2)
		  {
				BIg.setColor(Color.white);
				BIg.fillOval(root.coupX[x]*longueur+dX,root.coupY[x]*largeur+dY,(longueur-1),(largeur-1));
				BIg.setColor(Color.black);
				BIg.drawOval(root.coupX[x]*longueur+dX,root.coupY[x]*largeur+dY,(longueur-1),(largeur-1));	
			}
			else if(root.pos[root.coupX[x]][root.coupY[x]]==1)
			{
				BIg.setColor(Color.black);
				if (x==(root.coupCourant-1))
				{
				  BIg.setColor(Color.gray);
				}
								
				BIg.fillOval(root.coupX[x]*longueur+dX,root.coupY[x]*largeur+dY,(longueur-1),(largeur-1));
			}
		}
		g.drawImage(bufferedImage,0,0,this);
	}
	public boolean handleEvent(Event evt)
	{
	    return super.handleEvent(evt);
	}
}

