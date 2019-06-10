import java.applet.AudioClip;
import java.awt.*;
public class Morpion extends Frame
{
	Morpionjava  root;
	int timeFactor=1;						
	int []coupsGardes=new int[7];
	int niveauMax=5;
	int meilleurCoup;
	int profondeur;
	boolean elagage=false;
	int[]score=new int[8];
	int [][][]listeMeilleursCoups=new int[30][3][7];
	int [] listeIndex=new int[7];
	int myVictoire=0;
	int yourVictoire=0;
	int []coupX=new int[400];
  int []coupY=new int[400];
	int coupCourant=0,coupMax=0;
	int fin=1;
  int [][] pos=new int[20][20];
	int [][] note=new int[20][20];
	int vide=1,x=3,xx=8,xxx=20,xxxx=200,o=5,oo=10,ooo=25,oooo=1000;
	Grille damier;
	boolean ordistarts;
	CheckboxMenuItem easy,medium,hard;

	public Morpion(String title, Morpionjava rootclass)
	{
		super (title);
	 	coupsGardes[0]=5;
		coupsGardes[1]=5;
		coupsGardes[2]=5;
		coupsGardes[3]=6;
		coupsGardes[4]=6;
		root=rootclass;
		MenuBar mb=new MenuBar();
		Menu mfile=new Menu("실행");
		MenuItem ng=new MenuItem("새로시작");
		mfile.add(ng);
		mb.add (mfile);
		Menu moption=new Menu("옵션");
		
		easy= new CheckboxMenuItem("초보");		
		moption.add(easy);
		medium=new CheckboxMenuItem("중수");
		medium.setState(true);
			{
				medium.setState(true);
				coupsGardes[0]=5;
				coupsGardes[1]=5;
				coupsGardes[2]=5;
				coupsGardes[3]=6;
				coupsGardes[4]=6;
     			niveauMax=5;
         	}
		moption.add(medium);
		hard=new CheckboxMenuItem("고수");		
		moption.add(hard);
		MenuItem sep=new MenuItem("-");
		moption.add(sep);
		CheckboxMenuItem firstplayer=new CheckboxMenuItem("컴퓨터 먼저 시작");
		moption.add(firstplayer);
		mb.add(moption);
		Menu mgame=new Menu("게임조절");
		MenuItem fm=new MenuItem("처음으로");
		mgame.add(fm);
		MenuItem back=new MenuItem("뒤로");
		mgame.add(back);
		MenuItem forward=new MenuItem("앞으로");
		mgame.add(forward);
		MenuItem last=new MenuItem("되돌림");
		mgame.add(last);
		mb.add(mgame);
		setMenuBar(mb);
		damier=new Grille(this);
		add (damier);
		damier.dessin();
    }

