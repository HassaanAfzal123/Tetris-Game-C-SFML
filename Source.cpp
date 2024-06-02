/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */

// Hassaan Afzal  22i-0918    Project 
#include <SFML/Graphics.hpp>
#include <time.h>
#include <string> 
#include "utils.h"
#include <SFML/Audio.hpp>
#include "pieces.h"
#include "functionality.h"
using namespace std;
using namespace sf;
int main(){
    srand(time(0));
    RenderWindow window(VideoMode(320, 480), title);
    Music sound ;
    if (!sound.openFromFile("sound/gamesound.ogg"))
     return -1;
    sound.play();
    
    Texture obj1, obj2, obj3, obj4;
    obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/background.png");
    obj3.loadFromFile("img/frame.png");  
    Sprite sprite(obj1), background(obj2), frame(obj3);
    
    int delta_x=0, colorNum=1, count=0, score=0,end=0;
    float timer=0, delay=0.3;
    bool rotate=0,drop=0,check=0;
    Clock clock;
    
    Font font;
    if (!font.loadFromFile("img/arial.ttf"))
    {
     return -1;
    }
    Text display;
    display.setFont(font);
    display.setString("Points");
    display.setFillColor(Color::Red);
    display.setStyle(Text::Bold);
    display.setCharacterSize(20);
    display.setPosition(240.f,110.f);
    

        
    while (window.isOpen()){
        
        string strscore= to_string(score);
        Text point;
        point.setFont(font);
        point.setString(strscore);
        point.setFillColor(Color::Black);
        point.setStyle(Text::Bold);
        point.setCharacterSize(20);
        point.setPosition(240.f,130.f);    
    
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;

        //---Event Listening Part---//
        Event e;
        while (window.pollEvent(e)){                       //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();                            //Opened window disposes
            if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
                if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
                    rotate = true;                         //Rotation gets on
                else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
                    delta_x = -1;                          //Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
                    delta_x = 1;   }                       //Change in X-Axis - Positive
            if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
                if (e.key.code == Keyboard::E)             //Check if the other key pressed is E key
                     window.close();  }                    //game ends if E pressed           
           
                    
             }
         
        if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            delay=0.05;                                    //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05
        else
           delay=0.3;

        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///
        fallingPiece(timer, delay, colorNum);                 // pieces start to fall
        sidemove(delta_x);                                    // left right movement of pieces
        rotation(rotate);                                     // clockwise rotation of pieces on their second blocks axis
        completion(count,N);                                  // line deletion  after completion 
        scoring(count,score);                                 // calculating score
        gameend(end);                                         // game ends
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////
        window.clear(Color::Black);
        window.draw(background);
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
          }
       if(end==1)  
          window.close(); 
        window.draw(display);  
        window.draw(point);
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
    }
    
    return 0;
}
