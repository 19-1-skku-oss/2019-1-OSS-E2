import java.awt.*;

public class Victoire extends Dialog
{
	Morpion root;
	Label lb;

    Victoire(Frame parent,String title,Morpion rootclass)
    {
		super(parent,title,true);
 	 	root=rootclass;
 	 	root.fin=1;
 	 	
 	 	GridBagLayout boite=new GridBagLayout();			
 	 	GridBagConstraints constraints=new GridBagConstraints();
 	 	setLayout(boite);
 	 	
 	 	buildConstraints(constraints,0,0,2,1,40,0);
 	 	constraints.fill=GridBagConstraints.NONE;
 	 	constraints.anchor=GridBagConstraints.CENTER;
 	 	lb=new Label(title);
 	 	boite.setConstraints(lb,constraints);
 	 	add(lb);
 	 	
 	 	buildConstraints(constraints,0,1,1,1,40,50);	
 	 	constraints.fill=GridBagConstraints.NONE;
 	 	constraints.anchor=GridBagConstraints.CENTER;
		lb=new Label("Computer : "+root.myVictoire);		
		boite.setConstraints(lb,constraints);
 	 	add(lb);
		
 	 	buildConstraints(constraints,1,1,1,1,40,50);
 	 	constraints.fill=GridBagConstraints.NONE;
 	 	constraints.anchor=GridBagConstraints.CENTER;
		lb=new Label("Player : "+root.yourVictoire);
		boite.setConstraints(lb,constraints);
 	 	add(lb);
		
 	 	buildConstraints(constraints,0,2,2,1,0,0);
 	 	constraints.fill=GridBagConstraints.NONE;
 	 	constraints.anchor=GridBagConstraints.CENTER;
		Button b=new Button("OK");
		boite.setConstraints(b,constraints);
 	 	add(b);
    }

	public boolean handleEvent(Event e)
	{
		if(e.target instanceof Button && e.id==Event.ACTION_EVENT)
		{
			String label=((Button)e.target).getLabel();
			if (label=="OK")hide();
			return true;
		}
		return super.handleEvent(e);
	}

	void buildConstraints(GridBagConstraints gbc,int gx,int gy,int gw,int gh,int wx,int wy)
	{
	  gbc.gridx=gx;
		gbc.gridy=gy;
		gbc.gridwidth=gw;
		gbc.gridheight=gh;
		gbc.weightx=wx;
		gbc.weighty=wy;
	}
}
