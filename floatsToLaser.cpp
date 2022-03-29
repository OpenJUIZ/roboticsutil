/**
 * @file floatsToLaser.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date $DATE
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <juiz/juiz.h>
#include <juiz/operation.h>

using namespace juiz;

extern "C" {
    /**
     * @brief Create operationFactory object for floatsToLaser operation
     * 
     * @return JUIZ_OPERATION* 
     */
    JUIZ_OPERATION void* floatsToLaser() {
        return operationFactory(
          {
            {"typeName", "floatsToLaser"},
            {"defaultArg", {
              {"minAngle", -2.3562},
              {"maxAngle", 2.3562},
              {"maxRange", 5.0},
              {"minRange", 0.3},
              {"ranges", Value::list()},
              {"__TYPE__", "Robotics::LaserScan2D"}
            }},
          },
          [](auto arg) -> juiz::Value {
            return arg;
            /*
            const double minAngle = getDoubleValue(arg["minAngle"], -2.3562);
            const double maxAngle = getDoubleValue(arg["maxAngle"], +2.3562);
            const double maxRange = getDoubleValue(arg["maxRange"], 5.0);
            const double minRange = getDoubleValue(arg["minRange"], 0.3);
            if (arg["value"].isListValue()) {
              auto& listValue = arg["value"].listValue();
              v = arg;
              v["ranges"] = 
            }
            */
          });
    }
}
