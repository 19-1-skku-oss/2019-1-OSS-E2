import java.*;
import java.applet.*;
import java.awt.*;

public class Morpionjava extends java.applet.Applet 
{
	AudioClip joue,gagne,perd,joue2;
	    Morpion window;
    public Morpionjava()
	{
		window=new Morpion("자바오목게임",this);
    	window.resize(500,500);
       	window.show();
    	window.repaint();
	} 

   public void init()				
	 {
		joue=getAudioClip(getCodeBase(),"audio/click.au");
		perd=getAudioClip(getCodeBase(),"audio/congratu.au");
		joue2=getAudioClip(getCodeBase(),"audio/key.au");
		gagne=getAudioClip(getCodeBase(),"audio/laugh.au");  
	}
}

