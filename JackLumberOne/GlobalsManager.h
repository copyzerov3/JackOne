#pragma once
class GlobalsManager
{
public:
	GlobalsManager()
	{
		m_difficulty = EASY;
		m_mode = NORMAL;
		m_scraps = 0;
	}
	~GlobalsManager(){}
	enum DIFFICULTY
	{
		EASY,MEDIUM,HARD
	};
	enum GAMETYPE
	{
		NORMAL,PICKED
	};
	enum AREAS
	{
		FOREST,MOUNTAIN,CITY,OCEAN,SPACE
	};
	void SetDifficulty(DIFFICULTY dif){ m_difficulty = dif; }
	DIFFICULTY GetDifficulty(){return m_difficulty;}
	
	void SetGameType(GAMETYPE type){m_mode = type; }
	GAMETYPE GetGameType(){ return m_mode; }
	
	unsigned int GetScraps(){ return m_scraps; }
	void SetScraps(unsigned int scraps)	{ m_scraps = scraps; }

	unsigned int GetBusterLevel()
	{
		return m_busterlvl;
	}
	void SetBusterLevel(unsigned int level)
	{
		m_busterlvl = level;
	}
	unsigned int GetArmorLevel()
	{
		return m_armorlvl;
	}
	void SetArmorLevel(unsigned int level)
	{
		m_armorlvl = level;
	}

	unsigned int GetHealthLevel(){ return m_healthlvl; }
	void SetHealthLevel(unsigned int level){ m_healthlvl = level; }

	unsigned int GetTreeLevel(){ return m_treeLaucherlvl; }
	void SetTreeLevel(unsigned int level){ m_treeLaucherlvl = level; }

	unsigned int GetLavaLevel(){ return m_lavaBalllvl; }
	void SetLavaLevel(unsigned int level){ m_lavaBalllvl = level; }

	unsigned int GetStaticLevel(){ return m_staticBalllvl; }
	void SetStaticLevel(unsigned int level){ m_staticBalllvl = level; }

	unsigned int GetWaterLevel(){ return m_waterGrenadelvl; }
	void SetWaterLevel(unsigned int level){ m_waterGrenadelvl = level; }

private :
	DIFFICULTY m_difficulty;
	GAMETYPE m_mode;
	unsigned int m_scraps;
	unsigned int m_busterlvl;
	unsigned int m_armorlvl;
	unsigned int m_healthlvl;
	unsigned int m_treeLaucherlvl;
	unsigned int m_lavaBalllvl;
	unsigned int m_staticBalllvl;
	unsigned int m_waterGrenadelvl;
};

