#include "Copter.h"

#if MODE_GUIDED_NOGPS_ENABLED

/*
 * Init and run calls for guided_nogps flight mode
 */

// initialise guided_nogps controller
bool ModeGuidedNoGPS::init(bool ignore_checks)
{
    ahrs.set_posvelyaw_source_set(SECONDARY_SOURCE);
    // start in angle control mode
    ModeGuided::angle_control_start();
    return true;
}

// guided_run - runs the guided controller
// should be called at 100hz or more
void ModeGuidedNoGPS::run()
{
    // run angle controller
    ModeGuided::angle_control_run();
}

#endif
