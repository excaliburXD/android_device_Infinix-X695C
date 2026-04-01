#
# Copyright (C) 2026 The Android Open Source Project
# Copyright (C) 2026 SebaUbuntu's TWRP device tree generator
#
# SPDX-License-Identifier: Apache-2.0
#

DEVICE_PATH := device/infinix/Infinix-X695C

# Inherit from mt6785-common
include device/transsion/mt6785-common/BoardConfigCommon.mk

# PBRP Configs
PB_DISABLE_DEFAULT_DM_VERITY := true

# Assert
TARGET_OTA_ASSERT_DEVICE := X695C,Infinix-X695C

# Maintainer
TW_DEVICE_VERSION := Infinix Note 10 Pro NFC | ExcaliburXD