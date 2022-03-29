#include <juiz/juiz.h>
#include <juiz/container.h>

#include "MobileRobotKinematics.h"

using namespace juiz;


extern "C" {

    JUIZ_OPERATION  void* MobileRobotKinematics_setTargetVelocity() {
        return containerOperationFactory<MobileRobotKinematics>(
            {
              {"typeName", "setTargetVelocity"},
              {"defaultArg", {
                  {"velocity", {
                      {"translation", {
                          {"x", 0.0},
                          {"y", 0.0}
                      }},
                      {"rotation", {
                          {"z", 0.0}
                      }}
                  }}
              }},
            },
            [](auto& container, auto arg) {
                const double& axleTrack = container.trad;
                const double& rightWheelRadius = container.rightWheelRadius;
                const double& leftWheelRadius = container.leftWheelRadius;
                const double va = getDoubleValue(arg["velocity"]["rotation"]["z"], 0.0);
                const double vx = getDoubleValue(arg["velocity"]["translation"]["x"], 0.0);
                const double v_buf = va * axleTrack/2;
                const double vr = vx + v_buf;
                const double vl = vx - v_buf;

                const double omegaR = vr /rightWheelRadius;
                const double omegaL = vl /leftWheelRadius;

                container.leftWheelMotor = omegaL;
                container.rightWheelMotor = omegaR;
                return Value {
                    {"leftWheelVelocity", omegaL},
                    {"rightWheelVelocity", omegaR}
                };
            }
        );
    }

}
