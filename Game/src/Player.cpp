#include "Player.h"

void Player::Start() {}

Player::Player(): GameObject() {
    m_Texture = std::make_shared<Piero::Texture>("../../assets/_Idle.png");
    m_Texture->scale = Vector2D(2, 2);
    scale = m_Texture->scale;
    size = Vector2D(120, 80);
    ChangeState(State::idle);
}

void Player::Update() {
   
    position = position + velocity;

    if(position.y + velocity.y + size.y * scale.y >= Piero::PieroEngine::GetInstance()->GetWindowProps().height) {
        velocity.y = 0;
    }
    else velocity.y += GRAVITY;

    if(Piero::Input::GetKeyDown("Space")) {
        velocity.y = -5;
    }

    if(Piero::Input::GetKeyDown("ArrowLeft")) {
        IsFacingRight = false;
        velocity.x = -2;
    }
    else if(Piero::Input::GetKeyDown("ArrowRight")) {
        IsFacingRight = true;
        velocity.x = 2;
    }
    else {
        velocity.x = 0;
    }

    if(velocity.x != 0) ChangeState(Player::State::running);
    else ChangeState(Player::State::idle);

    // FillCircle(300, 300, 40);
    // SetFillStyle(255, 0, 100, 255);
    // FillRect(position.x, position.y, size.x * scale.x, size.y * scale.y);
    m_Frame = (SDL_GetTicks() / m_AnimationSpeed) % m_FrameCount;
    m_Texture->DrawFrame(position.x, position.y, size.x, size.y, 0, m_Frame, !IsFacingRight);
}

void Player::ChangeState(State state) {
    currentState = state;

    switch (currentState) {
        case State::idle:
            m_Texture->LoadImage("../../assets/_Idle.png");
            break;
        case State::running:
            m_Texture->LoadImage("../../assets/_Run.png");
            break;
    }
    m_FrameCount =  m_Texture->GetImageWidth() / size.x;
}