//##################################################################
//##################################################################
void fnctn_checkbuttons() {
  if(gb.buttons.pressed(BTN_C)){gb.titleScreen();}
  
  if(gb.buttons.pressed(BTN_B)){
    if(player.jumpStatus==0 && player.crouch==0){ 
      outpt_soundfx(5);
      player.jumpStatus=8;
      player.walking=0;
    }
  }
  
  if(gb.buttons.repeat(BTN_RIGHT,0)){
    if(player.dir==0){
      player.dir=1;
    }else{

      if(gb.display.getPixel(player.x_screen+5,player.y_screen+(5*player.crouch))==1 || gb.display.getPixel(player.x_screen+5,player.y_screen+7)==1){} 
      else{
        if(player.x_screen<84){
          if(player.walking!=1){player.walking=1;}
          else{player.walking=2;}
          if(player.x_screen<40){
            if(player.crouch==1){player.x_screen=player.x_screen+1;}
            else{
              if(gb.display.getPixel(player.x_screen+6,player.y_screen+(5*player.crouch))==1 || gb.display.getPixel(player.x_screen+6,player.y_screen+7)==1){player.x_screen=player.x_screen+1;}
              else{player.x_screen=player.x_screen+2;}
            }
          }else{
            if(player.x_world<levelLength-40){
              if(player.crouch==1){player.x_world=player.x_world+1;}
              else{
                if(gb.display.getPixel(player.x_screen+6,player.y_screen+(5*player.crouch))==1 || gb.display.getPixel(player.x_screen+6,player.y_screen+7)==1){player.x_world=player.x_world+1;}
                else{player.x_world=player.x_world+2;}
              }
            }else{
              if(player.crouch==1){player.x_screen=player.x_screen+1;}
              else{
                if(gb.display.getPixel(player.x_screen+6,player.y_screen+(5*player.crouch))==1 || gb.display.getPixel(player.x_screen+6,player.y_screen+7)==1){player.x_screen=player.x_screen+1;}
                else{player.x_screen=player.x_screen+2;}
              }
            }
          }
        }
      }
    }
  }else if(gb.buttons.repeat(BTN_LEFT,0)){
    if(player.dir==1){
      player.dir=0;
    }else{
      if(gb.display.getPixel(player.x_screen-1,player.y_screen+(5*player.crouch))==1 || gb.display.getPixel(player.x_screen-1,player.y_screen+7)==1){}
      else{
        if(player.x_screen>0){
          if(player.walking!=1){player.walking=1;}
          else{player.walking=2;}
          if(player.x_screen>40){
              if(player.crouch==1){player.x_screen=player.x_screen-1;}
              else{
                if(gb.display.getPixel(player.x_screen-2,player.y_screen+(5*player.crouch))==1 || gb.display.getPixel(player.x_screen-2,player.y_screen+7)==1){player.x_screen=player.x_screen-1;}
                else{player.x_screen=player.x_screen-2;}
              }
          }else{
            if(player.x_world>40){
              if(player.crouch==1){player.x_world=player.x_world-1;}
              else{
                if(gb.display.getPixel(player.x_screen-2,player.y_screen+(5*player.crouch))==1 || gb.display.getPixel(player.x_screen-2,player.y_screen+7)==1){player.x_world=player.x_world-1;}
                else{player.x_world=player.x_world-2;}
              }
            }else{
              if(player.crouch==1){player.x_screen=player.x_screen-1;}
              else{
                if(gb.display.getPixel(player.x_screen-2,player.y_screen+(5*player.crouch))==1 || gb.display.getPixel(player.x_screen-2,player.y_screen+7)==1){player.x_screen=player.x_screen-1;}
                else{player.x_screen=player.x_screen-2;}
              }
            }
          }
        }
      }
    }
  }else{player.walking=0;}

  if(gb.buttons.repeat(BTN_DOWN,0)){
    player.crouch=1;
  }else{
    if(player.crouch==1 && (gb.display.getPixel(player.x_screen,player.y_screen)==1 || gb.display.getPixel(player.x_screen+4,player.y_screen)==1) ){}
    else{player.crouch=0;}
  }
}

//##################################################################
//##################################################################
void fnctn_initPlayer(){
  player.x_screen=0;
  player.y_screen=30;
  player.x_world=40;
  player.jumpStatus=0;
  player.fall=0;
  player.crouch=0;
  player.walking=0;
  player.dir=1;
  player.eyes=0;
}
//##################################################################
//##################################################################
void fnctn_playerEyes(){
  player.eyes = (player.eyes+1)%80;
}

//##################################################################
//##################################################################
void fnctn_checkJump(){
  switch(player.jumpStatus){
    case 8: player.y_screen=player.y_screen-6; break;
    case 7: player.y_screen=player.y_screen-4; break;
    case 6: player.y_screen=player.y_screen-2; break;
    case 5: player.y_screen=player.y_screen-1; break;
  }
  if(player.jumpStatus>0){player.jumpStatus=player.jumpStatus-1;}
}



//##################################################################
//##################################################################
void fnctn_checkPlayerPos(){
  if(gb.display.getPixel(player.x_screen  ,player.y_screen+8)==0 && gb.display.getPixel(player.x_screen+4,player.y_screen+8)==0){
    player.y_screen=player.y_screen+1;
    if(player.fall<4){player.fall=player.fall + 1;}
    for(for_x=0; for_x<player.fall;for_x++){
      if(gb.display.getPixel(player.x_screen  ,player.y_screen+8)==0 && gb.display.getPixel(player.x_screen+4,player.y_screen+8)==0){
        player.y_screen=player.y_screen+1;
      }
    }
  }else{
    player.fall = 0;
  }
}
