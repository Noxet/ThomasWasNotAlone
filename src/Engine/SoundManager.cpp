#include "tpch.hpp"

#include "SoundManager.hpp"


SoundManager::SoundManager()
{
	m_fireBuffer.loadFromFile("../assets/sfx/fire1.wav");
	m_fallInFireBuffer.loadFromFile("../assets/sfx/fallinfire.wav");
	m_fallInWaterBuffer.loadFromFile("../assets/sfx/fallinwater.wav");
	m_jumpBuffer.loadFromFile("../assets/sfx/jump.wav");
	m_reachGoalBuffer.loadFromFile("../assets/sfx/reachgoal.wav");

	// Fire sounds, spatialized
	m_fire1Sound.setBuffer(m_fireBuffer);
	m_fire1Sound.setMinDistance(MIN_DISTANCE);
	m_fire1Sound.setAttenuation(ATTENUATION);
	m_fire1Sound.setLoop(true);	// always be loopin'
	
	m_fire2Sound.setBuffer(m_fireBuffer);
	m_fire2Sound.setMinDistance(MIN_DISTANCE);
	m_fire2Sound.setAttenuation(ATTENUATION);
	m_fire2Sound.setLoop(true);	// always be loopin'

	m_fire3Sound.setBuffer(m_fireBuffer);
	m_fire3Sound.setMinDistance(MIN_DISTANCE);
	m_fire3Sound.setAttenuation(ATTENUATION);
	m_fire3Sound.setLoop(true);	// always be loopin'

	// other non-spatialized sounds
	m_fallInFireSound.setBuffer(m_fallInFireBuffer);
	m_fallInWaterSound.setBuffer(m_fallInWaterBuffer);
	m_jumpSound.setBuffer(m_jumpBuffer);
	m_reachGoalSound.setBuffer(m_reachGoalBuffer);
}


void SoundManager::playFire(Vector2f emitterLocation, Vector2f listenerLocation)
{
	// Where is the listener, i.e., Thomas?
	sf::Listener::setPosition(listenerLocation.x, listenerLocation.y, 0.f);

	switch (m_nextSound)
	{
	case 1:
		// Set the source of the sound
		m_fire1Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.f);

		if (m_fire1Sound.getStatus() == Sound::Status::Stopped)
		{
			m_fire1Sound.play();
		}
		break;

	case 2:
		m_fire2Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.f);

		if (m_fire2Sound.getStatus() == Sound::Status::Stopped)
		{
			m_fire2Sound.play();
		}
		break;

	case 3:
		m_fire3Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.f);

		if (m_fire3Sound.getStatus() == Sound::Status::Stopped)
		{
			m_fire3Sound.play();
		}
		break;
	}

	++m_nextSound;

	if (m_nextSound > 3) m_nextSound = 1;
}
