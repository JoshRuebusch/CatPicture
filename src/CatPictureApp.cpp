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
	bool reverseR;
	bool reverseG;
	bool reverseB;
	bool stopR;
	bool stopG;
	bool stopB;
};

void CatPictureApp::setup()
{
	colorR = 0.0f;
	colorG = 0.0f;
	colorB = 0.0f;
	selector = 0;
	reverseR = false;
	reverseG = false;
	reverseB = false;
	stopR = false;
	stopG = false;
	stopB = false;
}

void CatPictureApp::mouseDown( MouseEvent event )
{
}

void CatPictureApp::update()
{
	selector = rand() % 3 + 1;
	if (selector == 1 && stopR == false)
		colorR = colorR + 0.01f;
	else if (selector == 2 && stopG == false)
		colorG = colorG + 0.01f;
	else if (selector == 3 && stopB == false) 
		colorB = colorB +0.01f;
	if (colorR > 1.0f)
	{
		reverseR = true;
		stopG = true;
		stopB = true;
	}
	if (colorG > 1.0f)
	{
		stopR = true;
		reverseG = true;
		stopB = true;
	}
	if (colorB > 1.0f)
	{
		stopR = true;
		stopG = true;
		reverseB = true;
	}

	if (reverseR == true)
	{
		colorR = colorR - 0.01f;
		if (colorR < 0)
		{
			reverseR = false;
			stopG = false;
			stopB = false;
		}
	}

	if (reverseG == true)
	{
		colorG = colorG - 0.01f;
		if (colorG < 0)
		{
			stopR = false;
			reverseG = false;
			stopB = false;
		}
	}

	if (reverseB == true)
	{
		colorB = colorB - 0.01f;
		if (colorB < 0)
		{
			stopR = false;
			stopG = false;
			reverseB = false;
		}
	}

}

void CatPictureApp::draw()
{
	// clear out the window with black
	gl::clear( Color( colorR, colorG, colorB ) ); 
}

CINDER_APP_BASIC( CatPictureApp, RendererGl )
