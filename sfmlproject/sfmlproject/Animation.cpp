#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(Sprite& sprite, float x, float y, float frameWidth, float frameHeight, float framecount, float animspeed)
	:sprite(&sprite),
	x(x),
	y(y),
	frameWidth(frameWidth),
	frameHeight(frameHeight),
	frameCount(framecount),
	animSpeed(animspeed),
	frames(0)
{

}

void Animation::update()
{
	frames += animSpeed;
	if (frames > frameCount)
	{
		frames -= frameCount;
	}
	sprite->setTextureRect(IntRect((int)frames * x, y, frameWidth, frameHeight));

}
