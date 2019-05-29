#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(Sprite& sprite, float x, float y, float frameWidth, float frameHeight, float framecount, float animspeed, int animCycle)
	:sprite(&sprite),
	x(x),
	y(y),
	frameWidth(frameWidth),
	frameHeight(frameHeight),
	frameCount(framecount),
	animSpeed(animspeed),
	animCycle(animCycle),
	frames(0),
	totalCycles(animCycle)
{

}

void Animation::reset()
{
	frames = 0;
	animComplete = false;
	animCycle = totalCycles;
}



void Animation::update()
{

	frames += animSpeed;

	switch (animCycle)
	{
	case 0:
		animComplete = true;
		break;
	default:
		animComplete = false;
	}

	if (animComplete)
		return;

	if (frames > frameCount)
	{
		frames -= frameCount;
		if(animCycle>0)
			animCycle--;
	}
	
	sprite->setTextureRect(IntRect((int)frames * x, y, frameWidth, frameHeight));
}


