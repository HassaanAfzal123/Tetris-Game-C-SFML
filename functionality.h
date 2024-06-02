/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

// Hassaan Afzal  22i-0918    Project 
//---Piece Starts to Fall When Game Starts---//
void fallingPiece(float& timer, float& delay, int& colorNum){
    if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward
        }
        if (!anamoly()){
            for (int i=0;i<4;i++)
                gameGrid[point_2[i][1]][point_2[i][0]] = colorNum;
            
            colorNum=1+rand()%7;
            
            int n=rand()%7;
            
            
                for (int i=0;i<4;i++){                                   // making block arrays
                    point_1[i][0] = BLOCKS[n][i] % 2;
                    point_1[i][1] = BLOCKS[n][i] / 2;
                }
            
        }
        timer=0;
    }
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///
//sideways movement
void sidemove(int& delta_x)
{  

for (int i=0;i<4;i++)
     {
      point_2[i][0]=point_1[i][0];                
      point_2[i][1]=point_1[i][1];
      point_1[i][0]=point_1[i][0]+delta_x;        //side ways movement of blocks
      }
      delta_x=0;                                 //only one 1 unit movement when pressed once

if (!anamoly())
  {
    for (int i=0;i<4;i++)
     {
       point_1[i][0]=point_2[i][0];
       point_1[i][1]=point_2[i][1];            // preventing blocks from insertion into boundary as point2 retains point 1's previous value
     }
  }
}

//rotation
void rotation(bool& rotate)
{
   int x,y;
   int temp;
   if (rotate==true){
   rotate=0;                                 //rotation happens only when up word key pressed
   for (int i=0;i<4;i++)
        {
         point_2[i][0]=point_1[i][0];                
         point_2[i][1]=point_1[i][1]; 
        }
     
   for (int i=0;i<4;i++){     
        x=point_1[i][0]-point_1[1][0];       //point_1[1][0]represents the  'x' coordinates of the block around which rotation happens 
        y=point_1[i][1]-point_1[1][1];       //point_1[1][1]represents the  'y' coordinates of the block around which rotation happens
     
        temp=x;
        x=y;
        y=temp;                             //values of x and y are swapped
  
  //  The previous loop does reflection of the coordinates in the line y=x
        
        point_1[i][0]=point_1[1][0] -  x ;     // Translation of block in x direction with rotation block having original coordinates   
        point_1[i][1]=point_1[1][1] +  y ;     // Translation of block in y direction with rotation block having original coordinates   
        }
    }
     
      
   if (!anamoly())
   {
      for (int i=0;i<4;i++)
       {
         point_1[i][0]=point_2[i][0];
         point_1[i][1]=point_2[i][1];      // preventing blocks from insertion into boundary as point2 retains point 1's previous value
       }
   }
}
      
//line deletion  after completion 
void completion(int& count,int N){

int i=M-1;
count=0;
   while(i>-1)                    
   {   
       int fill=0;
       
       for(int j=0; j< N; j++)             
	{
 	    if(gameGrid[i][j] != 0)           
 	        fill=fill+1;                             //how much blocks are filled in a row 
 	} 
 	 
 	 if(fill ==N)                                    //condition if the whole row is filled 
 	{  
 	  
 	  for(int a=i; a>-1 ; a-- )            
   	       for(int j =0; j<N; j++)
      	           gameGrid[a][j] =gameGrid[a-1][j];     //next row blocks fall to the place of the deleted row
         
         i=i+1;                                          //To check row again if whole row is filled again
         count=count+1 ;                                
   	}
   i=i-1;
   }
}


// Calculating score 
void scoring(int& count,int& score){   
   if (count==0)
      score=score+0;  
   else if (count==1)
      score=score+10;
   else if (count==2)
      score=score+30;
   else if (count==3)
      score=score+60;
   else if (count==4)
      score=score+100;                  
}   

//the game ends
void gameend(int& end){
	  for(int j=0; j<N; j++)  
	  {
 	    if(gameGrid[0][j] != 0)             //checking if blocks reach last row 
               end=1;     
         }
}         
 

     
     
     
      
      













///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
