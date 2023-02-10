#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

bool gameOver = false ;

const int width = 20 ;
const int height = 20 ;

int x , y , fruitX , fruitY , score = 0 ;
int tailX [100] , tailY [100] ;
int nTail ;

enum Directon { STOP = 0 , LEFT , RIGHT , UP , DOWN } dir ;

void initialSetup ()

{

    dir = STOP ;
    x = width / 2 ;
    y = height / 2 ;
    fruitX = rand() % width ;
    fruitY = rand() % height ;
    
}

int structure ()

{

    system ( "cls" ) ;
    
    for ( int i = 0 ; i < width+2 ; i++ )
        cout << "*";
        
    cout << endl;
 
    for ( int i = 0 ; i < height ; i++ )
    
	{
    
	    for ( int j = 0 ; j < width ; j++ )
    
	    {
	    	
            if ( j == 0 )
                cout << "|" ;
                
            if ( i == y && j == x )
                cout << "0" ;
                
            else if ( i == fruitY && j == fruitX )
                cout << "o" ;
                
            else
            
            {
            	
                bool print = false;
                
				for ( int k = 0 ; k < nTail ; k++ )
                
				{
                
				    if ( tailX [k] == j && tailY [k] == i )
                
				    {
                
				        cout << "o" ;
                        print = true ;
                        
                    }

                }

                if ( !print )
                    cout << " " ;

            }
                 
 
            if (j == width - 1)
                cout << "|";
                
        }
        
        cout << endl ;
        
    }
 
    for ( int i = 0 ; i < width+2 ; i++ )
        cout << "*" ;
        
    cout << endl ;
    
	cout << "Score:" << score << endl ;
	
	return score ;
	
}

void movement ()

{

    if ( kbhit() )

    {

        switch ( getch() )

        {

        case 'a' :
        	
            dir = LEFT ;
            break ;

        case 'd' :
        	
            dir = RIGHT ;
            break ;
            
        case 'w' :
        	
            dir = UP ;
            break ;
            
        case 's' :
        	
            dir = DOWN ;
            break ;
            
        case 'x' :
        	
            gameOver = true ;
            break ;
            
        }
        
    }
    
}

void rules ( char option )

{

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    
	tailX[0] = x ;
    tailY[0] = y ;
    
	for ( int i = 1 ; i < nTail ; i++ )
    
	{
    
	    prev2X = tailX[i] ;
        prev2Y = tailY[i] ;
        tailX[i] = prevX ;
        tailY[i] = prevY ;
        prevX = prev2X ;
        prevY = prev2Y ;
        
    }
    
	switch (dir)
    
	{
    
	case LEFT :
		
        x-- ;
        break ;
        
    case RIGHT :
    	
        x++ ;
        break ;
        
    case UP :
    	
        y-- ;
        break ;
        
    case DOWN :
        
		y++;
        break;
        
    default:
    	
        break;
        
    }
    
    if ( option == '2')
    
	{
    	
    	if ( x > width || x < 0 || y > height || y < 0 )
   		gameOver = true ;
    	
	}
    
    else if ( option == '1' )
    
    {
    	
    	if ( x >= width )
		x = 0 ; 
		
		else if ( x < 0 ) 
		x = width - 1 ;
	
    	if ( y >= height ) 
		y = 0 ;
		
		else if ( y < 0 ) 
		y = height - 1 ;
    	
	}
	
	for ( int i = 0 ; i < nTail ; i++ )
	    	if ( tailX [i] == x && tailY [i] == y )
            	gameOver = true ;
 
    if (x == fruitX && y == fruitY)
    
	{
    
	    score += 10;
        fruitX = rand() % width ;
    	fruitY = rand() % height ;
        nTail++;
        
    }

}

int main()

{

	char option ; 
	
	while ( option != '1' || option != '2' )
	
	{
		
		cout << "1.CLASSIC \n" ;
		cout << "2.HARD \n" ;
	
		option = getch() ;

    	if ( option == '1' || option == '2' )
    
    	{
    		char level ;
    		bool flag = true ;
    		
    		while ( flag )
    		
    		{
    			
    			cout << "Please select level from 1 to 6 : " ;
    			level = getch() ;
    			
    			if ( level >= 1 || level <= 6 )
    			flag = false ;
    			
			}
			
			switch (level)
			
			{
				
				case '1' :
					
					level = 100 ;
					break ;
					
				case '2' : 
				
					level = 83 ;
					break ;
					
				case '3' :
					
					level = 66 ;
					break ;
					
				case '4' :
					
					level = 49 ;
					break ;
					
				case '5' :
					
					level = 32 ;
					break ;
					
				case '6' :
					
					level = 0 ;
					break ;
				
			}
    	
    		initialSetup() ;

    		while ( !gameOver )

    		{

        		structure () ;
        		movement () ;
        		rules (option) ;
        		Sleep (level) ;
        
    		}
    
    		system ("pause") ;
    		break ;
    		
    	
		}
		
		system("cls") ;
		
	}
	
			system ("CLS") ;
    
			int x = structure () ;
    
   			cout << "GAME OVER!! " << endl ;
   			cout << "Your score is : " << x << endl ;
    
    		return 0 ;

}
