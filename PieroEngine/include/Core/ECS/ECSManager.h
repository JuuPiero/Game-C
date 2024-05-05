#pragma once

namespace Piero {
class ECSManager {

public:
    ECSManager();
    ~ECSManager();
private:
    static ECSManager* s_Instance;

};

ECSManager* ECSManager::s_Instance = nullptr;

ECSManager::ECSManager(/* args */)
{
}

ECSManager::~ECSManager()
{
}


}