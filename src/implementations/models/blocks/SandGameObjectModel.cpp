#include "SandGameObjectModel.hpp"

SandGameObjectModel::SandGameObjectModel()
{
    setSize(PIXEL_SIZE);
    setHitbox(PIXEL_SIZE);
}

std::string SandGameObjectModel::getObjectName() const
{
    return GAME_OBJECT_NAME;
}

std::string SandGameObjectModel::getTextureName() const
{
    return TEXTURE_NAME;
}

void SandGameObjectModel::update()
{
}
