#include <juiz/juiz.h>
#include <juiz/container.h>

#include "MobileRobotKinematics.h"

using namespace juiz;


extern "C" {

    JUIZ_OPERATION  void* MobileRobotKinematics_getPose() {
        return containerOperationFactory<MobileRobotKinematics>(
            {
              {"typeName", "getPose"},
              {"defaultArg", {
              }},
            },
            [](auto& container, auto arg) {
                logger::trace_object to("MobileRobotKinematics_getPose() called.");
                
                return juiz::toValue(container.pose);
            }
        );
    }

}
