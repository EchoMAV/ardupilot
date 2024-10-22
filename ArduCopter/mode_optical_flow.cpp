#include "Copter.h"
#include "defines.h"

#if MODE_OPTICAL_FLOW_ENABLED == ENABLED

bool ModeOpticalFlow::init(bool ignore_checks)
{
    return ModeLoiter::init(ignore_checks);
}

void ModeOpticalFlow::set_ekf3_source()
{
    // set secondary optical flow source for position control
    ahrs.set_posvelyaw_source_set(SECONDARY_SOURCE);
}

#endif