#include "CAnimation.hpp"

/*explicit*/ CAnimation::CAnimation()
{
  LOG("CAnimation Constructor\n");

  m_currentFrame = 0;
  m_loop = false;
}

/*virtual*/ CAnimation::~CAnimation()
{
  LOG("CAnimation Destructor\n");
}

void CAnimation::addFrame(const sf::IntRect& frame, float timeToNextFrame)
{
  m_frames.push_back(Frame(frame, timeToNextFrame));
}

const sf::IntRect CAnimation::getFrame()
{
  if (m_timer.getElapsedTime().asSeconds() >= m_frames[m_currentFrame].timeToNextFrame)
  {
      m_currentFrame++;
      if (m_currentFrame >= m_frames.size()){
          m_currentFrame = 0;
          m_loop = true;
      }
      m_timer.restart();
  }

  return  m_frames[m_currentFrame].frame;
}

bool CAnimation::isLoopDone(void){
  return m_loop;
}

const sf::IntRect CAnimation::getCurrentFrame()
{
  return  m_frames[m_currentFrame].frame;
}


void CAnimation::restart(void)
{
  m_currentFrame = 0;
  m_loop = false;
}
