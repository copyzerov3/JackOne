#include "Player.h"
#include "BusterWeapon.h"

Player::Player() : m_x(0), m_y(0)
{

	
}


Player::~Player()
{
}

bool Player::Init(Managers *managersRef)
{
	m_managers = managersRef;
	ResourceManager* r = managersRef->GetResourceManager();
	m_weapon = new BusterWeapon(m_managers);
	if (!r->GetTexture("Player", m_player))
		return false;
	return true;
}
void Player::Draw(SDL_Renderer* r)
{
	m_player->Render(r, m_x, m_y);
}
void Player::Update(InputManager *im,int WIDTH,int HEIGHT)
{
	if (im->GetUp() && !im->GetDown())
	{
		m_y-= m_speed;
		if (m_y < 0)
			m_y = 0;

	}
	else if (im->GetDown() && !im->GetUp())
	{
		m_y+=m_speed;
		if (m_y + GetHeight() > HEIGHT)
			m_y = HEIGHT - GetHeight();
	}
	if (im->GetLeft() && !im->GetRight())
	{
		m_x-=m_speed;
		if (m_x < 0)
			m_x = 0;

	}
	else if (im->GetRight() && !im->GetLeft())
	{
		m_x+=m_speed;
		if (m_x + GetWidth() > WIDTH)
			m_x = WIDTH - GetWidth();
	}
	if (im->GetAttack())
	{
		if (m_weapon->CanFire())
		{
			printf("FIRING\n");
			m_weapon->Fire(m_managers,m_x + GetWidth(), m_y + (GetHeight() / 2));
		}
			
	}
}
