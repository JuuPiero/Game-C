#pragma once
#include "PieroEngine.h"
class Player : public Piero::GameObject {
public:
    enum State { idle, running };
public:
    Player();
    ~Player() = default;
    void Update() override;
    void Start() override;

    void ChangeState(State state);
public:
    State currentState;
    Vector2D size;
    Vector2D velocity;
    bool IsFacingRight = true;
    const int GRAVITY = 1;

private:
    int m_Row = 0, m_Frame, m_FrameCount;
    int m_AnimationSpeed = 50;
    std::shared_ptr<Piero::Texture> m_Texture;
};

