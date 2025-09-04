#include "Copter.h"
#include <utility>

#if MODE_FLOWHOLD_ENABLED

bool ModeFlowHold::init(bool ignore_checks)
{
    // Fetch current altitude from the barometer (ASL)
    float current_alt_m = AP::baro().get_altitude();

    // Prevent mode switch if the altitude is too high
    if (copter.motors->armed()){
        float relative_alt_m = current_alt_m - copter.arming_altitude_m;
        if (relative_alt_m >= 19.0f) {
            gcs().send_text(MAV_SEVERITY_ALERT, "Altitude too high for flow mode");
            gcs().send_text(MAV_SEVERITY_INFO, "Relative altitude above home = %.2f m", relative_alt_m);
            return false;
        }
    } else {
        gcs().send_text(MAV_SEVERITY_INFO, "Flow hold enabled at = %.2f m", current_alt_m);
    }

    return ModeLoiter::init(ignore_checks);
}

void ModeFlowHold::set_ekf3_source()
{
    // set secondary optical flow source for position control
    ahrs.set_posvelyaw_source_set(SECONDARY_SOURCE);
}

#endif