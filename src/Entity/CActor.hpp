#pragma once

#include "CEntity.hpp"
#include "../ResourceManager/CResourceHolder.hpp"
#include "../Tools/DEBUG.hpp"
#include "../Tools/CDisplay.hpp"

class CActor : public CEntity
{

  struct Key { bool keyUp, keyLeft, keyDown, keyRight;};

  public:
    explicit CActor(float positionX, float positionY);
    virtual ~CActor(void);

    void setTexture(void) override;
    void setAnimation(void) override;

    void input(void) override;
    void update(float dt) override;

    void setInput(bool keyUp, bool keyLeft, bool keyDown, bool keyRight);

  private:
    Key m_key;
    const int WALK_SPEED = 60;

    enum Estate {e_idle, e_walk};

    enum Eorientation {e_bot, e_left, e_right, e_top};

    enum EAnimation {e_idle_bot, e_idle_left, e_idle_right, e_idle_top, e_walk_bot, e_walk_left, e_walk_right, e_walk_top};
    const unsigned int NB_ANIMATION = 8;
};
