/**
 * @file PersistentConfiguration.cpp
 * @copyright 2021 Bernd Wachter
 * @author Bernd Wachter <bernd-github@wachter.fi>
 * @date 2021
 */

#include <EEPROM.h>

#include "PersistentConfiguration.h"

CONFIG_STRUCT config;
STATE_STRUCT state;

PersistentConfiguration::PersistentConfiguration(){
}

void PersistentConfiguration::save(){
  if (state.config_changed)
    EEPROM.put(0, config);
  state.config_changed=false;
}

void PersistentConfiguration::load(){
  EEPROM.get(0, config);
}
