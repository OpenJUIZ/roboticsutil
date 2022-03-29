#pragma once
/**
 * @file MobileRobotKinematics.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date $DATE
 * 
 * @copyright Copyright (c) 2022
 */


#include <juiz/geometry.h>
/**
 * @brief 
 * 
 */
struct MobileRobotKinematics {

    juiz::Pose3D pose;

    double previousRightMotorAngle;
    double previousLeftMotorAngle;
    bool _angleIsInitialized;

    double trad;
    double rightWheelRadius;
    double leftWheelRadius;

    double leftWheelMotor;
    double rightWheelMotor;
    
    /**
     * @brief Construct a new MobileRobotKinematics object
     * 
     */
    MobileRobotKinematics(): _angleIsInitialized(false), previousLeftMotorAngle(0.0), previousRightMotorAngle(0.0), trad(0.331), rightWheelRadius(0.0975), leftWheelRadius(0.0975), leftWheelMotor(0.0), rightWheelMotor(0.0) {}
};
