#include <juiz/juiz.h>
#include <juiz/container.h>

#include <cmath>
#define _USE_MATH_DEFINES

#include "MobileRobotKinematics.h"

using namespace juiz;


extern "C" {

    inline double normalize(double a) {
        while (a > M_PI) { a -= 2*M_PI; }
        while (a < -M_PI) { a += 2*M_PI; }
        return a;
    }

    JUIZ_OPERATION  void* MobileRobotKinematics_updatePose() {
        return containerOperationFactory<MobileRobotKinematics>(
            {
              {"typeName", "updatePose"},
              {"defaultArg", {
                  {"rightMotorAngle", 0.0},
                  {"leftMotorAngle", 0.0},
              }},
            },
            [](auto& container, auto arg) {
                logger::trace("MobileRobotKinematics_updatePose({}) called", arg);
                const double rightWheelAngle = getDoubleValue(arg["rightMotorAngle"], 0.0);
                const double leftWheelAngle = getDoubleValue(arg["leftMotorAngle"], 0.0);
                if (container._angleIsInitialized) {
                    logger::verbose(" - initialized. updatePose (left={}, right={}).", leftWheelAngle, rightWheelAngle);
                    const double axleTrack = container.trad;
                    const double rightWheelRadius = container.rightWheelRadius;
                    const double leftWheelRadius = container.leftWheelRadius;

                    const double& x = container.pose.position.x;
                    const double&y = container.pose.position.y;
                    const auto& orientation = juiz::QuaternionToEulerXYZ(container.pose.orientation);
                    const double& theta = orientation.z;

                    const double deltaR = normalize(rightWheelAngle - container.previousRightMotorAngle) * rightWheelRadius;
                    const double deltaL = normalize(leftWheelAngle - container.previousLeftMotorAngle) * leftWheelRadius;

                    const double deltaTrans = (deltaR + deltaL) / 2;
                    const double deltaTheta = (deltaR - deltaL) / axleTrack;

                    logger::verbose(" - deltaTrans : {}", deltaTrans);
                    logger::verbose(" - deltaTheta : {}", deltaTheta);

                    container.pose.position.x = x + deltaTrans * cos(theta + deltaTheta/2);
                    container.pose.position.y = y + deltaTrans * sin(theta + deltaTheta/2);
                    container.pose.orientation = juiz::EulerXYZToQuaternion({0, 0, theta + deltaTheta});
                }
                container.previousRightMotorAngle = rightWheelAngle;
                container.previousLeftMotorAngle = leftWheelAngle;
                container._angleIsInitialized = true;
                auto v =  juiz::toValue(container.pose);
                logger::verbose(" - returns {}", v);
                return v;
            }
        );
    }

}
