#include "StoneGameObjectModel.hpp"

StoneGameObjectModel::StoneGameObjectModel()
{
    setSize(PIXEL_SIZE);
    setHitbox(PIXEL_SIZE);
}

std::string StoneGameObjectModel::getObjectName() const
{
    return GAME_OBJECT_NAME;
}

std::string StoneGameObjectModel::getTextureName() const
{
    return TEXTURE_NAME;
}

void StoneGameObjectModel::update()
{
}
