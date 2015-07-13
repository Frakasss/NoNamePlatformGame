//##################################################################
//##################################################################
void outpt_displayPlayer(){
  switch(player.dir){
    case 0:    gb.display.drawBitmap(player.x_screen-1 ,player.y_screen,playerSprite[player.crouch],NOROT, FLIPH);    break;
    
    case 1:    gb.display.drawBitmap(player.x_screen   ,player.y_screen,playerSprite[player.crouch],NOROT,NOFLIP);    break;
  }

  if(player.walking!=0 && player.fall==0){
    gb.display.setColor(INVERT);
    gb.display.drawPixel(player.x_screen+(player.walking*2)-1,player.y_screen+7);
    gb.display.setColor(BLACK);
  }

  if(player.eyes==0 ||player.eyes==1 || player.eyes==40 || player.eyes==41 || player.eyes==45 || player.eyes==46 || player.eyes==90 || player.eyes==91){gb.display.drawFastHLine(player.x_screen+1,player.y_screen+2+(player.crouch*3),3);}
  
}

//##################################################################
//##################################################################
void outpt_drawLandscape(){
  gb.display.drawFastHLine(0,45,84);
  gb.display.drawFastHLine(0,46,84);
  gb.display.drawFastHLine(0,47,84);
  gb.display.drawFastHLine(0,48,84);

  if(100-player.x_world>-8 && 100-player.x_world<92){gb.display.fillRect(100-player.x_world,35,8,8);}

  
}

//##################################################################
//##################################################################
void outpt_drawBackground(){
  byte spaceBetweenTrees = 50;
  for(for_x=0;for_x<levelLength/spaceBetweenTrees;for_x++){
    if(for_x*50-player.x_world>-8 && for_x*50-player.x_world<92)
    gb.display.drawBitmap(for_x*50-player.x_world,29,background[0]);
  }
  
    
}


//##################################################################
//##################################################################
void outpt_soundfx(byte fxno) {
  gb.sound.command(0,soundfx[fxno][6],0,0); // set volume
  gb.sound.command(1,soundfx[fxno][0],0,0); // set waveform
  gb.sound.command(2,soundfx[fxno][5],-soundfx[fxno][4],0); // set volume slide
  gb.sound.command(3,soundfx[fxno][3],soundfx[fxno][2]-58,0); // set pitch slide
  gb.sound.playNote(soundfx[fxno][1],soundfx[fxno][7],0); // play note
}

