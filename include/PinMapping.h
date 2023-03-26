// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include <Arduino.h>
#include <stdint.h>
#include <ETH.h>

#define PINMAPPING_FILENAME "/pin_mapping.json"

#define MAPPING_NAME_STRLEN 31

struct PinMapping_t {
    char name[MAPPING_NAME_STRLEN + 1];
    int8_t nrf24_miso;
    int8_t nrf24_mosi;
    int8_t nrf24_clk;
    int8_t nrf24_irq;
    int8_t nrf24_en;
    int8_t nrf24_cs;
    int8_t eth_phy_addr;
    bool eth_enabled;
    int eth_power;
    int eth_mdc;
    int eth_mdio;
    eth_phy_type_t eth_type;
    eth_clock_mode_t eth_clk_mode;
    uint8_t display_type;
    uint8_t display_data;
    uint8_t display_clk;
    uint8_t display_cs;
    uint8_t display_reset;
    uint8_t victron_tx;
    uint8_t victron_rx;
    uint8_t battery_rx;
    uint8_t battery_tx;
    uint8_t huawei_miso;
    uint8_t huawei_mosi;
    uint8_t huawei_clk;
    uint8_t huawei_irq;
    uint8_t huawei_cs;
    uint8_t huawei_power;
};

class PinMappingClass {
public:
    PinMappingClass();
    bool init(const String& deviceMapping);
    PinMapping_t& get();

    bool isValidNrf24Config();
    bool isValidEthConfig();
    bool isValidVictronConfig();
    bool isValidBatteryConfig();
    bool isValidHuaweiConfig();
    
private:
    PinMapping_t _pinMapping;
};

extern PinMappingClass PinMapping;
