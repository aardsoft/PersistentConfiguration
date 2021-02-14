/**
 * @file PersistentConfiguration.h
 * @copyright 2021 Bernd Wachter
 * @author Bernd Wachter <bernd-github@wachter.fi>
 * @date 2021
 */

#ifndef _PERSISTENTCONFIGURATION_H
#define _PERSISTENTCONFIGURATION_H

#ifndef CONFIG_STRUCT
#define CONFIG_STRUCT PersistentConfig
#endif

#ifndef STATE_STRUCT
#define STATE_STRUCT PersistentState
#endif

#ifndef CONFIG_MAGIC
#define CONFIG_MAGIC 0xA001
#endif

struct PersistentConfig{
    unsigned int magic;
    // MAC address used by this device
    char mac[18];
};

struct PersistentState{
    // track if there are unsaved config changes
    bool config_changed = false;
};

extern CONFIG_STRUCT config;
extern STATE_STRUCT state;

class PersistentConfiguration{
  public:
    PersistentConfiguration();
    void save();
    void load();
};

#endif
