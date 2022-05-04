// quick note about namespaces in my """""engine""""""
// managers and ordinary things you'll probably use are in a namespace called 'fr'
// individual things, like some specific utilities for example,
// that already have wrappers/managers for them, are in the namespace 'fr_util'
// if you wanna have some more elasticity you can use these individual
// utilities and create your own wrappers/managers for them

#pragma once

#include "Farfocel/Utils/StateManager/IState.hpp"
#include "Farfocel/Utils/StateManager/StateManager.hpp"

#include "Farfocel/Utils/FunctionBinder.hpp"
#include "Farfocel/Utils/EventManager.hpp"
#include "Farfocel/Utils/InputManager.hpp"

#include "Farfocel/Utils/Log.hpp"

#include "Farfocel/Utils/ResourceManager/ResourceManager.hpp"
#include "Farfocel/Utils/ResourceManager/Asset.hpp"

#include "Farfocel/Utils/AnimationManager/Animation.hpp"