#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std ;

const int height = 20 ; // HEIGHT OF THE BOARD
const int width = 20 ;	// WIDTH OF THE BOARD

int x_coordinate , y_coordinate ; // COORDINATES OF THE FIGHTER PLANE

int fire_array_x [height] = {0} ; // FIRE X COORDINATE ARRAY FOR FIRE STREAM 1
int fire_array_y [width] = {0} ; // FIRE Y COORDINATE ARRAY FOR FIRE STREAM 1

int fire_array_y_2 [width] = {0} ; // FIRE X COORDINATE ARRAY FOR FIRE STREAM 2
int fire_array_x_2 [width] = {0} ; // FIRE Y COORDINATE ARRAY FOR FIRE STREAM 2

int enemy_array_x [width] = {0} ; // ENEMY PLANE X COORDINATE ARRAY
int enemy_array_y [height] = {0} ; // ENEMY PLANE Y COORDINATE ARRAY

bool gameOver = false ; // VARIABLE FOR GAME OVER CONDITION
bool flag = true ; // VARIABLE FOR MOVEMENT OF FIRE ARRAY 1 OR FIRE ARRAY 2

int x_movement = 0 ; // VARIABLE FOR STORING MOVEMENT OF OUR PLANE

int starting_limit = 0 ; // VARIABLE FOR TELLING THE STARTING LIMIT OF FIRE ARRAY 1
int fire_limit = 1 ; // VARIABLE FOR TELLING THE ENDING LIMIT OF FIRE ARRAY 1

int starting_limit_2 = 0 ; // VARIABLE FOR TELLING THE STARTING LIMIT OF FIRE ARRAY 2
int fire_limit_2 = 1 ; // VARIABLE FOR TELLING THE ENDING LIMIT OF FIRE ARRAY 2

int score = 0 ; // SCORE OF GAME

HANDLE colour = GetStdHandle ( STD_OUTPUT_HANDLE ) ; // VARIABLE FOR GIVING COLOURS IN OUTPUT 

void initial_positions_of_game () ; // FUNCTION FOR INITIAL POSITIONS OF THE  OF THE BOARD ELEMENTS 
void structure_of_the_board () ; // FUNCTION FOR STRUCTURE OF THE BOARD
void movement_of_the_plane () ; // FUNCTION FOR MOVEMENT OF THE PLANE
void logic_of_game () ; // FUNCTION FOR THE LOGICS OF THE GAME OR RULES

int main ()

{
	
	initial_positions_of_game () ; // CALLING INITIAL POSITION FUNCTION
	
	bool start = false ;
	
	while ( !gameOver ) // LOOP TILL GAME OVER IS TRUE
	
	{
		
		structure_of_the_board () ; // CALLING STRUCTURE FUNCTION
		
		if ( !start ) // TO CHECK IF GAME HAS BEEN START
		{
			
			_getch () ; // GET A CHARACTER FROM USER 
			start = true ; // TO TELL THAT GAME HAS BEEN START
			
		}
		
		movement_of_the_plane () ;	// CALLING MOVEMENT OF PLANE FUNCTION
		
		logic_of_game () ; // CALLING LOGIC OF GAME FUNCTION 
		
	}
		
	SetConsoleTextAttribute ( colour , FOREGROUND_GREEN ) ;
	
	cout << endl << "Your plane hasbeen crashed!! " << endl ;
	cout << "Final score is : " << score ;
	
	SetConsoleTextAttribute ( colour , FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN ) ;
	
	cout << endl ;
	
}

void initial_positions_of_game () // DEFINATION OF INITIAL POSITION FUNCTION

{
	
	x_coordinate = width/2 ; // INITIAL X POSITION OF FIGHTER PLANE 
	y_coordinate = height ; // INITIAL Y POSITION OF FIGHTER PLANE
	
	for ( int i = 0 ; i < 20 ; i++ )
	{

		fire_array_x [i] = x_coordinate ; // INITIALIZATION OF X COORDINATE OF FIRE ARRAY 1
		fire_array_x_2 [i] = x_coordinate ; // INITIALIZATION OF X COORDINATE OF FIRE ARRAY 2
	
		enemy_array_x [i] = i+1 ; // INITIALIZATION OF X COORDINATE OF ENEMY FIGHTER PLANE
		enemy_array_y [i] = 1 ; // INITIALIZATION OF X COORDINATE OF ENEMY FIGHTER PLANE

	}

	fire_array_y [0] = y_coordinate - 1 ; // INITIALIZATION OF Y COORDINATE OF FIRE ARRAY 1
	
}

