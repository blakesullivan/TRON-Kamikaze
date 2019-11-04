//Blake Sullivan - Attributes.h
#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

class Attributes
{
protected:
	int iHealth;
	int iShield;
	bool bShieldAlive;
	int iLives;
	int iPoints;
	int iBulletType;
	int iBulletMax;
	int iBulletDamage;
	bool bAlive;
	int iCollisionDamage;
	bool bExplode;
	static const int CIMAXHEALTH = 50, CIMAXSHIELD = 100;

public:
	Attributes();

	void SetupAttr(int, int, bool, int, int, int, int, int, bool, int);

	bool TakeDamageReturnDead(int);
	void Destroy();

	void SetHealth(int);
	void SetShield(int);
	void SetShieldAlive(bool);
	void SetLives(int);
	void SetPoints(int);
	void SetBulletType(int);
	void SetBulletMax(int);
	void SetBulletDamage(int);
	void SetAlive(bool);
	void SetCollisionDamage(int);
	void SetExplode(bool);

	int GetHealth();
	int GetShield();
	bool GetShieldAlive();
	int GetLives();
	int GetPoints();
	int GetBulletType();
	int GetBulletMax();
	int GetBulletDamage();
	bool GetAlive();
	int GetCollisionDamage();
	bool GetExplode();
	int GetMaxHealth();
	int GetMaxShield();
};
#endif