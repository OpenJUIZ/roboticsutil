/**
 * @file valueSelector.cpp
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
     * @brief Create operationFactory object for valueSelector operation
     * 
     * @return JUIZ_OPERATION* 
     */
    JUIZ_OPERATION void* valueSelector() {
        return operationFactory(
          {
            {"typeName", "valueSelector"},
            {"defaultArg", {
                {"key", "keyValue"},
                {"value", Value{
                    {"keyValue", 0}
                }}
            }},
          },
          [](auto arg) {
              logger::trace("valueSelector(value) called");
              logger::verbose("- argument: {}", arg);
              const auto key = getStringValue(arg["key"], "");
              if (arg["value"].hasKey(key)) {
                  return arg["value"][key];
              }
              return Value::error(logger::error("valueSelector failed. The argument do not have the key {}.", key));
          });
    }
}