void structure_of_the_board () // DEFINATION OF STRUCTURE OF BOARD FUNCTION 

{
	
	system ("CLS") ; // CLEAR THE SCREEN EACH TIME LOOP HAS BEEN STARTED          

	for ( int i = 1 ; i <= height + 2 ; i++ ) // PRINT UPPER BOUNDARY OF BOARD
	{

		cout << "\xDC" ; 
		SetConsoleTextAttribute ( colour , FOREGROUND_RED ) ; // SET RED COLOUR FOR UPPER BOUNDARY

	}

	cout << endl ;
	
	// PRINT SIDES OF THE BOARD AND ELEMENTS WITHIN THE BOARD

	for ( int i = 1 ; i <= height ; i++ )

	{

		for ( int j = 1 ; j <= width ; j++ )

		{

			SetConsoleTextAttribute ( colour , FOREGROUND_RED ) ; // SET COLOUR TO RED
			if ( j == 1 ) // PRINTING LEFT BOUNDARY
				cout << "\xDD" ; 
				
			SetConsoleTextAttribute ( colour , FOREGROUND_RED | FOREGROUND_BLUE ) ; // SET COLOUR TO PURPLE WHICH IS MIXTURE OF BLUE AND RED
			if ( j ==  x_coordinate && i == y_coordinate ) // PRINTING YOUR FIGHTER PLANE
				cout << "\xCA" ;

			else

			{

				bool fire_print = false ; // VARIABLE TO TELL IF THE FIRE HAS BEEN PRINTED OR NOT
				bool enemy_print = false ; // VARIABLE TO TELL IF THE ENEMY PLANE HASS BEEN PRINTED OR NOT

				SetConsoleTextAttribute ( colour , FOREGROUND_RED | FOREGROUND_GREEN ) ; // SET COLOUR OF FIRE TO YELLOW
				for ( int a = 0 ; a < fire_limit ; a++ )
					if ( i == fire_array_y[a] && j == fire_array_x[a] ) // PRINT FIRE ARRAY 1

					{

						cout << "\x5E" ;
						fire_print = true ;

					}

				for ( int a = 0 ; a < fire_limit_2 ; a++ ) // PRINT FIRE ARRAY 2
					if ( i == fire_array_y_2[a] && j == fire_array_x_2[a] )

					{

						cout << "\x5E" ;
						fire_print = true ;

					}
				
				SetConsoleTextAttribute ( colour , FOREGROUND_BLUE | FOREGROUND_GREEN ) ;// SET ENEMY PLANE COLOUR TO BLUE
				for ( int a = 0 ; a < 20 && !fire_print ; a++ ) // PRINT ENEMY FIGHTER PLANE
					if ( i == enemy_array_y[a] && j == enemy_array_x[a] )

					{

						cout << "\xCB" ;
						enemy_print = true ;

					}

				if ( !fire_print && !enemy_print ) // IF NON OF THE PLANE OF FIRE IS PRINT THEN PRINT SPACE
					cout << " " ;

			}
			
			SetConsoleTextAttribute ( colour , FOREGROUND_RED ) ;// SET COLOUR OF LOWER BOUNDARY TO RED
			if ( j == width ) // PRINTING RIGHTSIDE BOUNDARY
				cout << "\xDE";
			
			
			if ( i == 10 && j == 20 ) // CONDITION TO PRINT THE SCORE AT COORDINATES
				
				cout << "\t\t\t\tSCORE : " << score ; // PRINTIING SCORES

		}

		cout << endl ;

	}
	
	SetConsoleTextAttribute ( colour , FOREGROUND_RED ) ; // SET LOWER BOUNDARY COLOUR TO RED
	for ( int i = 1 ; i <= height + 2 ; i++ ) // PRINTING LOWER BOUNDARY
		cout << "\xDF" ;

}

