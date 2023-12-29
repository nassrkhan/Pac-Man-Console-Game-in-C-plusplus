#include<iostream>
#include<conio.h>
#include <stdlib.h>		
#include<windows.h>

using namespace std;

void gotoxy(int x,int y)
{
	static HANDLE h = NULL;
	if(!h)
	{	                                            /*HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);*/
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD c = { x, y};
	SetConsoleCursorPosition(h,c);
}

bool game=true;

int main()
{
	int x=1;
	int y=1;
	int x1=22;
	int y1=1;
	int x2=19;
	int y2=9;
	int x3=37;
	int y3=18;
	a:
	char player=120;
	int enemy1=64;
	int enemy2=42;
	int fruit=0;
	char w=219;
	char map [500][500]={"#######################################", //character array which store map
                     "#.....................................#",
                     "#.########.########.########.########.#",
                     "#.#      #.#      #.#      #.#      #.#",
                     "#.#      #.#      #.#      #.#      #.#",
                     "#.#      #.#      #.#      #.#      #.#",
                     "#.#      #.#      #.#      #.#      #.#",
                     "#.#      #.#      #.#      #.#      #.#",
                     "#.########.########.########.########.#",
                     "#.....................................#",
                     "#.#################.#################.#",
                     "#.#               #.#               #.#",
                     "#.#               #.#               #.#",
                     "#.#               #.#               #.#",
                     "#.#################.#################.#",
                     "#.....................................#",
    				 "#.#################.#################.#",
                     "#.#               #.#               #.#",
                     "#.#               #.#               #.#",
                     "#.#               #.#               #.#",
                     "#.#################.#################.#",
                     "#.....................................#",
                     "#######################################"};

	int dir , up=-1 , down = -2 , left = -3 , right = -4 ; //assign directional variables
	int dir1=4 , up1=1 , down1 = 3 , left1 = 2 , right1 = 4 ;
	int dir2=5 , up2=5 , down2 = 6 , left2 = 7 , right2 = 8 ;
	int dir3=9 , up3=12 , down3 = 10 , left3 = 11 , right3 = 12 ;
	
	system("color e9"); //text and output secreen colour
	
	int i;
	
	for(int k=0;k<=23;k++)
	{
	   for(int j=0;j<=38;j++)
		{
		  gotoxy(k,j);
		  cout<<" ";
		}
	}
	
	gotoxy(50,10);
	
	cout<<"PAC MAN";
	
	gotoxy(30,12);
	
	cout<<"Loading:";
	
	for(int k=39;k<=50;k++)
	{
	  gotoxy(k,12);
	  cout<<".";
	}  
	
	for(int k=39;k<=50;k++)
	{
	 gotoxy(k,12);
	 cout<<"<";
	 Sleep(100);
	 gotoxy(k,12);
	 cout<<" ";
	}	
	
	while(game==true)
	
	{ //while start
	 
	  Sleep(100);
	 
	  system("cls");
	 
	  for(i=0;i<23;i++) //output map
	  {
		cout<<map[i]<<endl;
	  }
	
	  for(int k=0;k<23;k++) //highlight map
	  {
	  	for(int j=0;j<=38;j++)
		{
			if(map[k][j]=='#')
			map[k][j]=219;
		}
	   }
	
		map[y][x]=player; //pacman leftmost initial position
	
		if(GetAsyncKeyState(VK_DOWN))       /*if(GetAsyncKeystate(VK_DOWN)) DOWN BUTTON */
	   {
		 dir=down;
		 dir1=rand()%4+1;
		 dir2=rand()%4+5;
		 dir3=rand()%4+9;
	    }
	    
		if(GetAsyncKeyState(VK_UP))          /*if(GetAsyncKeystate(VK_UP)) UP BUTTON */
	  	{
		 dir=up;
		 dir1=rand()%4+1;
		 dir2=rand()%4+5;
		 dir3=rand()%4+9;
		}
		
		if(GetAsyncKeyState(VK_RIGHT))      /*if(GetAsyncKeystate(VK_RIGHT)) RIGHT BUTTON */
	  	{
		 dir=right;
		 dir1=rand()%4+1;
	     dir2=rand()%4+5;
		 dir3=rand()%4+9;
	   	}
	   
		if(GetAsyncKeyState(VK_LEFT))      /*if(GetAsyncKeystate(VK_LEFT)) LEFT BUTTON */
	  	{
		  dir=left;
		  dir1=rand()%4+1;
		  dir2=rand()%4+5;
		  dir3=rand()%4+9;
	   	}
	   
		if(GetAsyncKeyState(VK_ESCAPE))     /*if(GetAsyncKeystate(VK_ESCAPE)) ESCAP BUTTON */ 
	  	{
		   game==false;
		   system("cls");
		   exit(game);
	   	}
	   
		if(dir==up)  //up movement of pacman
		{
		  if(map[y-1][x]==enemy1)
			{
				system("cls");
				break;
			}
		  if(map[y-1][x]==' ') 
			{
			  map[y][x]=' ';
			  y--;
			  map[y][x]=player;
			}
		  if(map[y-1][x]=='.')
			{
			  map[y][x]=' ';
			  y--;
			  fruit++;
			  map[y][x]=player;
			}
		}	
		
		if(dir==down)   //down movement of pacman
	  	{
		 if(map[y+1][x]==enemy1)
		 	{
		 		system("cls");
		 		break;
			}
		
		 if(map[y+1][x]==' ') //|| map[y+1][x]=='.')
		   {
			   map[y][x]=' ';
			   y++;
			   map[y][x]=player;
			}		
		 if(map[y+1][x]=='.')
			{
			   map[y][x]=' ';
			   y++;
			   fruit++;
			   map[y][x]=player;
			}
		}
		
		if(dir==left)   //left movement of pacman
	  	{
	  	 if(map[y][x-1]==enemy1)
			{
				system("cls");
		   		break;
			}
	
		 if(map[y][x-1]==' ')// || map[y][x-1]=='.')
		   {	
			   map[y][x]=' ';
			   x--;
			   map[y][x]=player;
			}
			
		 if(map[y][x-1]=='.')
			{	
			   map[y][x]=' ';
			   x--;
			   fruit++;
			   map[y][x]=player;
			}	
		}
		if(dir==right)   //right movement of pacman
		{
	  	 	if(map[y][x+1]==enemy1)
			{
				system("cls");
		   		break;
			}
			
			if(map[y][x+1]==' ')
			{
				map[y][x]=' ';
				x++;
				map[y][x]=player;
			}
			
			if(map[y][x+1]=='.')
			{
				map[y][x]=' ';
				x++;
				fruit++;
				map[y][x]=player;
		
			}
		}
	
		gotoxy(39,13);
	
		cout<<" x = "<<x<<" "<<" y = "<<y<<endl;
		
		gotoxy(39,14);
		
		cout<<" x1 = "<<x1<<" "<<" y1 = "<<y1<<endl;
		
		gotoxy(39,15);
		
		cout<<" x2 = "<<x2<<" "<<" y2 = "<<y2<<endl;
		
		gotoxy(39 ,16);
		
		cout<<" x3 = "<<x3<<" "<<" y3 = "<<y3<<endl;
		
		gotoxy(40,18);
		
		cout<<"Pacman game implemented in C++"<<endl;
		
		gotoxy(40,19);
		
		cout<<"NASRULLAH KHAN"<<endl;   //out of control of position of pacman
		
		
		if ( x1==1 && y1==1) dir1=rand()%4+1;    // creating ranmdom numbers for dir1
		
		if ( x1==10 && y1==1) dir1=rand()%4+1;  
		
		if ( x1==19 && y1==1) dir1=rand()%4+1;
		
		if ( x1==28 && y1==1) dir1=rand()%4+1;
		
		if ( x1==37 && y1==1) dir1=rand()%4+1;
		
		if ( x1==1 && y1==9) dir1=rand()%4+1;
		
		if ( x1==10 && y1==9) dir1=rand()%4+1;
		
		if ( x1==19 && y1==9) dir1=rand()%4+1;
		
		if ( x1==28 && y1==9) dir1=rand()%4+1;
		
		if ( x1==37 && y1==9) dir1=rand()%4+1;
		
		if ( x1==1 && y1==14) dir1=rand()%4+1;
		
		if ( x1==19 && y1==14) dir1=rand()%4+1;
		
		if ( x1==37 && y1==14) dir1=rand()%4+1;
		
		if ( x1==1 && y1==18) dir1=rand()%4+1;
		
		if ( x1==1 && y1==14) dir1=rand()%4+1;
		
		if ( x1==19 && y1==18) dir1=rand()%4+1;
		
		if ( x1==37 && y1==18) dir1=rand()%4+1;
		
		if(x1==x2 && y1==y2)
		{
		    dir1=rand()%4+1;dir2=rand()%4+5;dir3=rand()%4+9;
		}
		if(x1+1==x2 && y1==y2)
		{
			dir1=rand()%4+1;dir2=rand()%4+5;dir3=rand()%4+9;
		}
		if(x1-1==x2 && y1==y2)
		{
			dir1=rand()%4+1;dir2=rand()%4+5;dir3=rand()%4+9;
		}
		if(x1==x2 && y1+1==y2)
		{
			dir1=rand()%4+1;dir2=rand()%4+5;dir3=rand()%4+9;
		}
		if(x1==x2 && y1-1==y2)
		{
			dir1=rand()%4+1;dir2=rand()%4+5;dir3=rand()%4+9;
		}
		if(x1==x3 && y1==y3)
		{
			dir1=rand()%4+1;dir2=rand()%4+5;dir3=rand()%4+9;
		}
		if(x1+1==x3 && y1==y3)
		{
			dir1=rand()%4+1;dir2=rand()%4+5;dir3=rand()%4+9;
		}
		if(x1-1==x3 && y1==y3)
		{
			dir1=rand()%4+1;dir2=rand()%4+5;dir3=rand()%4+9;
		}
		if(x1==x3 && y1+1==y3)
		{
			dir1=rand()%4+1;dir2=rand()%4+5;dir3=rand()%4+9;
		}
		if(x1==x3 && y1-1==y3)
		{
			dir1=rand()%4+1;dir2=rand()%4+5;dir3=rand()%4+9;
		}
		if(x2==x3 && y2==y3)
		{
			dir1=rand()%4+1;dir2=rand()%4+5;dir3=rand()%4+9;
		}
		if(x2+1==x3 && y2==y3)
		{
			dir1=rand()%4+1;dir2=rand()%4+5;dir3=rand()%4+9;
		}
		if(x2-1==x3 && y2==y3)
		{
			dir1=rand()%4+1;dir2=rand()%4+5;dir3=rand()%4+9;
		}
		if(x2==x3 && y2+1==y3)
		{
			dir1=rand()%4+1;dir2=rand()%4+5;dir3=rand()%4+9;
		}
		if(x2==x3 && y2-1==y3)
		{
			dir1=rand()%4+1;dir2=rand()%4+5;dir3=rand()%4+9;
		}
		
		if(dir1==up1)    //up1 var dir1 var     first enemy created
		{
			if(map[y1-1][x1]==' ')
			{
				if(map[y1-1][x1]==player)
				 {
					system("cls");
					break;
				 }
				else
				{
					map[y1][x1]=' ';
					y1--;
					map[y1][x1]=enemy1;
				}
			}
			if(map[y1-1][x1]=='.')
			{
				if(map[y1-1][x1]==player)
				 {
					system("cls");
					break;
				 }
				else
				{
					map[y1][x1]='.';
					y1--;
					map[y1][x1]=enemy1;
				}
			}
		}   //end up1 var dir1 var
	
		if(dir1==down1)  //down1 var dir1 var
		{
			if(map[y1+1][x1]==' ')
			{
				if(map[y1+1][x1]==player)
				 {
					system("cls");
					break;
				 }
				 
				else
				{
					map[y1][x1]=' ';
					y1++;
					map[y1][x1]=enemy1;
				}
			}
			
			if(map[y1+1][x1]=='.')
			{
				if(map[y1+1][x1]==player)
				 {
					system("cls");
					break;
				 }
				else
				{
					map[y1][x1]='.';
					y1++;
					map[y1][x1]=enemy1;
				}
			}
		} //end down1 var dir1 var
		
		if(dir1==left1) //left1 var dir1 var
		{
			if(map[y1][x1-1]==' ')
			{
				if(map[y1][x1-1]==player)
				 {
					system("cls");
					break;
				 }
				 
				else
				{
					map[y1][x1]=' ';
					x1--;
					map[y1][x1]=enemy1;
				}
			}
		
			if(map[y1][x1-1]=='.')
			{
				if(map[y1][x1-1]==player)
				 {
					system("cls");
					break;
				 }
				else
				{
					map[y1][x1]='.';
					x1--;
					map[y1][x1]=enemy1;
			}
			
			}
		}  //end left1 var dir1 var
	
		if(dir1==right1) //right1 var dir1 var
		{
			if(map[y1][x1+1]==' ')
			{
				if(map[y1][x1+1]==player)
				 {
						 	
				 	system("cls");
					break;
				 }
				else
				{
					map[y1][x1]=' ';
					x1++;
					map[y1][x1]=enemy1;
				}
			}
			if(map[y1][x1+1]=='.')
			{
				if(map[y1][x1+1]==player)
				 {
						 	
				 	system("cls");
					break;
				 }
		        else
				{
					map[y1][x1]='.';
					x1++;
					map[y1][x1]=enemy1;
				}
			}
		}   //end left1 var dir1 var   //first enemy created to line 318 
	
		if ( x2==1 && y2==1) dir2=rand()%4+5;  //creating random number for dir2
		if ( x2==10 && y2==1) dir2=rand()%4+5;
		if ( x2==19 && y2==1) dir2=rand()%4+5;
		if ( x2==28 && y2==1) dir2=rand()%4+5;
		if ( x2==37 && y2==1) dir2=rand()%4+5;
		if ( x2==1 && y2==9) dir2=rand()%4+5;
		if ( x2==10 && y2==9) dir2=rand()%4+5;
		if ( x2==19 && y2==9) dir2=rand()%4+5;
		if ( x2==28 && y2==9) dir2=rand()%4+5;
		if ( x2==37 && y2==9) dir2=rand()%4+5;
		if ( x2==1 && y2==14) dir2=rand()%4+5;
		if ( x2==19 && y2==14) dir2=rand()%4+5;
		if ( x2==37 && y2==14) dir2=rand()%4+5;
		if ( x2==1 && y2==18) dir2=rand()%4+5;
		if ( x2==1 && y2==14) dir2=rand()%4+5;
		if ( x2==19 && y2==18) dir2=rand()%4+5;
		if ( x2==37 && y2==18) dir2=rand()%4+5;	
	
	
		if(dir2==up2)  //Up direction and enemy 2 creating from 338
		{
			if(map[y2-1][x2]==' ')
			{
				if(map[y2-1][x2]==player)
					 {
						system("cls");
						break;
					 }
				else
					{
						map[y2-1][x2]=' ';
						y2--;
						map[y2][x2]=enemy1;
					}
			}
			if(map[y2-1][x2]=='.')//|| map[y1-1][x1]==player)
			{
				if(map[y2-1][x2]==player)
				 {
					system("cls");
					break;
				 }
				else
				{
					map[y2][x2]='.';
					y2--;
					map[y2][x2]=enemy2;
				}
			}
		}
		
		if(dir2==down2) //Down
		{
			if(map[y1+1][x1]==' ')
			{
				if(map[y2+1][x2]==player)
				 {
					system("cls");
					break;
				 }
				else
				{
					map[y2+1][x2]=' ';
					y2++;
					map[y2][x2]=enemy2;
				}
			}
		
			if(map[y2+1][x2]=='.')
			{
				if(map[y2+1][x2]==player)
				 {
					system("cls");
					break;
				 }
				else
				{
					map[y2][x2]='.';
					y2++;
					map[y2][x2]=enemy2;
				}		
			}
		}
		
		if(dir2==left2)  //Left
		{	
			if(map[y2][x2-1]==' ')
			{	
				if(map[y2][x2-1]==player)
				{
					system("cls");
					break;
				}
				else
				{
					map[y2][x2-1]=' ';
					x2--;
					map[y2][x2]=enemy2;
				}
			}
			if(map[y2][x2-1]=='.')
			{
				if(map[y2][x2-1]==player)
				 {
					system("cls");
					break;
				 }
				else
				{
					map[y2][x2]='.';
					x2--;
					map[y2][x2]=enemy1;
				}
			}
		}
		 //Left end
		if(dir2==right2) //Right2
		{
			if(map[y2][x2+1]==' ')
				{
					if(map[y2][x2+1]==player)
					 	{
							system("cls");
							break;
						 }
					else
						{
							map[y2][x2+1]=' ';
							x2++;
							map[y2][x2]=enemy2;
						}
				}
			if(map[y2][x2+1]=='.')
				{
					if(map[y2][x1+1]==player)
					 	{
						 	system("cls");
							break;
					 	}
		        	else
						{
						map[y2][x2]='.';
						x2++;
						map[y2][x2]=enemy1;
						}
			}
		
		} //Right2 end   // Enemy2 created.
	
		gotoxy(40,3);
		cout<<"Fruit = "<<fruit<<endl;
		
		gotoxy(40,5);
		cout<<"PAC MAN"<<endl;
		
		gotoxy(40,6);
		cout<<"CONSOLE GAME"<<endl;
		
		gotoxy(40,7);
		cout<<"WITHOUT USING GRAPHICS";
		
		gotoxy(40,8);
		
		char p=120;char e1=64;char e2=42;
		
		cout<<"PLAYER= "<<p<<endl;
		
		gotoxy(40,9);
		cout<<"Enemy-1= "<<e1<<endl;
		
		gotoxy(40,10);
		cout<<"Enemy-2= "<<e2<<endl;
		
		if(fruit>100)
			break;
		
	}//while
		
		
	if(fruit>=100)
		{
			system("cls");
			gotoxy(50,12);
			cout<<"You WIN";
			Sleep(500);
			gotoxy(50,12);
			cout<<"          ";
			Sleep(500);
			gotoxy(50,12);
			cout<<"You WIN";
			Sleep(500);
			gotoxy(50,12);
			cout<<"          ";
			Sleep(500);
			gotoxy(50,12);
			cout<<"You WIN";
			Sleep(500);
			gotoxy(50,12);
			cout<<"         ";
			Sleep(500);
			gotoxy(50,12);
			cout<<"You WIN";
			Sleep(500);
	}
		
	if(fruit>=0 && fruit<100)
	{
		system("cls");
		gotoxy(50,12);
		cout<<"You Lose";
		Sleep(500);
		gotoxy(50,12);
		cout<<"          ";
		Sleep(500);
		gotoxy(50,12);
		cout<<"You Lose";
		Sleep(500);
		gotoxy(50,12);
		cout<<"          ";
		Sleep(500);
		gotoxy(50,12);
		cout<<"You Lose";
		Sleep(500);
		gotoxy(50,12);
		cout<<"         ";
		Sleep(500);
		gotoxy(50,12);
		cout<<"You Lose";
		Sleep(500);
	}
	gotoxy(50,14);
	
	cout<<"Game Over!"<<endl;
	
	cout<<"Press any key to end the program.";
	
	getch();		
	
	return 0;
}

