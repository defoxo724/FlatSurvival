#pragma once

#include "IKeyboardDetector.hpp"
#include <SFML/Window/Keyboard.hpp>

class SfmlKeyBoardDetector : public IKeyboardDetector
{

  public:
    bool isKeyPressed(Key key) override;
};