#pragma once


class SoundManager
{
private:
	// full sound if player < 150 px, i.e., no attenuation
	const float MIN_DISTANCE{ 150 };
	const float ATTENUATION{ 15 };

	SoundBuffer m_fireBuffer;
	SoundBuffer m_fallInFireBuffer;
	SoundBuffer m_fallInWaterBuffer;
	SoundBuffer m_jumpBuffer;
	SoundBuffer m_reachGoalBuffer;

	Sound m_fire1Sound;
	Sound m_fire2Sound;
	Sound m_fire3Sound;
	// which of the fires sounds to play
	int m_nextSound{ 1 };
	Sound m_fallInFireSound;

	Sound m_fallInWaterSound;
	Sound m_jumpSound;
	Sound m_reachGoalSound;

public:
	SoundManager();

	void playFire(Vector2f emitterLocation, Vector2f listenerLocation);

	void playFallInFire();
	void playFallInWater();
	void playJump();
	void playReachGoal();
};