void movement_of_the_plane () // DIFINATION OF MOVEMENT OF PLANE FUNCTION

{
	
	if (_kbhit() ) // IF A KEYBOARD KEY IS PRERSSED, THEN IT WILL CHECK WHICH KEY WAS PRESSED
	
		switch ( _getch () ) // GET A CHARACTER
		
		{
			
			case 'a' : // IF A IS PRESSED THEN IT WILL MOVE LEFT
			case 'A' :
				x_coordinate-- ;
				break ;
				
			case 'd' : // IF D IS PRESSED THEN IT WILL MOVE RIGHT
			case 'D' :
				x_coordinate++ ;
				break ;
			
			default : // IF ANY OTHER KEY IS PRESSED, NOTHING WILL HAPPEN
				break ;
		
		}
	
}

void logic_of_game () // DEFINATION OF LOGIC FUNCTION

{
	
	x_movement++ ; // X_COORDINATE MOVEMENT OF PLANE WILL INCREASE EACH TIME A LOOP HAS RAN THAT INDICATES THE NUMBER OF FIRES A PLANE DID

	if ( x_movement == 19 ) // IF PLANE HAS DID 19 FIRES, WHICH IS SIZE OF ARRAYS, THEN IT WILL RETURN TO ZERO FOR SECOND ARRAY
	{
	
		x_movement = 0 ;
		flag = !flag ;
	
	}

	if ( x_coordinate >= width ) // IF PLANE TOUCHES RIGHT SIDE OF BOUNDARY, IT WILL RETURN TO SAME POSITION 
		x_coordinate = width ;

	else if ( !x_coordinate ) // IF PLANE TOUCHES LEFT SIDE OF BOUNDARY, IT WILL RETURN TO SAME POSITION
		x_coordinate = true ;

    for ( int i = 0 ; i < 20 ; i++ )

    {

    	if ( enemy_array_y [i] == y_coordinate && enemy_array_x [i] == x_coordinate ) // IF ENEMY PLAN TOUCHES OUR PLANE THEN GAME IS OVER
        {
		
			gameOver = true ;
			return ;
			
		}
		
		else 
        	enemy_array_y[i]++ ; // ENEMY PLANE WILL MOVE DOWNWARD

    }

    for ( int i = 0 ; i < 20 ; i++ )
            for ( int j = 0 ; j < 20 ; j++ )
                if ( ( enemy_array_y [j] == fire_array_y_2 [i] && enemy_array_x [j] == fire_array_x_2 [i] ) || ( enemy_array_y [j] == fire_array_y [i] && enemy_array_x [j] == fire_array_x [i] ) ) // IF FIRE TOUCHES THE ENEMY PLANE, IT WILL CRASH AN OUR SCORE WILL INCREASE
                {
				    
					enemy_array_y[j] = 1 ;
					score++ ;
					
				}

	if ( fire_array_y[0] != 0 || fire_array_y[18] > 0 ) // FIRST FIRE ARRAY
	{
		
        for ( int i = x_movement ; i < 20 && flag ; i++ )
			fire_array_x[i] = x_coordinate ; // X_COORDINATE OF EACH FIRE SEGMENT

		int previous = fire_array_y[starting_limit] ; // STORING THE VALUE OF Y_COORDINATE THE FIST FIRE SEGMENT
		
	    fire_array_y[starting_limit]--; // DECREASING THE FIST FIRE SEGMENT

		if 	( fire_array_y[0] < 19 )
			for ( int i = starting_limit ; i < fire_limit ; i++ )
				if ( i < 18 )
					fire_array_y[i+1] = previous++; // GIVING VALUES OF THE FIRST SEGMENT BY INCREASING ONE IN IT EACH TIME

		if ( fire_limit < 19 ) // TO LIMIT THE LAST SEGMENT OF FIRE
			fire_limit++ ;

		if ( fire_array_y[18] < 0 ) // TO RETURN THE INITIAL VALUE OF THE LIMIT OF FIRE'S LAST SEGMENT
			fire_limit = 0 ;

		if ( fire_array_y[0] == 0 ) // IF FIRST SEGMENT OF FIRE BECOMES ZERO THE SEGMENT BEFORE IT WILL GET USED OF DECREMENT
			starting_limit++ ;

	}

	if ( fire_array_y_2[0] != 0 || fire_array_y_2[18] > 0 ) // SECOND FIRE ARRAY
	{

		for ( int i = x_movement ; i < 20 && !flag ; i++ )
			fire_array_x_2[i] = x_coordinate ;// X_COORDINATE OF EACH FIRE SEGMENT

	    int previous_2 = fire_array_y_2[starting_limit_2] ;// DECREASING THE FIST FIRE SEGMENT
		fire_array_y_2[starting_limit_2]--;

		if 	( fire_array_y_2[0] < 19 )
			for ( int i = starting_limit_2 ; i < fire_limit_2 ; i++ )
				if ( i < 18 )
					fire_array_y_2[i+1] = previous_2++; // GIVING VALUES OF THE FIRST SEGMENT BY INCREASING ONE IN IT EACH TIME

		if ( fire_limit_2 < 19 ) // TO LIMIT THE LAST SEGMENT OF FIRE
			fire_limit_2++ ;

		if ( fire_array_y_2[19] < 0 ) // TO RETURN THE INITIAL VALUE OF THE LIMIT OF FIRE'S LAST SEGMENT
			fire_limit_2 = 0 ;

	    if (fire_array_y_2[0] == 0) // IF FIRST SEGMENT OF FIRE BECOMES ZERO THE SEGMENT BEFORE IT WILL GET USED OF DECREMENT
			starting_limit_2++ ;

	}

	if ( fire_array_y[18] == 18 ) // IF FIRST FIRE Y_COORDINATE ARRAY'S LAST SEGMENT HAS REACHED 18, IT WILL PASS ITS VALUE TO 2ND ARRAY'S FIRST INDEX 
	{							   //AND ALSO THE X_COORDINATE OF ITS LAST INDEX

    	fire_array_y_2[0] = 19 ;
    	fire_array_x_2[x_movement] = x_coordinate ;

	}

	else if ( fire_array_y_2[18] == 18 ) // IF SECOND FIRE Y_COORDINATE ARRAY'S LAST SEGMENT HAS REACHED 18, IT WILL PASS ITS VALUE TO 1ST ARRAY'S FIRST INDEX
	{									 //AND ALSO THE X_COORDINATE OF ITS LAST INDEX

    	fire_array_y[0] = 19 ;
    	fire_array_x[x_movement] = x_coordinate ;

	}

	if ( starting_limit == 19 ) // IF STARTING FIRE LIMIT OF FIRE ARRAY 1 HAS BECOME EQUAL TO THE SIZE OF ARRAY IT WILL BECOME ZERO AND FIRE ENDING LIMIT WILL BE ONE
	{
		starting_limit = 0 ;
		fire_limit = 1 ;

	}

	if ( starting_limit_2 == 19 ) // IF STARTING FIRE LIMIT OF FIRE ARRAY 2 HAS BECOME EQUAL TO THE SIZE OF ARRAY IT WILL BECOME ZERO AND FIRE ENDING LIMIT WILL BE ONE
	{
		starting_limit_2 = 0 ;
		fire_limit_2 = 1 ;

	}

    for ( int i = 0 ; i < 20 ; i++ ) // IF NOTHING HAPPENS AND ENEMY PLANE REACHES THE END THEN IT WILL START FROM BEGENING
        if ( enemy_array_y [i] == 21 )
			enemy_array_y[i] = 1 ;
	
	for ( int i = 0 ; i < 20 ; i++ )
            for ( int j = 0 ; j < 20 ; j++ )
                if ( ( enemy_array_y [j] == fire_array_y_2 [i] && enemy_array_x [j] == fire_array_x_2 [i] ) || ( enemy_array_y [j] == fire_array_y [i] && enemy_array_x [j] == fire_array_x [i] ) ) // IF FIRE TOUCHES THE ENEMY PLANE, IT WILL CRASH AN OUR SCORE WILL INCREASE
                {
				    
					enemy_array_y[j] = 1 ;
					score++ ;
					
				}
	
          
}