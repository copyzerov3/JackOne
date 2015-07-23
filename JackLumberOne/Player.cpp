#include "Player.h"
#include "BusterWeapon.h"
#include "Managers.h"
Player::Player() : m_x(0), m_y(0), m_maxHealth(0), m_health(0)
{

	
}


Player::~Player()
{
}

bool Player::Init()
{
	//create base weapon for instance.
	m_weapon = new BusterWeapon();
	//Get the image for the player if fail return false abort game.
	if (!Managers::GetResourceManager()->GetTexture("Player", m_player))
	{
		printf("Could not load the player image\n"); 
		return false;
	}
	
	//Determine what the base health should be.
	switch (Managers::GetGlobalsManager()->GetDifficulty())
	{
	case GlobalsManager::DIFFICULTY::EASY:
	case GlobalsManager::DIFFICULTY::MEDIUM:
		m_maxHealth = 100;
		break;
	case GlobalsManager::DIFFICULTY::HARD:
		m_maxHealth = 50;
		break;
	}
	//add any health bonus if needed.
	switch (Managers::GetGlobalsManager()->GetHealthLevel())
	{
	case 2:
		m_maxHealth += 33;
		break;
	case 3:
		m_maxHealth += 66;
		break;
	case 4:
		m_maxHealth += 100;
		break;
	}
	//set health to the max health
	m_health = m_maxHealth;
	//create and set the label for the health.
	m_healthLabel = new Texture();
	UpdateHealthText();
	//set the hitbox for collision detection
	m_hitbox.Init(m_x, m_y, m_player->GetWidth(), m_player->GetHeight());
	return true;
}
void Player::Draw()
{
	m_player->Render( m_x, m_y);
	m_healthLabel->Render(m_x + m_player->GetWidth() - m_healthLabel->GetWidth(), m_y + m_player->GetHeight() - m_healthLabel->GetHeight());
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

void Player::TakeDamage(float damage)
{
	m_health -= damage;
	UpdateHealthText();
}
void Player::UpdateHealthText()
{
	SDL_Color color = { 0, 0, 0, 0 };
	m_healthLabel->LoadFromRenderedText(std::to_string((int)m_health), color, Managers::GetGraphicsManager()->GetFont());
}
