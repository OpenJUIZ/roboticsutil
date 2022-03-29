/**
 * @file MobileRobotKinematics.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date $DATE
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <juiz/juiz.h>
#include <juiz/container.h>

#include "MobileRobotKinematics.h"

using namespace juiz;

extern "C" {
    /**
     * @brief Create a MobileRobotKinematics object
     * 
     * @return JUIZ_OPERATION*
     */
    JUIZ_OPERATION  void* createMobileRobotKinematics() {
        return containerFactory<MobileRobotKinematics>();
    }

}

