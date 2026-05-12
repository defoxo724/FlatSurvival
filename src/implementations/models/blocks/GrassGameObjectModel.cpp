#include "GrassGameObjectModel.hpp"

GrassGameObjectModel::GrassGameObjectModel()
{
    setSize(PIXEL_SIZE);
    setHitbox(PIXEL_SIZE);
}

std::string GrassGameObjectModel::getObjectName() const
{
    return GAME_OBJECT_NAME;
}

std::string GrassGameObjectModel::getTextureName() const
{
    return TEXTURE_NAME;
}

void GrassGameObjectModel::update()
{
}
