#include "Player.h"
#include "BusterWeapon.h"
#include "Managers.h"
Player::Player() : m_x(0), m_y(0)
{

	
}


Player::~Player()
{
}

bool Player::Init()
{
	m_weapon = new BusterWeapon();
	if (!Managers::GetResourceManager()->GetTexture("Player", m_player))
	{
		printf("Could not load the player image\n"); 
		return false;
	}
	
	m_hitbox.Init(m_x, m_y, m_player->GetWidth(), m_player->GetHeight());

	return true;
}
void Player::Draw()
{
	m_player->Render( m_x, m_y);
}
void Player::Update()
{
	InputManager* im = Managers::GetInputManager();
	if (im->GetUp() && !im->GetDown())
	{
		m_y-= m_speed;
		if (m_y < 0)
			m_y = 0;

	}
	else if (im->GetDown() && !im->GetUp())
	{
		m_y+=m_speed;
		if (m_y + GetHeight() > Managers::GetGraphicsManager()->GetScreenHeight())
			m_y = Managers::GetGraphicsManager()->GetScreenHeight() - GetHeight();
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
		if (m_x + GetWidth() > Managers::GetGraphicsManager()->GetScreenWidth())
			m_x = Managers::GetGraphicsManager()->GetScreenWidth() - GetWidth();
	}
	if (im->GetAttack())
	{
		if (m_weapon->CanFire())
		{
			m_weapon->Fire(m_x + GetWidth(), m_y + (GetHeight() / 2));
		}
			
	}

	m_hitbox.SetPosition(m_x, m_y);
}