    public boolean handleEvent(Event e)
    {
        if(e.id == Event.WINDOW_DESTROY)
        {
     	    Morpion app;
        	app=(Morpion)e.target;
        	app.hide();
        	return true;
  	    }
	
        if (e.id == Event.MOUSE_UP)
    	{
	    	if (fin==0)
		    {
        		int x=e.x-(insets().left);
        		int y=e.y-(insets().top);
    	    	joue((int)((x-damier.dX)/damier.longueur),(int)((y-damier.dY)/damier.largeur));
        	}
        	return true;
	    }

     	if (e.target instanceof CheckboxMenuItem)
		{
     		String label=((CheckboxMenuItem)e.target).getLabel();

     		if (label.equals("컴퓨터 먼저 시작"))
			{
				if (ordistarts==true)
				{
				    ordistarts=false;
				}
				else
				{
				    ordistarts=true;
				}
				return true;
     		}

			if (label.equals("초보"))
			{
				easy.setState(true);
				medium.setState(false);
				hard.setState(false);
				coupsGardes[0]=10;
				coupsGardes[1]=10;
				coupsGardes[2]=10;
				niveauMax=3;
				return true;
			}

			if (label.equals("중수"))
			{
				medium.setState(true);
				easy.setState(false);
				hard.setState(false);
				coupsGardes[0]=5;
				coupsGardes[1]=5;
				coupsGardes[2]=5;
				coupsGardes[3]=6;
				coupsGardes[4]=6;
     			niveauMax=5;
     			return true;
         	}

		    if (label.equals("고수"))
			{
     			hard.setState(true);
        		medium.setState(false);
		    	easy.setState(false);
				TimeFactor window=new TimeFactor(this,"Enter computer thinking time",timeFactor);	//고수에만 활성화되는 Time Factor
     			window.resize(225,150);
        		window.show();
		    	timeFactor=window.timeFactor;
				coupsGardes[0]=3+(int)(timeFactor*7/100);
     			coupsGardes[1]=coupsGardes[0];
      	    	coupsGardes[2]=coupsGardes[1];
				coupsGardes[3]=coupsGardes[1];
				coupsGardes[4]=coupsGardes[1];
     			coupsGardes[5]=coupsGardes[1]+1;
      		    coupsGardes[6]=coupsGardes[1]+2;
			    niveauMax=7;
			    return true;
			}
		}

        if (e.id==Event.ACTION_EVENT)
    	{
			if (e.target instanceof MenuItem)
			{
				String label=((MenuItem)e.target).getLabel();
				
				if (label.equals("새로시작"))
				{
				 	fin=0;
					coupMax=0;
					coupCourant=0;
					for (int x=0;x<20;x++)
					{
						for (int y=0;y<20;y++)
						{
							pos[x][y]=0;
						    note[x][y]=0;
						}
						damier.dessin();
					}
					if (ordistarts==true)
					{
						root.joue2.play();
						pos[10][10]=1;
						coupX[0]=10;
						coupY[0]=10;
						damier.dessin();
						coupCourant++;
						coupMax=coupCourant;
						damier.dessin();
					}
					return true;
				}
								
				
				if (label.equals("처음으로"))		
				{
					coupCourant=2;
					damier.dessin();
					return true;
				}
				if(label.equals("뒤로")&& coupCourant>1)
				{
					note[coupX[coupCourant-1]][coupY[coupCourant-1]]=0;	
					note[coupX[coupCourant-2]][coupY[coupCourant-2]]=0;	
					coupCourant=coupCourant-2;
					damier.dessin();	
					return true;
				}
        		if (label.equals("앞으로")&& coupCourant<coupMax)
        		{
					note[coupX[coupCourant-1]][coupY[coupCourant-1]]=0;
					coupCourant=coupCourant+2;
					damier.dessin();
					return true;
				}
				if (label.equals("되돌림"))
				{
					coupCourant=coupMax;
					damier.dessin();
					return true;
				}
		    }
		}
		return super.handleEvent(e);
	}


	void joue(int x, int y)
	{
		if (coupCourant!=coupMax)
		{
			for (int z=coupCourant;z<coupMax;z++)
			{
				pos[coupX[z]][coupY[z]]=0;
			}
		}
		
		if (pos[x][y]==0)		
		{
	    	pos[x][y]=2;
    		coupX[coupCourant]=x;
	    	coupY[coupCourant]=y;
    	 	coupCourant++;
	    	coupMax++;
			profondeur=0;
			damier.paint(damier.getGraphics());
    		root.joue.play();
    		if (evaluation()<-6000000)
    		{
    			root.perd.play();
        		yourVictoire++;
    			Victoire window=new Victoire(this,"당신이 이겼습니다.",this);
	    		window.resize(280,150);
		    	window.show();
				return;
			}
		    reponse();
	    }
    }

	void reponse()
	{
		listeIndex[0]=0;
		score[0]=-2147483648;
		profondeur=0;
		elagage=false;
		generationCoups(coupsGardes[0],0);
		if(listeMeilleursCoups[0][2][0]>=oooo)
		{
			meilleurCoup=0;
			listeIndex[0]=coupsGardes[0];
		}

		while(listeIndex[0]<coupsGardes[profondeur]){
			while (listeIndex[profondeur]<coupsGardes[profondeur]){
				while(profondeur<niveauMax){
	   		       simuleCoup(listeIndex[profondeur],profondeur);
					profondeur++;
					if(profondeur<niveauMax){
					generationCoups(coupsGardes[profondeur],profondeur);
				  if(listeMeilleursCoups[0][2][profondeur]>=oooo){
					break;
						}
					if (profondeur%2==0){
						score[profondeur]=-2147483648;}
					else{
						score[profondeur]=2147483647;}
					}
				}
			if (profondeur!=niveauMax){
				profondeur--;
				reprendCoup(listeIndex[profondeur],profondeur);
				listeIndex[profondeur]++;
				elagage=false;}
				else{
			score[profondeur]=evaluation();
			comparaisonScore(profondeur);
			profondeur--;
			reprendCoup(listeIndex[profondeur],profondeur);
			listeIndex[profondeur]++;}
		}
		if (listeIndex[0]>=coupsGardes[0]){
			break;}
		comparaisonScore(profondeur);
		listeIndex[profondeur]=0;
		profondeur--;
		reprendCoup(listeIndex[profondeur],profondeur);
		if (elagage==true){
			listeIndex[profondeur]=coupsGardes[profondeur];
			score[profondeur]=-2147483647;
			elagage=false;}
		listeIndex[profondeur]++;
	}
		pos[listeMeilleursCoups[meilleurCoup][0][0]][listeMeilleursCoups[meilleurCoup][1][0]]=1;
		coupX[coupCourant]=listeMeilleursCoups[meilleurCoup][0][0];
		coupY[coupCourant]=listeMeilleursCoups[meilleurCoup][1][0];
		coupCourant++;
		coupMax=coupCourant;
		
		damier.paint(damier.getGraphics());
		root.joue2.play();
    
		if (listeMeilleursCoups[meilleurCoup][2][0]>=oooo)		
		{
			myVictoire++;
			root.gagne.play();
			Victoire window=new Victoire(this,"제가 이겼네여. 다시 도전?",this);
			window.resize(280,150);
			window.show();
		}
  }



