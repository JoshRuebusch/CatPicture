#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CatPictureApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

private:
	float colorR;
	float colorG;
	float colorB;
	int selector;
};

void CatPictureApp::setup()
{
	colorR = 0.0f;
	colorG = 0.0f;
	colorB = 0.0f;
	selector = 0;
}

void CatPictureApp::mouseDown( MouseEvent event )
{
}

void CatPictureApp::update()
{
	selector = rand() % 3 + 1;
	if (selector == 1)
		colorR = colorR + 0.01f;
	else if (selector == 2)
		colorG = colorG + 0.01f;
	else 
		colorB = colorB +0.01f;
	if (colorR > 1.0f)
		colorR = 0.0f;
	if (colorG > 1.0f)
		colorG = 0.0f;
	if (colorB > 1.0f)
		colorB = 0.0f;
}

void CatPictureApp::draw()
{
	// clear out the window with black
	gl::clear( Color( colorR, colorG, colorB ) ); 
}

CINDER_APP_BASIC( CatPictureApp, RendererGl )
