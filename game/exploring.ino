double shipx=0, shipy=0;
double shipspeedx=0, shipspeedy=0;
const int tilew=8, tileh=8;

// Tile for the background 
void drawTile(int x, int y)
{
  arduboy.drawRect(x*tilew,y*tileh,tilew,tileh);
}

void drawSea()
{
  for(int i=0;i<WIDTH/tilew;i++)
  for(int j=0;j<HEIGHT/tileh;j++)
  drawTile(i,j);
}

void doExploringGame()
{
  arduboy.clear();
  tinyfont.setCursor(0,0);
  tinyfont.print("Exploring");

  drawSea();
  arduboy.display();
}