	void simuleCoup(int numero,int profondeur){
		if (profondeur%2==0) {
			pos[listeMeilleursCoups[numero][0][profondeur]][listeMeilleursCoups[numero][1][profondeur]]=1;
    }
		else {
			pos[listeMeilleursCoups[numero][0][profondeur]][listeMeilleursCoups[numero][1][profondeur]]=2;
    }
	}

	void reprendCoup(int numero,int profondeur){
			pos[listeMeilleursCoups[numero][0][profondeur]][listeMeilleursCoups[numero][1][profondeur]]=0;

	}

	void comparaisonScore(int profondeur){
		if (profondeur%2==0){
			if (score[profondeur]<score[profondeur-2]) {
				elagage=true;
      }
			else if (score[profondeur]<score[profondeur-1]) {
				score[profondeur-1]=score[profondeur];
			}
		}
		else {

			if (score[profondeur]>score[profondeur-1]) {
				if (profondeur==1){
					meilleurCoup=listeIndex[0];
        }
				score[profondeur-1]=score[profondeur];
      }
		}

	}

	void generationCoups(int max,int niveau)
	{
		int quintet;
		int eval;
		int zz;
		for (int x=0;x<20;x++){
			for (int y=0;y<20;y++){
				note[x][y]=0;
			}
		}
		for(int x=0;x<max;x++){
			listeMeilleursCoups[x][0][profondeur]=0;
			listeMeilleursCoups[x][1][profondeur]=0;
			listeMeilleursCoups[x][2][profondeur]=-1;
		}
		
		for( int x=0;x<15;x++){
			for (int y=0;y<20;y++){
				quintet=0;
				for (int z=0;z<5;z++){
				zz=pos[x+z][y];
				if (zz==2){zz=-10;}
				quintet=quintet+zz;
				}
				eval=evalQuintet2(quintet);
				for (int z=0;z<5;z++){
					 note[x+z][y]=note[x+z][y]+eval;}
					 }
		}
		
		for(int x=0;x<20;x++){
			for (int y=0;y<15;y++){
				quintet=0;
				for (int z=0;z<5;z++){
				zz=pos[x][y+z];
				if (zz==2){zz=-10;}
				quintet=quintet+zz;
				}

				eval=evalQuintet2(quintet);
				for (int z=0;z<5;z++){
					 note [x][y+z]=note[x][y+z]+eval;}
			}
		}

		for (int x=0;x<15;x++){
			for(int y=0;y<15;y++){
				quintet=0;
				for (int z=0;z<5;z++){
				zz=pos[x+z][y+z];
				if (zz==2){zz=-10;}
				quintet=quintet+zz;
				}

				eval=evalQuintet2(quintet);
				for (int z=0;z<5;z++) {
					note [x+z][y+z]=note[x+z][y+z]+eval;}
			}
		}
		for (int x=4;x<20;x++){
			for(int y=0;y<15;y++){
				quintet=0;
				for (int z=0;z<5;z++){
				zz=pos[x-z][y+z];
				if (zz==2){zz=-10;}
				quintet=quintet+zz;
				}

				eval=evalQuintet2(quintet);
				for (int z=0;z<5;z++){
					note [x-z][y+z]=note[x-z][y+z]+eval;}
			}
		}
		
		for (int x=0;x<20;x++){
			for (int y=0;y<20;y++){
					for (int coups=0;coups<coupsGardes[profondeur];coups++){
							if (pos[x][y]==0 && note[x][y]>listeMeilleursCoups[coups][2][profondeur]){
								for (int z=coupsGardes[profondeur]-2;z>=coups;z--){
									listeMeilleursCoups[z+1][0][profondeur]=listeMeilleursCoups[z][0][profondeur];
									listeMeilleursCoups[z+1][1][profondeur]=listeMeilleursCoups[z][1][profondeur];
									listeMeilleursCoups[z+1][2][profondeur]=listeMeilleursCoups[z][2][profondeur];}
							listeMeilleursCoups[coups][0][profondeur]=x;
							listeMeilleursCoups[coups][1][profondeur]=y;
							listeMeilleursCoups[coups][2][profondeur]=note[x][y];
							break;}
							}
			}
		}
	}

