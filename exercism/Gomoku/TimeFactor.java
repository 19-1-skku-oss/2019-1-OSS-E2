import java.awt.*;

public class TimeFactor extends Dialog
{
	Label lb;
	Label error;
	TextField tf;
	String message;
	int timeFactor;
	int oldValue;
	boolean erreur;

	TimeFactor(Frame parent,String title,int timeFactor)
	{
    	
		super(parent,title,true);
    	oldValue=timeFactor;
		GridBagLayout boite=new GridBagLayout();
 	 	GridBagConstraints constraints=new GridBagConstraints();
 	 	setLayout(boite);
 	 	buildConstraints(constraints,0,0,1,1,30,100);
 	 	constraints.fill=GridBagConstraints.NONE;
 	 	constraints.anchor=GridBagConstraints.EAST;
		lb=new Label(" Computer Thinking Time");
 	 	boite.setConstraints(lb,constraints);
 	 	add(lb);

 	 	buildConstraints(constraints,1,0,1,1,70,100);
 	 	constraints.fill=GridBagConstraints.NONE;
 	 	constraints.anchor=GridBagConstraints.WEST;
		tf=new TextField(String.valueOf(timeFactor),7);
 	 	boite.setConstraints(tf,constraints);
 	 	add(tf);

 	 	buildConstraints(constraints,0,1,2,1,100,100);
 	 	constraints.fill=GridBagConstraints.NONE;
 	 	constraints.anchor=GridBagConstraints.CENTER;
		error=new Label("                                                ");
 	 	boite.setConstraints(error,constraints);
 	 	add(error);

 	 	buildConstraints(constraints,0,2,2,1,0,20);
 	 	constraints.fill=GridBagConstraints.NONE;
 	 	constraints.anchor=GridBagConstraints.CENTER;
		Button b=new Button("OK");
		boite.setConstraints(b,constraints);
 	 	add(b);
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

	public boolean handleEvent(Event evt)
    {
        if (evt.id==Event.WINDOW_DESTROY)
        {
     	    timeFactor=oldValue;
        	TimeFactor app;
  	        app=(TimeFactor)evt.target;
        	app.hide();
        	return true;
  	    }

  	    if (evt.id==Event.ACTION_EVENT)
        {
    		isOk();
            if (erreur==false)
            {
          	    hide();
            }
            return true;
        }
        return super.handleEvent(evt);
	}

	public void isOk()
	{
		erreur=false;
		int i,j;
        message = tf.getText();
        message = message.toUpperCase();
        
        for (i =0; i<message.length(); i++)
        {
            char c = message.charAt(i);
            j = (int) c - 32;
            if ((j < 16) || (j>26))
            {
             	error.setText("Enter an integer please.");
    			erreur=true;
             	tf.setText(String.valueOf(oldValue));
            	break;
            }
        
        }
        if(message.length()>7 && erreur==false)
        {
          	timeFactor=1000;
        }
        else
        {
            timeFactor=Integer.parseInt(tf.getText());
        }
        if ( timeFactor<=0 || timeFactor>100)
        {
        	error.setText("Number beetwen 1 and 100");
          	erreur=true;
          	tf.setText(String.valueOf(oldValue));
        }
	}

}
