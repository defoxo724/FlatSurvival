#include "ModelManagerImpl.hpp"

void ModelManagerImpl::addModel(std::shared_ptr<IGameObject> gameObject)
{
    gameObjects.push_back(gameObject);
}

void ModelManagerImpl::removeModel(std::shared_ptr<IGameObject> gameObject)
{
    gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gameObject), gameObjects.end());
}

std::vector<std::shared_ptr<IGameObject>> ModelManagerImpl::getGameObjects() const
{
    return gameObjects;
}

void ModelManagerImpl::update() const
{
    for (auto &el : gameObjects)
    {
        el->update();
    }
}

std::uint64_t ModelManagerImpl::size() const
{
    return gameObjects.size();
}
