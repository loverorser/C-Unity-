#include"WaitForSeconds.h"
#include"CoroutineManager.h"
WaitForSeconds::WaitForSeconds(float seconds) {
	m_Seconds = seconds;
}
bool WaitForSeconds::tick() {
	m_Seconds -= 1.0/CoroutineManager::frameRate;
	return m_Seconds <= 0;
}