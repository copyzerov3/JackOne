#include "BusterBullet.h"


BusterBullet::BusterBullet()
{
}


BusterBullet::~BusterBullet()
{
}
bool BusterBullet::Init(Managers* managers,int x,int y)
{
	Texture* image;
	int speed, damage;
	ResourceManager* r = managers->GetResourceManager();
	switch (managers->GetGlobalsManager()->GetBusterLevel())
	{
	case 1:
		speed = 6;
		damage = 1;
		if (!r->GetTexture("BusterBulletOne", image))
			return false;
		break;
	case 2:
		speed = 8;
		damage = 2;
		if (!r->GetTexture("BusterBulletTwo", image))
			return false;
		break;
	case 3:
		speed = 8;
		damage = 3;
		if (!r->GetTexture("BusterBulletThree", image))
			return false;
		break;
	case 4:
		speed = 10;
		damage = 4;
		if (!r->GetTexture("BusterBulletFour", image))
			return false;
		break;
	default:
		return false;
	}

	Bullet::Init(image, speed, damage, x, y);
	return true;
}
