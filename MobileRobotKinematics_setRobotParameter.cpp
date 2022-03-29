#include <juiz/juiz.h>
#include <juiz/container.h>

#include "MobileRobotKinematics.h"

using namespace juiz;


extern "C" {

    JUIZ_OPERATION  void* MobileRobotKinematics_setRobotParameter() {
        return containerOperationFactory<MobileRobotKinematics>(
            {
              {"typeName", "setRobotParameter"},
              {"defaultArg", {
                
                {"trad", 0.331},
                {"rightWheelRadius", 0.0975},
                {"leftWheelRadius", 0.0975}
                
              }},
            },
            [](auto& container, auto arg) {
                logger::trace("MobileRobotKinematics_setRobotParameter() called");
                container.trad = getDoubleValue(arg["trad"], 0.331);
                container.leftWheelRadius = getDoubleValue(arg["leftWheelRadius"], 0.0975);
                container.rightWheelRadius = getDoubleValue(arg["rightWheelRadius"], 0.0975);
                return Value{0};
            }
        );
    }

}
