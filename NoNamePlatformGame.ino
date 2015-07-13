#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;


//Sprites
extern const byte PROGMEM gamelogo[];
extern const byte PROGMEM playerSprite[2][10];
extern const byte PROGMEM background[1][18];

//Sounds
extern const byte soundfx[6][8];

//Struct
typedef struct{
  byte x_screen;
  byte y_screen;
  int  x_world;
  byte jumpStatus;
  byte fall;
  byte crouch;
  byte walking;
  char dir;
  byte eyes;
} Player;

Player player;

//Global Variables
int levelLength;
byte for_x;
byte for_y;
byte check01;
byte check02;



//#####################################################
//#####################################################
void setup() {
  gb.begin();
  levelLength = 1000;
  fnctn_initPlayer();
  gb.titleScreen(gamelogo);
  gb.battery.show=false;
}



//#####################################################
//#####################################################
void loop() {
  if(gb.update()){ 
    outpt_drawLandscape();
    fnctn_checkbuttons();
    gb.display.setColor(WHITE);
    gb.display.fillRect(0,0,84,48);
    gb.display.setColor(BLACK);
    outpt_drawLandscape();
    outpt_displayPlayer();
    fnctn_playerEyes();
    
    fnctn_checkJump();
    if(player.jumpStatus<4){
      fnctn_checkPlayerPos();
    }
    
    outpt_drawBackground();
    
  }
}