	int evaluation(){
		int quintet;
		int eval;
		int position=0;

			for( int x=0;x<15;x++){
			for (int y=0;y<20;y++){
				if (pos[x][y]!=0){
				quintet=0;
				int zz=1;
				for (int z=0;z<5;z++){
				quintet=quintet+pos[x+z][y]*zz;
				zz=zz*10;}
				position=position+evalQuintet(quintet);
				}
			}
		}
		for( int x=4;x<20;x++){
			for (int y=0;y<20;y++){
				if (pos[x][y]!=0){
				quintet=0;
				int zz=1;
				for (int z=0;z<5;z++){
				quintet=quintet+pos[x-z][y]*zz;
				zz=zz*10;}
				position=position+evalQuintet(quintet);
				}
			}
		}

		for(int x=0;x<20;x++){
			for (int y=0;y<15;y++){
				if (pos[x][y]!=0){
				quintet=0;
				int zz=1;
				for (int z=0;z<5;z++){
				quintet=quintet+pos[x][y+z]*zz;
				zz=zz*10;	}
				position=position+evalQuintet(quintet);
				}
			}
		}
		for(int x=0;x<20;x++){
			for (int y=4;y<20;y++){
				if (pos[x][y]!=0){
				quintet=0;
				int zz=1;
				for (int z=0;z<5;z++){
				quintet=quintet+pos[x][y-z]*zz;
				zz=zz*10;	}
				position=position+evalQuintet(quintet);
				}
			}
		}

			for (int x=0;x<15;x++){
			for(int y=0;y<15;y++){
				if (pos[x][y]!=0){
				quintet=0;
				int zz=1;
				for (int z=0;z<5;z++){
				quintet=quintet+pos[x+z][y+z]*zz;

				zz=zz*10;
        }
				position=position+evalQuintet(quintet);
				}
			}
		}

		for (int x=4;x<20;x++){
			for(int y=4;y<20;y++){
				if (pos[x][y]!=0){
				quintet=0;
				int zz=1;
				for (int z=0;z<5;z++){
				quintet=quintet+pos[x-z][y-z]*zz;
				zz=zz*10;
        }
				position=position+evalQuintet(quintet);
				}
			}
		}

		for (int x=4;x<20;x++){
			for(int y=0;y<15;y++){
				if (pos[x][y]!=0){
				quintet=0;
				int zz=1;
				for (int z=0;z<5;z++){
				quintet=quintet+pos[x-z][y+z]*zz;
				zz=zz*10;}
				position=position+evalQuintet(quintet);
        }
			}
		}
		for (int x=0;x<15;x++){
			for(int y=4;y<20;y++){
				if (pos[x][y]!=0){
				quintet=0;
				int zz=1;
				for (int z=0;z<5;z++){
				quintet=quintet+pos[x+z][y-z]*zz;
				zz=zz*10;}
				position=position+evalQuintet(quintet);
        }
			}
		}
		return position;
	}

	int evalQuintet2(int quintet)	{
		if(profondeur%2==0){
		switch(quintet){
		case 0:return vide;
		case 1: return o;
		case -10: return x;
		case 2: return oo;
		case -20: return xx;
		case 3: return ooo;
		case -30: return xxx;
		case 4: return oooo;
		case -40: return xxxx;
		default: return 0;}
	}
	else{
		switch(quintet){
		case 0:return vide;
		case 1: return x;
		case -10: return o;
		case 2: return xx;
		case -20: return oo;
		case 3: return xxx;
		case -30: return ooo;
		case 4: return xxxx;
		case -40: return oooo;
		default: return 0;}

		}
		}
			
	int evalQuintet(int quintet)	{
 		switch(quintet){
		case 0: return 1;	
		case 1: return 10;
		case 11: return 21;
		case 101: return 16;
		case 1001: return 12;
		case 10001: return 11;
		case 111: return 42;
		case 1011: return 32;
		case 10011: return 28;
		case 1101: return 32;
		case 10101: return 15;
		case 11001: return 28;
		case 1111: return 80;
		case 11101: return 60;
		case 11011: return 40;
		case 11111: return 100000000;
		case 2: return -15;
		case 22: return -30;
		case 202: return -25;
		case 2002: return -18;
		case 20002: return -16;
		case 222: return -62;
		case 2022: return -50;
		case 20022: return -46;
		case 2202: return -50;
		case 20202:return -26;
		case 22002: return -46;
		case 2222: return -1000;
		case 22202: return -1000;
		case 22022: return -1000;
		case 22222: return -10000000;
		default: return 0;
 		}
	}
}
