/*Joshua Ruebusch
CSE 274 A
Instructor: Dr. Brinkman
This program changes the color of the background frame. It does so by incrementally changing the RGB levels and then once a certain 
color becomes full, drains it away also incrementally until reaching 0. Then starts building up color randomly again until antoher
becomes full. 
*/

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
	// ^ these keep track of RGB levels
	int selector;
	//^ selects which color will change
	bool reverseR;
	bool reverseG;
	bool reverseB;
	//^ keeps track of which color will increment negatively
	bool stopR;
	bool stopG;
	bool stopB;
	//^ keeps track of which colors should stop changing for a while
};

void CatPictureApp::setup()
{
	//all initalized to 0.0f or false
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
	//randomly select number 1-3 to pick which color changes
	selector = rand() % 3 + 1;
	if (selector == 1 && stopR == false)
		colorR = colorR + 0.01f;
	else if (selector == 2 && stopG == false)
		colorG = colorG + 0.01f;
	else if (selector == 3 && stopB == false) 
		colorB = colorB +0.01f;

	// if statements that switch boolean variables accordingly for which color should reverse and which should stop
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
	//decrease red levels slowly until 0
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
	//decrease green levels until 0
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
	//decrease blue levels until 0
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
