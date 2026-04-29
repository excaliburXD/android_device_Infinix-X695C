#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <android-base/properties.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

using android::base::GetProperty;
using std::string;

void property_override(string prop, string value)
{
    auto pi = (prop_info *)__system_property_find(prop.c_str());

    if (pi != nullptr)
        __system_property_update(pi, value.c_str(), value.size());
    else
        __system_property_add(prop.c_str(), prop.size(), value.c_str(), value.size());
}

void vendor_load_properties()
{
    string prop_partitions[] = {"", "vendor.", "odm."};
    for (const string &prop : prop_partitions)
    {
        property_override(string("ro.product.") + prop + string("brand"), "Infinix");
        property_override(string("ro.product.") + prop + string("name"), "X695C-GL");
        property_override(string("ro.product.") + prop + string("device"), "Infinix-X695C");
        property_override(string("ro.product.") + prop + string("model"), "Infinix X695C");
        property_override(string("ro.product.") + prop + string("marketname"), "Infinix Note 10 Pro");
        property_override(string("ro.product.system.") + prop + string("device"), "Infinix Note 10 Pro");
    }

    // [FIX] Override critical properties for normal boot compatibility.
    // The OrangeFox/TWRP build system sets recovery-specific values that prevent
    // normal Android boot. These overrides ensure the ramdisk properties match
    // what the stock system partition expects when init does switch_root for
    // normal boot via the ForceNormalBoot mechanism.
    //
    // ro.zygote=zygote64_32: Stock firmware uses both 64-bit and 32-bit zygote
    //   because the device supports armeabi-v7a apps. OrangeFox sets zygote64 only.
    // ro.secure=1: Stock is user build. OrangeFox sets 0 (eng build).
    // ro.debuggable=0: Stock is release. OrangeFox sets 1 (debuggable).
    // ro.adb.secure=1: Stock enables ADB auth. OrangeFox disables it.
    // persist.sys.usb.config=none: Stock disables USB by default. OrangeFox sets adb.
    property_override("ro.zygote", "zygote64_32");
    property_override("ro.secure", "1");
    property_override("ro.debuggable", "0");
    property_override("ro.adb.secure", "1");
    property_override("persist.sys.usb.config", "none");
    property_override("ro.allow.mock.location", "0");
    property_override("ro.sf.lcd_density", "480");
    property_override("ro.oem_unlock_supported", "1");
}