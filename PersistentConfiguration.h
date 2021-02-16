/**
 * @file PersistentConfiguration.h
 * @copyright 2021 Bernd Wachter
 * @author Bernd Wachter <bernd-github@wachter.fi>
 * @date 2021
 */

#ifndef _PERSISTENTCONFIGURATION_H
#define _PERSISTENTCONFIGURATION_H

/*
 * This is disabled to avoid masking incorrect defines of custom configuration
 * structures. It can be enabled (or just defined like this) in the sketch
 * for using the minimal configuration structure by just removing the two
 * spaces below. Note that if this is enabled here, and an improperly
 * defined custom structure used additional members may get overwritten
 * in memory.
 * /
#ifndef CONFIG_STRUCT
#define CONFIG_STRUCT PersistentConfig
#endif
/ *
*/

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
