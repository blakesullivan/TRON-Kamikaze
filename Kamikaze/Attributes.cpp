//Blake Sullivan - Attributes.cpp
#include "Attributes.h"

Attributes::Attributes()
{
	SetHealth(0);
	SetShield(0);
	SetShieldAlive(false);
	SetBulletMax(0);
	SetBulletType(0);
	SetBulletDamage(0);
	SetLives(0);
	SetPoints(0);
	SetExplode(false);
}

bool Attributes::TakeDamageReturnDead(int iDamage)
{
	if (bShieldAlive == true)
	{
		iShield -= iDamage;
		if (iShield <= 0)
		{
			SetShieldAlive(false);
			iDamage = iShield * -1;
			iShield = 0;
		}
		else
			{iDamage = 0;}
	}

	iHealth -= iDamage;
	if (iHealth <= 0)
	{
		iHealth = 0;
		return true;
	}
	else
		{return false;}
}

void Attributes::Destroy()
{
	SetAlive(false);
	SetLives(iLives-1);
	SetExplode(true);
}

void Attributes::SetupAttr(int h, int s, bool sa, int bt, int bm, int bd, int l, int p, bool a, int cd)
{
	SetHealth(h);
	SetShield(s);
	SetShieldAlive(sa);
	SetLives(l);
	SetPoints(p);
	SetBulletType(bt);
	SetBulletMax(bm);
	SetBulletDamage(bd);
	SetAlive(a);
	SetCollisionDamage(cd);
}

void Attributes::SetHealth(int iTemp)
{
	iHealth = iTemp;
}
void Attributes::SetShield(int iTemp)
{
	iShield = iTemp;
}
void Attributes::SetShieldAlive(bool bTemp)
{
	bShieldAlive = bTemp;
}
void Attributes::SetLives(int iTemp)
{
	iLives = iTemp;
}
void Attributes::SetPoints(int iTemp)
{
	iPoints = iTemp;
}
void Attributes::SetBulletType(int iTemp)
{
	iBulletType = iTemp;
}
void Attributes::SetBulletMax(int iTemp)
{
	iBulletMax = iTemp;
}
void Attributes::SetBulletDamage(int iTemp)
{
	iBulletDamage = iTemp;
}
void Attributes::SetAlive(bool bTemp)
{
	bAlive = bTemp;
}
void Attributes::SetCollisionDamage(int iTemp)
{
	iCollisionDamage = iTemp;
}
void Attributes::SetExplode(bool bTemp)
{
	bExplode = bTemp;
}

int Attributes::GetHealth()
{
	return iHealth;
}
int Attributes::GetShield()
{
	return iShield;
}
bool Attributes::GetShieldAlive()
{
	return bShieldAlive;
}
int Attributes::GetLives()
{
	return iLives;
}
int Attributes::GetPoints()
{
	return iPoints;
}
int Attributes::GetBulletType()
{
	return iBulletType;
}
int Attributes::GetBulletMax()
{
	return iBulletMax;
}
int Attributes::GetBulletDamage()
{
	return iBulletDamage;
}
bool Attributes::GetAlive()
{
	return bAlive;
}
int Attributes::GetCollisionDamage()
{
	return iCollisionDamage;
}
bool Attributes::GetExplode()
{
	return bExplode;
}
int Attributes::GetMaxHealth()
{
	return CIMAXHEALTH;
}
int Attributes::GetMaxShield()
{
	return CIMAXSHIELD;
}