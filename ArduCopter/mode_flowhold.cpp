#include "Copter.h"
#include "defines.h"

#if MODE_FLOWHOLD_ENABLED == ENABLED

bool ModeFlowHold::init(bool ignore_checks)
{
    return ModeFlowHold::init(ignore_checks);
}

void ModeFlowHold::set_ekf3_source()
{
    // set secondary optical flow source for position control
    ahrs.set_posvelyaw_source_set(SECONDARY_SOURCE);
}

#endif