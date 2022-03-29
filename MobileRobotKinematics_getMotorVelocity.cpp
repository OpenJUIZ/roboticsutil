#include <juiz/juiz.h>
#include <juiz/container.h>

#include "MobileRobotKinematics.h"

using namespace juiz;


extern "C" {

    JUIZ_OPERATION  void* MobileRobotKinematics_getMotorVelocity() {
        return containerOperationFactory<MobileRobotKinematics>(
            {
              {"typeName", "getMotorVelocity"},
              {"defaultArg", {
                  {"left_or_right", "left"}
              }},
            },
            [](auto& container, auto arg) {
                if (arg["left_or_right"].isStringValue()) {
                    return Value::error("MobileRobotKinematics_getMotorVelocity failed. Argument 'left_or_right' must be string value 'left' or 'right'. ");
                }
                if (arg["left_or_right"].stringValue() == "left") {
                    return Value{container.leftWheelMotor};
                } else if (arg["left_or_right"].stringValue() == "right") {
                    return Value{container.rightWheelMotor};
                } 
                
                return Value::error("MobileRobotKinematics_getMotorVelocity failed. Argument 'left_or_right' must be string value 'left' or 'right'. ");
            }
        );
    }

}
