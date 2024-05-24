/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../../../inc/MarlinConfig.h"

#if HAS_TRINAMIC_CONFIG

#include "../../gcode.h"
#include "../../../feature/tmc_util.h"
#include "../../../module/stepper/indirection.h" // for restore_stepper_drivers
#include "../../../module/stepper/trinamic.h"

/**
 * M9999: Show Encoder Status
 */
void GcodeSuite::M9999() {
  #if ENABLED(TMC_DEBUG)
    #if ENABLED(MONITOR_DRIVER_STATUS)
    uint8_t enc_status = stepperX.ENC_STATUS();
    if (enc_status & 0x01) {
      SERIAL_ECHOLNPGM("Encoder not ready");
      SERIAL_ECHOLN(enc_status);
    } else {
      SERIAL_ECHOLNPGM("Encoder ready");
      SERIAL_ECHOLN(enc_status);
    }

    uint32_t enc_deviation = stepperX.ENC_DEVIATION();
    SERIAL_ECHOLNPGM("Encoder deviation: ");
    SERIAL_ECHOLN(enc_deviation);
    #endif
  #endif
}

#endif // HAS_TRINAMIC_CONFIG
