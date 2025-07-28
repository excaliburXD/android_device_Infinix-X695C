#
# Copyright (C) 2024 The TWRP Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

DEVICE_PATH := device/infinix/Infinix-X695C

# Inherit from mt6785-common
include device/transsion/mt6785-common/BoardConfigCommon.mk

# Assert
TARGET_OTA_ASSERT_DEVICE := Infinix-X695C

# TWRP Configs
TW_DEVICE_VERSION := Infinix-X695C | ExcaliburXD

# Init
TARGET_INIT_VENDOR_LIB := libinit_Infinix-X695C
TARGET_RECOVERY_DEVICE_MODULES := libinit_Infinix-X695C