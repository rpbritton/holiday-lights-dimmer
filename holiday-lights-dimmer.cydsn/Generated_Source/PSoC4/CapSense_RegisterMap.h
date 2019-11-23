/***************************************************************************//**
* \file CapSense_RegisterMap.h
* \version 5.0
*
* \brief
*   This file provides the definitions for the Component data structure register.
*
* \see CapSense v5.0 Datasheet
*
*//*****************************************************************************
* Copyright (2016-2017), Cypress Semiconductor Corporation.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*******************************************************************************/

#if !defined(CY_SENSE_CapSense_REGISTER_MAP_H)
#define CY_SENSE_CapSense_REGISTER_MAP_H

#include <cytypes.h>
#include "CapSense_Configuration.h"
#include "CapSense_Structure.h"

/*****************************************************************************/
/* RAM Data structure register definitions                                   */
/*****************************************************************************/
#define CapSense_CONFIG_ID_VALUE                            (CapSense_dsRam.configId)
#define CapSense_CONFIG_ID_OFFSET                           (0u)
#define CapSense_CONFIG_ID_SIZE                             (2u)
#define CapSense_CONFIG_ID_PARAM_ID                         (0x87000000u)

#define CapSense_DEVICE_ID_VALUE                            (CapSense_dsRam.deviceId)
#define CapSense_DEVICE_ID_OFFSET                           (2u)
#define CapSense_DEVICE_ID_SIZE                             (2u)
#define CapSense_DEVICE_ID_PARAM_ID                         (0x8B000002u)

#define CapSense_HW_CLOCK_VALUE                             (CapSense_dsRam.hwClock)
#define CapSense_HW_CLOCK_OFFSET                            (4u)
#define CapSense_HW_CLOCK_SIZE                              (2u)
#define CapSense_HW_CLOCK_PARAM_ID                          (0x86000004u)

#define CapSense_TUNER_CMD_VALUE                            (CapSense_dsRam.tunerCmd)
#define CapSense_TUNER_CMD_OFFSET                           (6u)
#define CapSense_TUNER_CMD_SIZE                             (2u)
#define CapSense_TUNER_CMD_PARAM_ID                         (0xA1000006u)

#define CapSense_SCAN_COUNTER_VALUE                         (CapSense_dsRam.scanCounter)
#define CapSense_SCAN_COUNTER_OFFSET                        (8u)
#define CapSense_SCAN_COUNTER_SIZE                          (2u)
#define CapSense_SCAN_COUNTER_PARAM_ID                      (0x85000008u)

#define CapSense_STATUS_VALUE                               (CapSense_dsRam.status)
#define CapSense_STATUS_OFFSET                              (12u)
#define CapSense_STATUS_SIZE                                (4u)
#define CapSense_STATUS_PARAM_ID                            (0xCB00000Cu)

#define CapSense_WDGT_ENABLE0_VALUE                         (CapSense_dsRam.wdgtEnable[0u])
#define CapSense_WDGT_ENABLE0_OFFSET                        (16u)
#define CapSense_WDGT_ENABLE0_SIZE                          (4u)
#define CapSense_WDGT_ENABLE0_PARAM_ID                      (0xE6000010u)

#define CapSense_WDGT_STATUS0_VALUE                         (CapSense_dsRam.wdgtStatus[0u])
#define CapSense_WDGT_STATUS0_OFFSET                        (20u)
#define CapSense_WDGT_STATUS0_SIZE                          (4u)
#define CapSense_WDGT_STATUS0_PARAM_ID                      (0xCC000014u)

#define CapSense_SNS_STATUS0_VALUE                          (CapSense_dsRam.snsStatus[0u])
#define CapSense_SNS_STATUS0_OFFSET                         (24u)
#define CapSense_SNS_STATUS0_SIZE                           (1u)
#define CapSense_SNS_STATUS0_PARAM_ID                       (0x48000018u)

#define CapSense_SNS_STATUS1_VALUE                          (CapSense_dsRam.snsStatus[1u])
#define CapSense_SNS_STATUS1_OFFSET                         (25u)
#define CapSense_SNS_STATUS1_SIZE                           (1u)
#define CapSense_SNS_STATUS1_PARAM_ID                       (0x4E000019u)

#define CapSense_SNS_STATUS2_VALUE                          (CapSense_dsRam.snsStatus[2u])
#define CapSense_SNS_STATUS2_OFFSET                         (26u)
#define CapSense_SNS_STATUS2_SIZE                           (1u)
#define CapSense_SNS_STATUS2_PARAM_ID                       (0x4400001Au)

#define CapSense_SNS_STATUS3_VALUE                          (CapSense_dsRam.snsStatus[3u])
#define CapSense_SNS_STATUS3_OFFSET                         (27u)
#define CapSense_SNS_STATUS3_SIZE                           (1u)
#define CapSense_SNS_STATUS3_PARAM_ID                       (0x4200001Bu)

#define CapSense_CSD0_CONFIG_VALUE                          (CapSense_dsRam.csd0Config)
#define CapSense_CSD0_CONFIG_OFFSET                         (28u)
#define CapSense_CSD0_CONFIG_SIZE                           (2u)
#define CapSense_CSD0_CONFIG_PARAM_ID                       (0xA780001Cu)

#define CapSense_MOD_CSD_CLK_VALUE                          (CapSense_dsRam.modCsdClk)
#define CapSense_MOD_CSD_CLK_OFFSET                         (30u)
#define CapSense_MOD_CSD_CLK_SIZE                           (1u)
#define CapSense_MOD_CSD_CLK_PARAM_ID                       (0x6380001Eu)

#define CapSense_MOD_CSX_CLK_VALUE                          (CapSense_dsRam.modCsxClk)
#define CapSense_MOD_CSX_CLK_OFFSET                         (31u)
#define CapSense_MOD_CSX_CLK_SIZE                           (1u)
#define CapSense_MOD_CSX_CLK_PARAM_ID                       (0x6580001Fu)

#define CapSense_BTN0_RESOLUTION_VALUE                      (CapSense_dsRam.wdgtList.btn0.resolution)
#define CapSense_BTN0_RESOLUTION_OFFSET                     (32u)
#define CapSense_BTN0_RESOLUTION_SIZE                       (2u)
#define CapSense_BTN0_RESOLUTION_PARAM_ID                   (0xAB800020u)

#define CapSense_BTN0_FINGER_TH_VALUE                       (CapSense_dsRam.wdgtList.btn0.fingerTh)
#define CapSense_BTN0_FINGER_TH_OFFSET                      (34u)
#define CapSense_BTN0_FINGER_TH_SIZE                        (2u)
#define CapSense_BTN0_FINGER_TH_PARAM_ID                    (0xA7800022u)

#define CapSense_BTN0_NOISE_TH_VALUE                        (CapSense_dsRam.wdgtList.btn0.noiseTh)
#define CapSense_BTN0_NOISE_TH_OFFSET                       (36u)
#define CapSense_BTN0_NOISE_TH_SIZE                         (1u)
#define CapSense_BTN0_NOISE_TH_PARAM_ID                     (0x62800024u)

#define CapSense_BTN0_NNOISE_TH_VALUE                       (CapSense_dsRam.wdgtList.btn0.nNoiseTh)
#define CapSense_BTN0_NNOISE_TH_OFFSET                      (37u)
#define CapSense_BTN0_NNOISE_TH_SIZE                        (1u)
#define CapSense_BTN0_NNOISE_TH_PARAM_ID                    (0x64800025u)

#define CapSense_BTN0_HYSTERESIS_VALUE                      (CapSense_dsRam.wdgtList.btn0.hysteresis)
#define CapSense_BTN0_HYSTERESIS_OFFSET                     (38u)
#define CapSense_BTN0_HYSTERESIS_SIZE                       (1u)
#define CapSense_BTN0_HYSTERESIS_PARAM_ID                   (0x6E800026u)

#define CapSense_BTN0_ON_DEBOUNCE_VALUE                     (CapSense_dsRam.wdgtList.btn0.onDebounce)
#define CapSense_BTN0_ON_DEBOUNCE_OFFSET                    (39u)
#define CapSense_BTN0_ON_DEBOUNCE_SIZE                      (1u)
#define CapSense_BTN0_ON_DEBOUNCE_PARAM_ID                  (0x68800027u)

#define CapSense_BTN0_LOW_BSLN_RST_VALUE                    (CapSense_dsRam.wdgtList.btn0.lowBslnRst)
#define CapSense_BTN0_LOW_BSLN_RST_OFFSET                   (40u)
#define CapSense_BTN0_LOW_BSLN_RST_SIZE                     (1u)
#define CapSense_BTN0_LOW_BSLN_RST_PARAM_ID                 (0x61800028u)

#define CapSense_BTN0_IDAC_MOD0_VALUE                       (CapSense_dsRam.wdgtList.btn0.idacMod[0u])
#define CapSense_BTN0_IDAC_MOD0_OFFSET                      (41u)
#define CapSense_BTN0_IDAC_MOD0_SIZE                        (1u)
#define CapSense_BTN0_IDAC_MOD0_PARAM_ID                    (0x41000029u)

#define CapSense_BTN0_SNS_CLK_VALUE                         (CapSense_dsRam.wdgtList.btn0.snsClk)
#define CapSense_BTN0_SNS_CLK_OFFSET                        (42u)
#define CapSense_BTN0_SNS_CLK_SIZE                          (2u)
#define CapSense_BTN0_SNS_CLK_PARAM_ID                      (0xA580002Au)

#define CapSense_BTN0_SNS_CLK_SOURCE_VALUE                  (CapSense_dsRam.wdgtList.btn0.snsClkSource)
#define CapSense_BTN0_SNS_CLK_SOURCE_OFFSET                 (44u)
#define CapSense_BTN0_SNS_CLK_SOURCE_SIZE                   (1u)
#define CapSense_BTN0_SNS_CLK_SOURCE_PARAM_ID               (0x4B80002Cu)

#define CapSense_BTN0_FINGER_CAP_VALUE                      (CapSense_dsRam.wdgtList.btn0.fingerCap)
#define CapSense_BTN0_FINGER_CAP_OFFSET                     (46u)
#define CapSense_BTN0_FINGER_CAP_SIZE                       (2u)
#define CapSense_BTN0_FINGER_CAP_PARAM_ID                   (0xA900002Eu)

#define CapSense_BTN0_SIGPFC_VALUE                          (CapSense_dsRam.wdgtList.btn0.sigPFC)
#define CapSense_BTN0_SIGPFC_OFFSET                         (48u)
#define CapSense_BTN0_SIGPFC_SIZE                           (2u)
#define CapSense_BTN0_SIGPFC_PARAM_ID                       (0xA3000030u)

#define CapSense_BTN1_RESOLUTION_VALUE                      (CapSense_dsRam.wdgtList.btn1.resolution)
#define CapSense_BTN1_RESOLUTION_OFFSET                     (50u)
#define CapSense_BTN1_RESOLUTION_SIZE                       (2u)
#define CapSense_BTN1_RESOLUTION_PARAM_ID                   (0xA1810032u)

#define CapSense_BTN1_FINGER_TH_VALUE                       (CapSense_dsRam.wdgtList.btn1.fingerTh)
#define CapSense_BTN1_FINGER_TH_OFFSET                      (52u)
#define CapSense_BTN1_FINGER_TH_SIZE                        (2u)
#define CapSense_BTN1_FINGER_TH_PARAM_ID                    (0xAC810034u)

#define CapSense_BTN1_NOISE_TH_VALUE                        (CapSense_dsRam.wdgtList.btn1.noiseTh)
#define CapSense_BTN1_NOISE_TH_OFFSET                       (54u)
#define CapSense_BTN1_NOISE_TH_SIZE                         (1u)
#define CapSense_BTN1_NOISE_TH_PARAM_ID                     (0x68810036u)

#define CapSense_BTN1_NNOISE_TH_VALUE                       (CapSense_dsRam.wdgtList.btn1.nNoiseTh)
#define CapSense_BTN1_NNOISE_TH_OFFSET                      (55u)
#define CapSense_BTN1_NNOISE_TH_SIZE                        (1u)
#define CapSense_BTN1_NNOISE_TH_PARAM_ID                    (0x6E810037u)

#define CapSense_BTN1_HYSTERESIS_VALUE                      (CapSense_dsRam.wdgtList.btn1.hysteresis)
#define CapSense_BTN1_HYSTERESIS_OFFSET                     (56u)
#define CapSense_BTN1_HYSTERESIS_SIZE                       (1u)
#define CapSense_BTN1_HYSTERESIS_PARAM_ID                   (0x67810038u)

#define CapSense_BTN1_ON_DEBOUNCE_VALUE                     (CapSense_dsRam.wdgtList.btn1.onDebounce)
#define CapSense_BTN1_ON_DEBOUNCE_OFFSET                    (57u)
#define CapSense_BTN1_ON_DEBOUNCE_SIZE                      (1u)
#define CapSense_BTN1_ON_DEBOUNCE_PARAM_ID                  (0x61810039u)

#define CapSense_BTN1_LOW_BSLN_RST_VALUE                    (CapSense_dsRam.wdgtList.btn1.lowBslnRst)
#define CapSense_BTN1_LOW_BSLN_RST_OFFSET                   (58u)
#define CapSense_BTN1_LOW_BSLN_RST_SIZE                     (1u)
#define CapSense_BTN1_LOW_BSLN_RST_PARAM_ID                 (0x6B81003Au)

#define CapSense_BTN1_IDAC_MOD0_VALUE                       (CapSense_dsRam.wdgtList.btn1.idacMod[0u])
#define CapSense_BTN1_IDAC_MOD0_OFFSET                      (59u)
#define CapSense_BTN1_IDAC_MOD0_SIZE                        (1u)
#define CapSense_BTN1_IDAC_MOD0_PARAM_ID                    (0x4B01003Bu)

#define CapSense_BTN1_SNS_CLK_VALUE                         (CapSense_dsRam.wdgtList.btn1.snsClk)
#define CapSense_BTN1_SNS_CLK_OFFSET                        (60u)
#define CapSense_BTN1_SNS_CLK_SIZE                          (2u)
#define CapSense_BTN1_SNS_CLK_PARAM_ID                      (0xAE81003Cu)

#define CapSense_BTN1_SNS_CLK_SOURCE_VALUE                  (CapSense_dsRam.wdgtList.btn1.snsClkSource)
#define CapSense_BTN1_SNS_CLK_SOURCE_OFFSET                 (62u)
#define CapSense_BTN1_SNS_CLK_SOURCE_SIZE                   (1u)
#define CapSense_BTN1_SNS_CLK_SOURCE_PARAM_ID               (0x4181003Eu)

#define CapSense_BTN1_FINGER_CAP_VALUE                      (CapSense_dsRam.wdgtList.btn1.fingerCap)
#define CapSense_BTN1_FINGER_CAP_OFFSET                     (64u)
#define CapSense_BTN1_FINGER_CAP_SIZE                       (2u)
#define CapSense_BTN1_FINGER_CAP_PARAM_ID                   (0xA2010040u)

#define CapSense_BTN1_SIGPFC_VALUE                          (CapSense_dsRam.wdgtList.btn1.sigPFC)
#define CapSense_BTN1_SIGPFC_OFFSET                         (66u)
#define CapSense_BTN1_SIGPFC_SIZE                           (2u)
#define CapSense_BTN1_SIGPFC_PARAM_ID                       (0xAE010042u)

#define CapSense_BTN2_RESOLUTION_VALUE                      (CapSense_dsRam.wdgtList.btn2.resolution)
#define CapSense_BTN2_RESOLUTION_OFFSET                     (68u)
#define CapSense_BTN2_RESOLUTION_SIZE                       (2u)
#define CapSense_BTN2_RESOLUTION_PARAM_ID                   (0xAB820044u)

#define CapSense_BTN2_FINGER_TH_VALUE                       (CapSense_dsRam.wdgtList.btn2.fingerTh)
#define CapSense_BTN2_FINGER_TH_OFFSET                      (70u)
#define CapSense_BTN2_FINGER_TH_SIZE                        (2u)
#define CapSense_BTN2_FINGER_TH_PARAM_ID                    (0xA7820046u)

#define CapSense_BTN2_NOISE_TH_VALUE                        (CapSense_dsRam.wdgtList.btn2.noiseTh)
#define CapSense_BTN2_NOISE_TH_OFFSET                       (72u)
#define CapSense_BTN2_NOISE_TH_SIZE                         (1u)
#define CapSense_BTN2_NOISE_TH_PARAM_ID                     (0x60820048u)

#define CapSense_BTN2_NNOISE_TH_VALUE                       (CapSense_dsRam.wdgtList.btn2.nNoiseTh)
#define CapSense_BTN2_NNOISE_TH_OFFSET                      (73u)
#define CapSense_BTN2_NNOISE_TH_SIZE                        (1u)
#define CapSense_BTN2_NNOISE_TH_PARAM_ID                    (0x66820049u)

#define CapSense_BTN2_HYSTERESIS_VALUE                      (CapSense_dsRam.wdgtList.btn2.hysteresis)
#define CapSense_BTN2_HYSTERESIS_OFFSET                     (74u)
#define CapSense_BTN2_HYSTERESIS_SIZE                       (1u)
#define CapSense_BTN2_HYSTERESIS_PARAM_ID                   (0x6C82004Au)

#define CapSense_BTN2_ON_DEBOUNCE_VALUE                     (CapSense_dsRam.wdgtList.btn2.onDebounce)
#define CapSense_BTN2_ON_DEBOUNCE_OFFSET                    (75u)
#define CapSense_BTN2_ON_DEBOUNCE_SIZE                      (1u)
#define CapSense_BTN2_ON_DEBOUNCE_PARAM_ID                  (0x6A82004Bu)

#define CapSense_BTN2_LOW_BSLN_RST_VALUE                    (CapSense_dsRam.wdgtList.btn2.lowBslnRst)
#define CapSense_BTN2_LOW_BSLN_RST_OFFSET                   (76u)
#define CapSense_BTN2_LOW_BSLN_RST_SIZE                     (1u)
#define CapSense_BTN2_LOW_BSLN_RST_PARAM_ID                 (0x6182004Cu)

#define CapSense_BTN2_IDAC_MOD0_VALUE                       (CapSense_dsRam.wdgtList.btn2.idacMod[0u])
#define CapSense_BTN2_IDAC_MOD0_OFFSET                      (77u)
#define CapSense_BTN2_IDAC_MOD0_SIZE                        (1u)
#define CapSense_BTN2_IDAC_MOD0_PARAM_ID                    (0x4102004Du)

#define CapSense_BTN2_SNS_CLK_VALUE                         (CapSense_dsRam.wdgtList.btn2.snsClk)
#define CapSense_BTN2_SNS_CLK_OFFSET                        (78u)
#define CapSense_BTN2_SNS_CLK_SIZE                          (2u)
#define CapSense_BTN2_SNS_CLK_PARAM_ID                      (0xA582004Eu)

#define CapSense_BTN2_SNS_CLK_SOURCE_VALUE                  (CapSense_dsRam.wdgtList.btn2.snsClkSource)
#define CapSense_BTN2_SNS_CLK_SOURCE_OFFSET                 (80u)
#define CapSense_BTN2_SNS_CLK_SOURCE_SIZE                   (1u)
#define CapSense_BTN2_SNS_CLK_SOURCE_PARAM_ID               (0x4C820050u)

#define CapSense_BTN2_FINGER_CAP_VALUE                      (CapSense_dsRam.wdgtList.btn2.fingerCap)
#define CapSense_BTN2_FINGER_CAP_OFFSET                     (82u)
#define CapSense_BTN2_FINGER_CAP_SIZE                       (2u)
#define CapSense_BTN2_FINGER_CAP_PARAM_ID                   (0xAE020052u)

#define CapSense_BTN2_SIGPFC_VALUE                          (CapSense_dsRam.wdgtList.btn2.sigPFC)
#define CapSense_BTN2_SIGPFC_OFFSET                         (84u)
#define CapSense_BTN2_SIGPFC_SIZE                           (2u)
#define CapSense_BTN2_SIGPFC_PARAM_ID                       (0xA3020054u)

#define CapSense_SLD_RESOLUTION_VALUE                       (CapSense_dsRam.wdgtList.sld.resolution)
#define CapSense_SLD_RESOLUTION_OFFSET                      (86u)
#define CapSense_SLD_RESOLUTION_SIZE                        (2u)
#define CapSense_SLD_RESOLUTION_PARAM_ID                    (0x8A830056u)

#define CapSense_SLD_FINGER_TH_VALUE                        (CapSense_dsRam.wdgtList.sld.fingerTh)
#define CapSense_SLD_FINGER_TH_OFFSET                       (88u)
#define CapSense_SLD_FINGER_TH_SIZE                         (2u)
#define CapSense_SLD_FINGER_TH_PARAM_ID                     (0x85830058u)

#define CapSense_SLD_NOISE_TH_VALUE                         (CapSense_dsRam.wdgtList.sld.noiseTh)
#define CapSense_SLD_NOISE_TH_OFFSET                        (90u)
#define CapSense_SLD_NOISE_TH_SIZE                          (1u)
#define CapSense_SLD_NOISE_TH_PARAM_ID                      (0x4183005Au)

#define CapSense_SLD_NNOISE_TH_VALUE                        (CapSense_dsRam.wdgtList.sld.nNoiseTh)
#define CapSense_SLD_NNOISE_TH_OFFSET                       (91u)
#define CapSense_SLD_NNOISE_TH_SIZE                         (1u)
#define CapSense_SLD_NNOISE_TH_PARAM_ID                     (0x4783005Bu)

#define CapSense_SLD_HYSTERESIS_VALUE                       (CapSense_dsRam.wdgtList.sld.hysteresis)
#define CapSense_SLD_HYSTERESIS_OFFSET                      (92u)
#define CapSense_SLD_HYSTERESIS_SIZE                        (1u)
#define CapSense_SLD_HYSTERESIS_PARAM_ID                    (0x4C83005Cu)

#define CapSense_SLD_ON_DEBOUNCE_VALUE                      (CapSense_dsRam.wdgtList.sld.onDebounce)
#define CapSense_SLD_ON_DEBOUNCE_OFFSET                     (93u)
#define CapSense_SLD_ON_DEBOUNCE_SIZE                       (1u)
#define CapSense_SLD_ON_DEBOUNCE_PARAM_ID                   (0x4A83005Du)

#define CapSense_SLD_LOW_BSLN_RST_VALUE                     (CapSense_dsRam.wdgtList.sld.lowBslnRst)
#define CapSense_SLD_LOW_BSLN_RST_OFFSET                    (94u)
#define CapSense_SLD_LOW_BSLN_RST_SIZE                      (1u)
#define CapSense_SLD_LOW_BSLN_RST_PARAM_ID                  (0x4083005Eu)

#define CapSense_SLD_IDAC_MOD0_VALUE                        (CapSense_dsRam.wdgtList.sld.idacMod[0u])
#define CapSense_SLD_IDAC_MOD0_OFFSET                       (95u)
#define CapSense_SLD_IDAC_MOD0_SIZE                         (1u)
#define CapSense_SLD_IDAC_MOD0_PARAM_ID                     (0x4B03005Fu)

#define CapSense_SLD_SNS_CLK_VALUE                          (CapSense_dsRam.wdgtList.sld.snsClk)
#define CapSense_SLD_SNS_CLK_OFFSET                         (96u)
#define CapSense_SLD_SNS_CLK_SIZE                           (2u)
#define CapSense_SLD_SNS_CLK_PARAM_ID                       (0x88830060u)

#define CapSense_SLD_SNS_CLK_SOURCE_VALUE                   (CapSense_dsRam.wdgtList.sld.snsClkSource)
#define CapSense_SLD_SNS_CLK_SOURCE_OFFSET                  (98u)
#define CapSense_SLD_SNS_CLK_SOURCE_SIZE                    (1u)
#define CapSense_SLD_SNS_CLK_SOURCE_PARAM_ID                (0x4C830062u)

#define CapSense_SLD_FINGER_CAP_VALUE                       (CapSense_dsRam.wdgtList.sld.fingerCap)
#define CapSense_SLD_FINGER_CAP_OFFSET                      (100u)
#define CapSense_SLD_FINGER_CAP_SIZE                        (2u)
#define CapSense_SLD_FINGER_CAP_PARAM_ID                    (0xAF030064u)

#define CapSense_SLD_SIGPFC_VALUE                           (CapSense_dsRam.wdgtList.sld.sigPFC)
#define CapSense_SLD_SIGPFC_OFFSET                          (102u)
#define CapSense_SLD_SIGPFC_SIZE                            (2u)
#define CapSense_SLD_SIGPFC_PARAM_ID                        (0xA3030066u)

#define CapSense_SLD_POSITION0_VALUE                        (CapSense_dsRam.wdgtList.sld.position[0u])
#define CapSense_SLD_POSITION0_OFFSET                       (104u)
#define CapSense_SLD_POSITION0_SIZE                         (2u)
#define CapSense_SLD_POSITION0_PARAM_ID                     (0x87030068u)

#define CapSense_BTN0_RX0_RAW0_VALUE                        (CapSense_dsRam.snsList.btn0[0u].raw[0u])
#define CapSense_BTN0_RX0_RAW0_OFFSET                       (106u)
#define CapSense_BTN0_RX0_RAW0_SIZE                         (2u)
#define CapSense_BTN0_RX0_RAW0_PARAM_ID                     (0x8E00006Au)

#define CapSense_BTN0_RX0_BSLN0_VALUE                       (CapSense_dsRam.snsList.btn0[0u].bsln[0u])
#define CapSense_BTN0_RX0_BSLN0_OFFSET                      (108u)
#define CapSense_BTN0_RX0_BSLN0_SIZE                        (2u)
#define CapSense_BTN0_RX0_BSLN0_PARAM_ID                    (0x8300006Cu)

#define CapSense_BTN0_RX0_BSLN_EXT0_VALUE                   (CapSense_dsRam.snsList.btn0[0u].bslnExt[0u])
#define CapSense_BTN0_RX0_BSLN_EXT0_OFFSET                  (110u)
#define CapSense_BTN0_RX0_BSLN_EXT0_SIZE                    (1u)
#define CapSense_BTN0_RX0_BSLN_EXT0_PARAM_ID                (0x4700006Eu)

#define CapSense_BTN0_RX0_DIFF_VALUE                        (CapSense_dsRam.snsList.btn0[0u].diff)
#define CapSense_BTN0_RX0_DIFF_OFFSET                       (112u)
#define CapSense_BTN0_RX0_DIFF_SIZE                         (2u)
#define CapSense_BTN0_RX0_DIFF_PARAM_ID                     (0x85000070u)

#define CapSense_BTN0_RX0_NEG_BSLN_RST_CNT0_VALUE           (CapSense_dsRam.snsList.btn0[0u].negBslnRstCnt[0u])
#define CapSense_BTN0_RX0_NEG_BSLN_RST_CNT0_OFFSET          (114u)
#define CapSense_BTN0_RX0_NEG_BSLN_RST_CNT0_SIZE            (1u)
#define CapSense_BTN0_RX0_NEG_BSLN_RST_CNT0_PARAM_ID        (0x41000072u)

#define CapSense_BTN0_RX0_IDAC_COMP0_VALUE                  (CapSense_dsRam.snsList.btn0[0u].idacComp[0u])
#define CapSense_BTN0_RX0_IDAC_COMP0_OFFSET                 (115u)
#define CapSense_BTN0_RX0_IDAC_COMP0_SIZE                   (1u)
#define CapSense_BTN0_RX0_IDAC_COMP0_PARAM_ID               (0x47000073u)

#define CapSense_BTN1_RX0_RAW0_VALUE                        (CapSense_dsRam.snsList.btn1[0u].raw[0u])
#define CapSense_BTN1_RX0_RAW0_OFFSET                       (116u)
#define CapSense_BTN1_RX0_RAW0_SIZE                         (2u)
#define CapSense_BTN1_RX0_RAW0_PARAM_ID                     (0x84000074u)

#define CapSense_BTN1_RX0_BSLN0_VALUE                       (CapSense_dsRam.snsList.btn1[0u].bsln[0u])
#define CapSense_BTN1_RX0_BSLN0_OFFSET                      (118u)
#define CapSense_BTN1_RX0_BSLN0_SIZE                        (2u)
#define CapSense_BTN1_RX0_BSLN0_PARAM_ID                    (0x88000076u)

#define CapSense_BTN1_RX0_BSLN_EXT0_VALUE                   (CapSense_dsRam.snsList.btn1[0u].bslnExt[0u])
#define CapSense_BTN1_RX0_BSLN_EXT0_OFFSET                  (120u)
#define CapSense_BTN1_RX0_BSLN_EXT0_SIZE                    (1u)
#define CapSense_BTN1_RX0_BSLN_EXT0_PARAM_ID                (0x4F000078u)

#define CapSense_BTN1_RX0_DIFF_VALUE                        (CapSense_dsRam.snsList.btn1[0u].diff)
#define CapSense_BTN1_RX0_DIFF_OFFSET                       (122u)
#define CapSense_BTN1_RX0_DIFF_SIZE                         (2u)
#define CapSense_BTN1_RX0_DIFF_PARAM_ID                     (0x8B00007Au)

#define CapSense_BTN1_RX0_NEG_BSLN_RST_CNT0_VALUE           (CapSense_dsRam.snsList.btn1[0u].negBslnRstCnt[0u])
#define CapSense_BTN1_RX0_NEG_BSLN_RST_CNT0_OFFSET          (124u)
#define CapSense_BTN1_RX0_NEG_BSLN_RST_CNT0_SIZE            (1u)
#define CapSense_BTN1_RX0_NEG_BSLN_RST_CNT0_PARAM_ID        (0x4E00007Cu)

#define CapSense_BTN1_RX0_IDAC_COMP0_VALUE                  (CapSense_dsRam.snsList.btn1[0u].idacComp[0u])
#define CapSense_BTN1_RX0_IDAC_COMP0_OFFSET                 (125u)
#define CapSense_BTN1_RX0_IDAC_COMP0_SIZE                   (1u)
#define CapSense_BTN1_RX0_IDAC_COMP0_PARAM_ID               (0x4800007Du)

#define CapSense_BTN2_RX0_RAW0_VALUE                        (CapSense_dsRam.snsList.btn2[0u].raw[0u])
#define CapSense_BTN2_RX0_RAW0_OFFSET                       (126u)
#define CapSense_BTN2_RX0_RAW0_SIZE                         (2u)
#define CapSense_BTN2_RX0_RAW0_PARAM_ID                     (0x8A00007Eu)

#define CapSense_BTN2_RX0_BSLN0_VALUE                       (CapSense_dsRam.snsList.btn2[0u].bsln[0u])
#define CapSense_BTN2_RX0_BSLN0_OFFSET                      (128u)
#define CapSense_BTN2_RX0_BSLN0_SIZE                        (2u)
#define CapSense_BTN2_RX0_BSLN0_PARAM_ID                    (0x84000080u)

#define CapSense_BTN2_RX0_BSLN_EXT0_VALUE                   (CapSense_dsRam.snsList.btn2[0u].bslnExt[0u])
#define CapSense_BTN2_RX0_BSLN_EXT0_OFFSET                  (130u)
#define CapSense_BTN2_RX0_BSLN_EXT0_SIZE                    (1u)
#define CapSense_BTN2_RX0_BSLN_EXT0_PARAM_ID                (0x40000082u)

#define CapSense_BTN2_RX0_DIFF_VALUE                        (CapSense_dsRam.snsList.btn2[0u].diff)
#define CapSense_BTN2_RX0_DIFF_OFFSET                       (132u)
#define CapSense_BTN2_RX0_DIFF_SIZE                         (2u)
#define CapSense_BTN2_RX0_DIFF_PARAM_ID                     (0x85000084u)

#define CapSense_BTN2_RX0_NEG_BSLN_RST_CNT0_VALUE           (CapSense_dsRam.snsList.btn2[0u].negBslnRstCnt[0u])
#define CapSense_BTN2_RX0_NEG_BSLN_RST_CNT0_OFFSET          (134u)
#define CapSense_BTN2_RX0_NEG_BSLN_RST_CNT0_SIZE            (1u)
#define CapSense_BTN2_RX0_NEG_BSLN_RST_CNT0_PARAM_ID        (0x41000086u)

#define CapSense_BTN2_RX0_IDAC_COMP0_VALUE                  (CapSense_dsRam.snsList.btn2[0u].idacComp[0u])
#define CapSense_BTN2_RX0_IDAC_COMP0_OFFSET                 (135u)
#define CapSense_BTN2_RX0_IDAC_COMP0_SIZE                   (1u)
#define CapSense_BTN2_RX0_IDAC_COMP0_PARAM_ID               (0x47000087u)

#define CapSense_SLD_SNS0_RAW0_VALUE                        (CapSense_dsRam.snsList.sld[0u].raw[0u])
#define CapSense_SLD_SNS0_RAW0_OFFSET                       (136u)
#define CapSense_SLD_SNS0_RAW0_SIZE                         (2u)
#define CapSense_SLD_SNS0_RAW0_PARAM_ID                     (0x86000088u)

#define CapSense_SLD_SNS0_BSLN0_VALUE                       (CapSense_dsRam.snsList.sld[0u].bsln[0u])
#define CapSense_SLD_SNS0_BSLN0_OFFSET                      (138u)
#define CapSense_SLD_SNS0_BSLN0_SIZE                        (2u)
#define CapSense_SLD_SNS0_BSLN0_PARAM_ID                    (0x8A00008Au)

#define CapSense_SLD_SNS0_BSLN_EXT0_VALUE                   (CapSense_dsRam.snsList.sld[0u].bslnExt[0u])
#define CapSense_SLD_SNS0_BSLN_EXT0_OFFSET                  (140u)
#define CapSense_SLD_SNS0_BSLN_EXT0_SIZE                    (1u)
#define CapSense_SLD_SNS0_BSLN_EXT0_PARAM_ID                (0x4F00008Cu)

#define CapSense_SLD_SNS0_DIFF_VALUE                        (CapSense_dsRam.snsList.sld[0u].diff)
#define CapSense_SLD_SNS0_DIFF_OFFSET                       (142u)
#define CapSense_SLD_SNS0_DIFF_SIZE                         (2u)
#define CapSense_SLD_SNS0_DIFF_PARAM_ID                     (0x8B00008Eu)

#define CapSense_SLD_SNS0_NEG_BSLN_RST_CNT0_VALUE           (CapSense_dsRam.snsList.sld[0u].negBslnRstCnt[0u])
#define CapSense_SLD_SNS0_NEG_BSLN_RST_CNT0_OFFSET          (144u)
#define CapSense_SLD_SNS0_NEG_BSLN_RST_CNT0_SIZE            (1u)
#define CapSense_SLD_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID        (0x49000090u)

#define CapSense_SLD_SNS0_IDAC_COMP0_VALUE                  (CapSense_dsRam.snsList.sld[0u].idacComp[0u])
#define CapSense_SLD_SNS0_IDAC_COMP0_OFFSET                 (145u)
#define CapSense_SLD_SNS0_IDAC_COMP0_SIZE                   (1u)
#define CapSense_SLD_SNS0_IDAC_COMP0_PARAM_ID               (0x4F000091u)

#define CapSense_SLD_SNS1_RAW0_VALUE                        (CapSense_dsRam.snsList.sld[1u].raw[0u])
#define CapSense_SLD_SNS1_RAW0_OFFSET                       (146u)
#define CapSense_SLD_SNS1_RAW0_SIZE                         (2u)
#define CapSense_SLD_SNS1_RAW0_PARAM_ID                     (0x8D000092u)

#define CapSense_SLD_SNS1_BSLN0_VALUE                       (CapSense_dsRam.snsList.sld[1u].bsln[0u])
#define CapSense_SLD_SNS1_BSLN0_OFFSET                      (148u)
#define CapSense_SLD_SNS1_BSLN0_SIZE                        (2u)
#define CapSense_SLD_SNS1_BSLN0_PARAM_ID                    (0x80000094u)

#define CapSense_SLD_SNS1_BSLN_EXT0_VALUE                   (CapSense_dsRam.snsList.sld[1u].bslnExt[0u])
#define CapSense_SLD_SNS1_BSLN_EXT0_OFFSET                  (150u)
#define CapSense_SLD_SNS1_BSLN_EXT0_SIZE                    (1u)
#define CapSense_SLD_SNS1_BSLN_EXT0_PARAM_ID                (0x44000096u)

#define CapSense_SLD_SNS1_DIFF_VALUE                        (CapSense_dsRam.snsList.sld[1u].diff)
#define CapSense_SLD_SNS1_DIFF_OFFSET                       (152u)
#define CapSense_SLD_SNS1_DIFF_SIZE                         (2u)
#define CapSense_SLD_SNS1_DIFF_PARAM_ID                     (0x83000098u)

#define CapSense_SLD_SNS1_NEG_BSLN_RST_CNT0_VALUE           (CapSense_dsRam.snsList.sld[1u].negBslnRstCnt[0u])
#define CapSense_SLD_SNS1_NEG_BSLN_RST_CNT0_OFFSET          (154u)
#define CapSense_SLD_SNS1_NEG_BSLN_RST_CNT0_SIZE            (1u)
#define CapSense_SLD_SNS1_NEG_BSLN_RST_CNT0_PARAM_ID        (0x4700009Au)

#define CapSense_SLD_SNS1_IDAC_COMP0_VALUE                  (CapSense_dsRam.snsList.sld[1u].idacComp[0u])
#define CapSense_SLD_SNS1_IDAC_COMP0_OFFSET                 (155u)
#define CapSense_SLD_SNS1_IDAC_COMP0_SIZE                   (1u)
#define CapSense_SLD_SNS1_IDAC_COMP0_PARAM_ID               (0x4100009Bu)

#define CapSense_SLD_SNS2_RAW0_VALUE                        (CapSense_dsRam.snsList.sld[2u].raw[0u])
#define CapSense_SLD_SNS2_RAW0_OFFSET                       (156u)
#define CapSense_SLD_SNS2_RAW0_SIZE                         (2u)
#define CapSense_SLD_SNS2_RAW0_PARAM_ID                     (0x8200009Cu)

#define CapSense_SLD_SNS2_BSLN0_VALUE                       (CapSense_dsRam.snsList.sld[2u].bsln[0u])
#define CapSense_SLD_SNS2_BSLN0_OFFSET                      (158u)
#define CapSense_SLD_SNS2_BSLN0_SIZE                        (2u)
#define CapSense_SLD_SNS2_BSLN0_PARAM_ID                    (0x8E00009Eu)

#define CapSense_SLD_SNS2_BSLN_EXT0_VALUE                   (CapSense_dsRam.snsList.sld[2u].bslnExt[0u])
#define CapSense_SLD_SNS2_BSLN_EXT0_OFFSET                  (160u)
#define CapSense_SLD_SNS2_BSLN_EXT0_SIZE                    (1u)
#define CapSense_SLD_SNS2_BSLN_EXT0_PARAM_ID                (0x460000A0u)

#define CapSense_SLD_SNS2_DIFF_VALUE                        (CapSense_dsRam.snsList.sld[2u].diff)
#define CapSense_SLD_SNS2_DIFF_OFFSET                       (162u)
#define CapSense_SLD_SNS2_DIFF_SIZE                         (2u)
#define CapSense_SLD_SNS2_DIFF_PARAM_ID                     (0x820000A2u)

#define CapSense_SLD_SNS2_NEG_BSLN_RST_CNT0_VALUE           (CapSense_dsRam.snsList.sld[2u].negBslnRstCnt[0u])
#define CapSense_SLD_SNS2_NEG_BSLN_RST_CNT0_OFFSET          (164u)
#define CapSense_SLD_SNS2_NEG_BSLN_RST_CNT0_SIZE            (1u)
#define CapSense_SLD_SNS2_NEG_BSLN_RST_CNT0_PARAM_ID        (0x470000A4u)

#define CapSense_SLD_SNS2_IDAC_COMP0_VALUE                  (CapSense_dsRam.snsList.sld[2u].idacComp[0u])
#define CapSense_SLD_SNS2_IDAC_COMP0_OFFSET                 (165u)
#define CapSense_SLD_SNS2_IDAC_COMP0_SIZE                   (1u)
#define CapSense_SLD_SNS2_IDAC_COMP0_PARAM_ID               (0x410000A5u)

#define CapSense_SLD_SNS3_RAW0_VALUE                        (CapSense_dsRam.snsList.sld[3u].raw[0u])
#define CapSense_SLD_SNS3_RAW0_OFFSET                       (166u)
#define CapSense_SLD_SNS3_RAW0_SIZE                         (2u)
#define CapSense_SLD_SNS3_RAW0_PARAM_ID                     (0x830000A6u)

#define CapSense_SLD_SNS3_BSLN0_VALUE                       (CapSense_dsRam.snsList.sld[3u].bsln[0u])
#define CapSense_SLD_SNS3_BSLN0_OFFSET                      (168u)
#define CapSense_SLD_SNS3_BSLN0_SIZE                        (2u)
#define CapSense_SLD_SNS3_BSLN0_PARAM_ID                    (0x8C0000A8u)

#define CapSense_SLD_SNS3_BSLN_EXT0_VALUE                   (CapSense_dsRam.snsList.sld[3u].bslnExt[0u])
#define CapSense_SLD_SNS3_BSLN_EXT0_OFFSET                  (170u)
#define CapSense_SLD_SNS3_BSLN_EXT0_SIZE                    (1u)
#define CapSense_SLD_SNS3_BSLN_EXT0_PARAM_ID                (0x480000AAu)

#define CapSense_SLD_SNS3_DIFF_VALUE                        (CapSense_dsRam.snsList.sld[3u].diff)
#define CapSense_SLD_SNS3_DIFF_OFFSET                       (172u)
#define CapSense_SLD_SNS3_DIFF_SIZE                         (2u)
#define CapSense_SLD_SNS3_DIFF_PARAM_ID                     (0x8D0000ACu)

#define CapSense_SLD_SNS3_NEG_BSLN_RST_CNT0_VALUE           (CapSense_dsRam.snsList.sld[3u].negBslnRstCnt[0u])
#define CapSense_SLD_SNS3_NEG_BSLN_RST_CNT0_OFFSET          (174u)
#define CapSense_SLD_SNS3_NEG_BSLN_RST_CNT0_SIZE            (1u)
#define CapSense_SLD_SNS3_NEG_BSLN_RST_CNT0_PARAM_ID        (0x490000AEu)

#define CapSense_SLD_SNS3_IDAC_COMP0_VALUE                  (CapSense_dsRam.snsList.sld[3u].idacComp[0u])
#define CapSense_SLD_SNS3_IDAC_COMP0_OFFSET                 (175u)
#define CapSense_SLD_SNS3_IDAC_COMP0_SIZE                   (1u)
#define CapSense_SLD_SNS3_IDAC_COMP0_PARAM_ID               (0x4F0000AFu)

#define CapSense_SLD_SNS4_RAW0_VALUE                        (CapSense_dsRam.snsList.sld[4u].raw[0u])
#define CapSense_SLD_SNS4_RAW0_OFFSET                       (176u)
#define CapSense_SLD_SNS4_RAW0_SIZE                         (2u)
#define CapSense_SLD_SNS4_RAW0_PARAM_ID                     (0x8B0000B0u)

#define CapSense_SLD_SNS4_BSLN0_VALUE                       (CapSense_dsRam.snsList.sld[4u].bsln[0u])
#define CapSense_SLD_SNS4_BSLN0_OFFSET                      (178u)
#define CapSense_SLD_SNS4_BSLN0_SIZE                        (2u)
#define CapSense_SLD_SNS4_BSLN0_PARAM_ID                    (0x870000B2u)

#define CapSense_SLD_SNS4_BSLN_EXT0_VALUE                   (CapSense_dsRam.snsList.sld[4u].bslnExt[0u])
#define CapSense_SLD_SNS4_BSLN_EXT0_OFFSET                  (180u)
#define CapSense_SLD_SNS4_BSLN_EXT0_SIZE                    (1u)
#define CapSense_SLD_SNS4_BSLN_EXT0_PARAM_ID                (0x420000B4u)

#define CapSense_SLD_SNS4_DIFF_VALUE                        (CapSense_dsRam.snsList.sld[4u].diff)
#define CapSense_SLD_SNS4_DIFF_OFFSET                       (182u)
#define CapSense_SLD_SNS4_DIFF_SIZE                         (2u)
#define CapSense_SLD_SNS4_DIFF_PARAM_ID                     (0x860000B6u)

#define CapSense_SLD_SNS4_NEG_BSLN_RST_CNT0_VALUE           (CapSense_dsRam.snsList.sld[4u].negBslnRstCnt[0u])
#define CapSense_SLD_SNS4_NEG_BSLN_RST_CNT0_OFFSET          (184u)
#define CapSense_SLD_SNS4_NEG_BSLN_RST_CNT0_SIZE            (1u)
#define CapSense_SLD_SNS4_NEG_BSLN_RST_CNT0_PARAM_ID        (0x410000B8u)

#define CapSense_SLD_SNS4_IDAC_COMP0_VALUE                  (CapSense_dsRam.snsList.sld[4u].idacComp[0u])
#define CapSense_SLD_SNS4_IDAC_COMP0_OFFSET                 (185u)
#define CapSense_SLD_SNS4_IDAC_COMP0_SIZE                   (1u)
#define CapSense_SLD_SNS4_IDAC_COMP0_PARAM_ID               (0x470000B9u)

#define CapSense_SNR_TEST_WIDGET_ID_VALUE                   (CapSense_dsRam.snrTestWidgetId)
#define CapSense_SNR_TEST_WIDGET_ID_OFFSET                  (186u)
#define CapSense_SNR_TEST_WIDGET_ID_SIZE                    (1u)
#define CapSense_SNR_TEST_WIDGET_ID_PARAM_ID                (0x660000BAu)

#define CapSense_SNR_TEST_SENSOR_ID_VALUE                   (CapSense_dsRam.snrTestSensorId)
#define CapSense_SNR_TEST_SENSOR_ID_OFFSET                  (187u)
#define CapSense_SNR_TEST_SENSOR_ID_SIZE                    (1u)
#define CapSense_SNR_TEST_SENSOR_ID_PARAM_ID                (0x600000BBu)

#define CapSense_SNR_TEST_SCAN_COUNTER_VALUE                (CapSense_dsRam.snrTestScanCounter)
#define CapSense_SNR_TEST_SCAN_COUNTER_OFFSET               (188u)
#define CapSense_SNR_TEST_SCAN_COUNTER_SIZE                 (2u)
#define CapSense_SNR_TEST_SCAN_COUNTER_PARAM_ID             (0x880000BCu)

#define CapSense_SNR_TEST_RAW_COUNT0_VALUE                  (CapSense_dsRam.snrTestRawCount[0u])
#define CapSense_SNR_TEST_RAW_COUNT0_OFFSET                 (190u)
#define CapSense_SNR_TEST_RAW_COUNT0_SIZE                   (2u)
#define CapSense_SNR_TEST_RAW_COUNT0_PARAM_ID               (0x840000BEu)


/*****************************************************************************/
/* Flash Data structure register definitions                                 */
/*****************************************************************************/
#define CapSense_BTN0_PTR2SNS_FLASH_VALUE                   (CapSense_dsFlash.wdgtArray[0].ptr2SnsFlash)
#define CapSense_BTN0_PTR2SNS_FLASH_OFFSET                  (0u)
#define CapSense_BTN0_PTR2SNS_FLASH_SIZE                    (4u)
#define CapSense_BTN0_PTR2SNS_FLASH_PARAM_ID                (0xD1000000u)

#define CapSense_BTN0_PTR2WD_RAM_VALUE                      (CapSense_dsFlash.wdgtArray[0].ptr2WdgtRam)
#define CapSense_BTN0_PTR2WD_RAM_OFFSET                     (4u)
#define CapSense_BTN0_PTR2WD_RAM_SIZE                       (4u)
#define CapSense_BTN0_PTR2WD_RAM_PARAM_ID                   (0xD0000004u)

#define CapSense_BTN0_PTR2SNS_RAM_VALUE                     (CapSense_dsFlash.wdgtArray[0].ptr2SnsRam)
#define CapSense_BTN0_PTR2SNS_RAM_OFFSET                    (8u)
#define CapSense_BTN0_PTR2SNS_RAM_SIZE                      (4u)
#define CapSense_BTN0_PTR2SNS_RAM_PARAM_ID                  (0xD3000008u)

#define CapSense_BTN0_PTR2FLTR_HISTORY_VALUE                (CapSense_dsFlash.wdgtArray[0].ptr2FltrHistory)
#define CapSense_BTN0_PTR2FLTR_HISTORY_OFFSET               (12u)
#define CapSense_BTN0_PTR2FLTR_HISTORY_SIZE                 (4u)
#define CapSense_BTN0_PTR2FLTR_HISTORY_PARAM_ID             (0xD200000Cu)

#define CapSense_BTN0_PTR2DEBOUNCE_VALUE                    (CapSense_dsFlash.wdgtArray[0].ptr2DebounceArr)
#define CapSense_BTN0_PTR2DEBOUNCE_OFFSET                   (16u)
#define CapSense_BTN0_PTR2DEBOUNCE_SIZE                     (4u)
#define CapSense_BTN0_PTR2DEBOUNCE_PARAM_ID                 (0xD4000010u)

#define CapSense_BTN0_STATIC_CONFIG_VALUE                   (CapSense_dsFlash.wdgtArray[0].staticConfig)
#define CapSense_BTN0_STATIC_CONFIG_OFFSET                  (20u)
#define CapSense_BTN0_STATIC_CONFIG_SIZE                    (4u)
#define CapSense_BTN0_STATIC_CONFIG_PARAM_ID                (0xD5000014u)

#define CapSense_BTN0_TOTAL_NUM_SNS_VALUE                   (CapSense_dsFlash.wdgtArray[0].totalNumSns)
#define CapSense_BTN0_TOTAL_NUM_SNS_OFFSET                  (24u)
#define CapSense_BTN0_TOTAL_NUM_SNS_SIZE                    (2u)
#define CapSense_BTN0_TOTAL_NUM_SNS_PARAM_ID                (0x99000018u)

#define CapSense_BTN0_TYPE_VALUE                            (CapSense_dsFlash.wdgtArray[0].wdgtType)
#define CapSense_BTN0_TYPE_OFFSET                           (26u)
#define CapSense_BTN0_TYPE_SIZE                             (1u)
#define CapSense_BTN0_TYPE_PARAM_ID                         (0x5D00001Au)

#define CapSense_BTN0_SENSE_METHOD_VALUE                    (CapSense_dsFlash.wdgtArray[0].senseMethod)
#define CapSense_BTN0_SENSE_METHOD_OFFSET                   (27u)
#define CapSense_BTN0_SENSE_METHOD_SIZE                     (1u)
#define CapSense_BTN0_SENSE_METHOD_PARAM_ID                 (0x5B00001Bu)

#define CapSense_BTN0_NUM_COLS_VALUE                        (CapSense_dsFlash.wdgtArray[0].numCols)
#define CapSense_BTN0_NUM_COLS_OFFSET                       (28u)
#define CapSense_BTN0_NUM_COLS_SIZE                         (1u)
#define CapSense_BTN0_NUM_COLS_PARAM_ID                     (0x5000001Cu)

#define CapSense_BTN0_NUM_ROWS_VALUE                        (CapSense_dsFlash.wdgtArray[0].numRows)
#define CapSense_BTN0_NUM_ROWS_OFFSET                       (29u)
#define CapSense_BTN0_NUM_ROWS_SIZE                         (1u)
#define CapSense_BTN0_NUM_ROWS_PARAM_ID                     (0x5600001Du)

#define CapSense_BTN0_X_RESOLUTION_VALUE                    (CapSense_dsFlash.wdgtArray[0].xResolution)
#define CapSense_BTN0_X_RESOLUTION_OFFSET                   (30u)
#define CapSense_BTN0_X_RESOLUTION_SIZE                     (2u)
#define CapSense_BTN0_X_RESOLUTION_PARAM_ID                 (0x9400001Eu)

#define CapSense_BTN0_X_CENT_MULT_VALUE                     (CapSense_dsFlash.wdgtArray[0].xCentroidMultiplier)
#define CapSense_BTN0_X_CENT_MULT_OFFSET                    (32u)
#define CapSense_BTN0_X_CENT_MULT_SIZE                      (4u)
#define CapSense_BTN0_X_CENT_MULT_PARAM_ID                  (0xDB000020u)

#define CapSense_BTN0_PTR2NOISE_ENVLP_VALUE                 (CapSense_dsFlash.wdgtArray[0].ptr2NoiseEnvlp)
#define CapSense_BTN0_PTR2NOISE_ENVLP_OFFSET                (36u)
#define CapSense_BTN0_PTR2NOISE_ENVLP_SIZE                  (4u)
#define CapSense_BTN0_PTR2NOISE_ENVLP_PARAM_ID              (0xDA000024u)

#define CapSense_BTN0_IIR_FILTER_COEFF_VALUE                (CapSense_dsFlash.wdgtArray[0].iirFilterCoeff)
#define CapSense_BTN0_IIR_FILTER_COEFF_OFFSET               (40u)
#define CapSense_BTN0_IIR_FILTER_COEFF_SIZE                 (1u)
#define CapSense_BTN0_IIR_FILTER_COEFF_PARAM_ID             (0x5E000028u)

#define CapSense_BTN1_PTR2SNS_FLASH_VALUE                   (CapSense_dsFlash.wdgtArray[1].ptr2SnsFlash)
#define CapSense_BTN1_PTR2SNS_FLASH_OFFSET                  (44u)
#define CapSense_BTN1_PTR2SNS_FLASH_SIZE                    (4u)
#define CapSense_BTN1_PTR2SNS_FLASH_PARAM_ID                (0xDB01002Cu)

#define CapSense_BTN1_PTR2WD_RAM_VALUE                      (CapSense_dsFlash.wdgtArray[1].ptr2WdgtRam)
#define CapSense_BTN1_PTR2WD_RAM_OFFSET                     (48u)
#define CapSense_BTN1_PTR2WD_RAM_SIZE                       (4u)
#define CapSense_BTN1_PTR2WD_RAM_PARAM_ID                   (0xDD010030u)

#define CapSense_BTN1_PTR2SNS_RAM_VALUE                     (CapSense_dsFlash.wdgtArray[1].ptr2SnsRam)
#define CapSense_BTN1_PTR2SNS_RAM_OFFSET                    (52u)
#define CapSense_BTN1_PTR2SNS_RAM_SIZE                      (4u)
#define CapSense_BTN1_PTR2SNS_RAM_PARAM_ID                  (0xDC010034u)

#define CapSense_BTN1_PTR2FLTR_HISTORY_VALUE                (CapSense_dsFlash.wdgtArray[1].ptr2FltrHistory)
#define CapSense_BTN1_PTR2FLTR_HISTORY_OFFSET               (56u)
#define CapSense_BTN1_PTR2FLTR_HISTORY_SIZE                 (4u)
#define CapSense_BTN1_PTR2FLTR_HISTORY_PARAM_ID             (0xDF010038u)

#define CapSense_BTN1_PTR2DEBOUNCE_VALUE                    (CapSense_dsFlash.wdgtArray[1].ptr2DebounceArr)
#define CapSense_BTN1_PTR2DEBOUNCE_OFFSET                   (60u)
#define CapSense_BTN1_PTR2DEBOUNCE_SIZE                     (4u)
#define CapSense_BTN1_PTR2DEBOUNCE_PARAM_ID                 (0xDE01003Cu)

#define CapSense_BTN1_STATIC_CONFIG_VALUE                   (CapSense_dsFlash.wdgtArray[1].staticConfig)
#define CapSense_BTN1_STATIC_CONFIG_OFFSET                  (64u)
#define CapSense_BTN1_STATIC_CONFIG_SIZE                    (4u)
#define CapSense_BTN1_STATIC_CONFIG_PARAM_ID                (0xDF010040u)

#define CapSense_BTN1_TOTAL_NUM_SNS_VALUE                   (CapSense_dsFlash.wdgtArray[1].totalNumSns)
#define CapSense_BTN1_TOTAL_NUM_SNS_OFFSET                  (68u)
#define CapSense_BTN1_TOTAL_NUM_SNS_SIZE                    (2u)
#define CapSense_BTN1_TOTAL_NUM_SNS_PARAM_ID                (0x91010044u)

#define CapSense_BTN1_TYPE_VALUE                            (CapSense_dsFlash.wdgtArray[1].wdgtType)
#define CapSense_BTN1_TYPE_OFFSET                           (70u)
#define CapSense_BTN1_TYPE_SIZE                             (1u)
#define CapSense_BTN1_TYPE_PARAM_ID                         (0x55010046u)

#define CapSense_BTN1_SENSE_METHOD_VALUE                    (CapSense_dsFlash.wdgtArray[1].senseMethod)
#define CapSense_BTN1_SENSE_METHOD_OFFSET                   (71u)
#define CapSense_BTN1_SENSE_METHOD_SIZE                     (1u)
#define CapSense_BTN1_SENSE_METHOD_PARAM_ID                 (0x53010047u)

#define CapSense_BTN1_NUM_COLS_VALUE                        (CapSense_dsFlash.wdgtArray[1].numCols)
#define CapSense_BTN1_NUM_COLS_OFFSET                       (72u)
#define CapSense_BTN1_NUM_COLS_SIZE                         (1u)
#define CapSense_BTN1_NUM_COLS_PARAM_ID                     (0x5A010048u)

#define CapSense_BTN1_NUM_ROWS_VALUE                        (CapSense_dsFlash.wdgtArray[1].numRows)
#define CapSense_BTN1_NUM_ROWS_OFFSET                       (73u)
#define CapSense_BTN1_NUM_ROWS_SIZE                         (1u)
#define CapSense_BTN1_NUM_ROWS_PARAM_ID                     (0x5C010049u)

#define CapSense_BTN1_X_RESOLUTION_VALUE                    (CapSense_dsFlash.wdgtArray[1].xResolution)
#define CapSense_BTN1_X_RESOLUTION_OFFSET                   (74u)
#define CapSense_BTN1_X_RESOLUTION_SIZE                     (2u)
#define CapSense_BTN1_X_RESOLUTION_PARAM_ID                 (0x9E01004Au)

#define CapSense_BTN1_X_CENT_MULT_VALUE                     (CapSense_dsFlash.wdgtArray[1].xCentroidMultiplier)
#define CapSense_BTN1_X_CENT_MULT_OFFSET                    (76u)
#define CapSense_BTN1_X_CENT_MULT_SIZE                      (4u)
#define CapSense_BTN1_X_CENT_MULT_PARAM_ID                  (0xDC01004Cu)

#define CapSense_BTN1_PTR2NOISE_ENVLP_VALUE                 (CapSense_dsFlash.wdgtArray[1].ptr2NoiseEnvlp)
#define CapSense_BTN1_PTR2NOISE_ENVLP_OFFSET                (80u)
#define CapSense_BTN1_PTR2NOISE_ENVLP_SIZE                  (4u)
#define CapSense_BTN1_PTR2NOISE_ENVLP_PARAM_ID              (0xDA010050u)

#define CapSense_BTN1_IIR_FILTER_COEFF_VALUE                (CapSense_dsFlash.wdgtArray[1].iirFilterCoeff)
#define CapSense_BTN1_IIR_FILTER_COEFF_OFFSET               (84u)
#define CapSense_BTN1_IIR_FILTER_COEFF_SIZE                 (1u)
#define CapSense_BTN1_IIR_FILTER_COEFF_PARAM_ID             (0x5C010054u)

#define CapSense_BTN2_PTR2SNS_FLASH_VALUE                   (CapSense_dsFlash.wdgtArray[2].ptr2SnsFlash)
#define CapSense_BTN2_PTR2SNS_FLASH_OFFSET                  (88u)
#define CapSense_BTN2_PTR2SNS_FLASH_SIZE                    (4u)
#define CapSense_BTN2_PTR2SNS_FLASH_PARAM_ID                (0xDD020058u)

#define CapSense_BTN2_PTR2WD_RAM_VALUE                      (CapSense_dsFlash.wdgtArray[2].ptr2WdgtRam)
#define CapSense_BTN2_PTR2WD_RAM_OFFSET                     (92u)
#define CapSense_BTN2_PTR2WD_RAM_SIZE                       (4u)
#define CapSense_BTN2_PTR2WD_RAM_PARAM_ID                   (0xDC02005Cu)

#define CapSense_BTN2_PTR2SNS_RAM_VALUE                     (CapSense_dsFlash.wdgtArray[2].ptr2SnsRam)
#define CapSense_BTN2_PTR2SNS_RAM_OFFSET                    (96u)
#define CapSense_BTN2_PTR2SNS_RAM_SIZE                      (4u)
#define CapSense_BTN2_PTR2SNS_RAM_PARAM_ID                  (0xD0020060u)

#define CapSense_BTN2_PTR2FLTR_HISTORY_VALUE                (CapSense_dsFlash.wdgtArray[2].ptr2FltrHistory)
#define CapSense_BTN2_PTR2FLTR_HISTORY_OFFSET               (100u)
#define CapSense_BTN2_PTR2FLTR_HISTORY_SIZE                 (4u)
#define CapSense_BTN2_PTR2FLTR_HISTORY_PARAM_ID             (0xD1020064u)

#define CapSense_BTN2_PTR2DEBOUNCE_VALUE                    (CapSense_dsFlash.wdgtArray[2].ptr2DebounceArr)
#define CapSense_BTN2_PTR2DEBOUNCE_OFFSET                   (104u)
#define CapSense_BTN2_PTR2DEBOUNCE_SIZE                     (4u)
#define CapSense_BTN2_PTR2DEBOUNCE_PARAM_ID                 (0xD2020068u)

#define CapSense_BTN2_STATIC_CONFIG_VALUE                   (CapSense_dsFlash.wdgtArray[2].staticConfig)
#define CapSense_BTN2_STATIC_CONFIG_OFFSET                  (108u)
#define CapSense_BTN2_STATIC_CONFIG_SIZE                    (4u)
#define CapSense_BTN2_STATIC_CONFIG_PARAM_ID                (0xD302006Cu)

#define CapSense_BTN2_TOTAL_NUM_SNS_VALUE                   (CapSense_dsFlash.wdgtArray[2].totalNumSns)
#define CapSense_BTN2_TOTAL_NUM_SNS_OFFSET                  (112u)
#define CapSense_BTN2_TOTAL_NUM_SNS_SIZE                    (2u)
#define CapSense_BTN2_TOTAL_NUM_SNS_PARAM_ID                (0x9A020070u)

#define CapSense_BTN2_TYPE_VALUE                            (CapSense_dsFlash.wdgtArray[2].wdgtType)
#define CapSense_BTN2_TYPE_OFFSET                           (114u)
#define CapSense_BTN2_TYPE_SIZE                             (1u)
#define CapSense_BTN2_TYPE_PARAM_ID                         (0x5E020072u)

#define CapSense_BTN2_SENSE_METHOD_VALUE                    (CapSense_dsFlash.wdgtArray[2].senseMethod)
#define CapSense_BTN2_SENSE_METHOD_OFFSET                   (115u)
#define CapSense_BTN2_SENSE_METHOD_SIZE                     (1u)
#define CapSense_BTN2_SENSE_METHOD_PARAM_ID                 (0x58020073u)

#define CapSense_BTN2_NUM_COLS_VALUE                        (CapSense_dsFlash.wdgtArray[2].numCols)
#define CapSense_BTN2_NUM_COLS_OFFSET                       (116u)
#define CapSense_BTN2_NUM_COLS_SIZE                         (1u)
#define CapSense_BTN2_NUM_COLS_PARAM_ID                     (0x53020074u)

#define CapSense_BTN2_NUM_ROWS_VALUE                        (CapSense_dsFlash.wdgtArray[2].numRows)
#define CapSense_BTN2_NUM_ROWS_OFFSET                       (117u)
#define CapSense_BTN2_NUM_ROWS_SIZE                         (1u)
#define CapSense_BTN2_NUM_ROWS_PARAM_ID                     (0x55020075u)

#define CapSense_BTN2_X_RESOLUTION_VALUE                    (CapSense_dsFlash.wdgtArray[2].xResolution)
#define CapSense_BTN2_X_RESOLUTION_OFFSET                   (118u)
#define CapSense_BTN2_X_RESOLUTION_SIZE                     (2u)
#define CapSense_BTN2_X_RESOLUTION_PARAM_ID                 (0x97020076u)

#define CapSense_BTN2_X_CENT_MULT_VALUE                     (CapSense_dsFlash.wdgtArray[2].xCentroidMultiplier)
#define CapSense_BTN2_X_CENT_MULT_OFFSET                    (120u)
#define CapSense_BTN2_X_CENT_MULT_SIZE                      (4u)
#define CapSense_BTN2_X_CENT_MULT_PARAM_ID                  (0xD7020078u)

#define CapSense_BTN2_PTR2NOISE_ENVLP_VALUE                 (CapSense_dsFlash.wdgtArray[2].ptr2NoiseEnvlp)
#define CapSense_BTN2_PTR2NOISE_ENVLP_OFFSET                (124u)
#define CapSense_BTN2_PTR2NOISE_ENVLP_SIZE                  (4u)
#define CapSense_BTN2_PTR2NOISE_ENVLP_PARAM_ID              (0xD602007Cu)

#define CapSense_BTN2_IIR_FILTER_COEFF_VALUE                (CapSense_dsFlash.wdgtArray[2].iirFilterCoeff)
#define CapSense_BTN2_IIR_FILTER_COEFF_OFFSET               (128u)
#define CapSense_BTN2_IIR_FILTER_COEFF_SIZE                 (1u)
#define CapSense_BTN2_IIR_FILTER_COEFF_PARAM_ID             (0x53020080u)

#define CapSense_SLD_PTR2SNS_FLASH_VALUE                    (CapSense_dsFlash.wdgtArray[3].ptr2SnsFlash)
#define CapSense_SLD_PTR2SNS_FLASH_OFFSET                   (132u)
#define CapSense_SLD_PTR2SNS_FLASH_SIZE                     (4u)
#define CapSense_SLD_PTR2SNS_FLASH_PARAM_ID                 (0xD6030084u)

#define CapSense_SLD_PTR2WD_RAM_VALUE                       (CapSense_dsFlash.wdgtArray[3].ptr2WdgtRam)
#define CapSense_SLD_PTR2WD_RAM_OFFSET                      (136u)
#define CapSense_SLD_PTR2WD_RAM_SIZE                        (4u)
#define CapSense_SLD_PTR2WD_RAM_PARAM_ID                    (0xD5030088u)

#define CapSense_SLD_PTR2SNS_RAM_VALUE                      (CapSense_dsFlash.wdgtArray[3].ptr2SnsRam)
#define CapSense_SLD_PTR2SNS_RAM_OFFSET                     (140u)
#define CapSense_SLD_PTR2SNS_RAM_SIZE                       (4u)
#define CapSense_SLD_PTR2SNS_RAM_PARAM_ID                   (0xD403008Cu)

#define CapSense_SLD_PTR2FLTR_HISTORY_VALUE                 (CapSense_dsFlash.wdgtArray[3].ptr2FltrHistory)
#define CapSense_SLD_PTR2FLTR_HISTORY_OFFSET                (144u)
#define CapSense_SLD_PTR2FLTR_HISTORY_SIZE                  (4u)
#define CapSense_SLD_PTR2FLTR_HISTORY_PARAM_ID              (0xD2030090u)

#define CapSense_SLD_PTR2DEBOUNCE_VALUE                     (CapSense_dsFlash.wdgtArray[3].ptr2DebounceArr)
#define CapSense_SLD_PTR2DEBOUNCE_OFFSET                    (148u)
#define CapSense_SLD_PTR2DEBOUNCE_SIZE                      (4u)
#define CapSense_SLD_PTR2DEBOUNCE_PARAM_ID                  (0xD3030094u)

#define CapSense_SLD_STATIC_CONFIG_VALUE                    (CapSense_dsFlash.wdgtArray[3].staticConfig)
#define CapSense_SLD_STATIC_CONFIG_OFFSET                   (152u)
#define CapSense_SLD_STATIC_CONFIG_SIZE                     (4u)
#define CapSense_SLD_STATIC_CONFIG_PARAM_ID                 (0xD0030098u)

#define CapSense_SLD_TOTAL_NUM_SNS_VALUE                    (CapSense_dsFlash.wdgtArray[3].totalNumSns)
#define CapSense_SLD_TOTAL_NUM_SNS_OFFSET                   (156u)
#define CapSense_SLD_TOTAL_NUM_SNS_SIZE                     (2u)
#define CapSense_SLD_TOTAL_NUM_SNS_PARAM_ID                 (0x9E03009Cu)

#define CapSense_SLD_TYPE_VALUE                             (CapSense_dsFlash.wdgtArray[3].wdgtType)
#define CapSense_SLD_TYPE_OFFSET                            (158u)
#define CapSense_SLD_TYPE_SIZE                              (1u)
#define CapSense_SLD_TYPE_PARAM_ID                          (0x5A03009Eu)

#define CapSense_SLD_SENSE_METHOD_VALUE                     (CapSense_dsFlash.wdgtArray[3].senseMethod)
#define CapSense_SLD_SENSE_METHOD_OFFSET                    (159u)
#define CapSense_SLD_SENSE_METHOD_SIZE                      (1u)
#define CapSense_SLD_SENSE_METHOD_PARAM_ID                  (0x5C03009Fu)

#define CapSense_SLD_NUM_COLS_VALUE                         (CapSense_dsFlash.wdgtArray[3].numCols)
#define CapSense_SLD_NUM_COLS_OFFSET                        (160u)
#define CapSense_SLD_NUM_COLS_SIZE                          (1u)
#define CapSense_SLD_NUM_COLS_PARAM_ID                      (0x5A0300A0u)

#define CapSense_SLD_NUM_ROWS_VALUE                         (CapSense_dsFlash.wdgtArray[3].numRows)
#define CapSense_SLD_NUM_ROWS_OFFSET                        (161u)
#define CapSense_SLD_NUM_ROWS_SIZE                          (1u)
#define CapSense_SLD_NUM_ROWS_PARAM_ID                      (0x5C0300A1u)

#define CapSense_SLD_X_RESOLUTION_VALUE                     (CapSense_dsFlash.wdgtArray[3].xResolution)
#define CapSense_SLD_X_RESOLUTION_OFFSET                    (162u)
#define CapSense_SLD_X_RESOLUTION_SIZE                      (2u)
#define CapSense_SLD_X_RESOLUTION_PARAM_ID                  (0x9E0300A2u)

#define CapSense_SLD_X_CENT_MULT_VALUE                      (CapSense_dsFlash.wdgtArray[3].xCentroidMultiplier)
#define CapSense_SLD_X_CENT_MULT_OFFSET                     (164u)
#define CapSense_SLD_X_CENT_MULT_SIZE                       (4u)
#define CapSense_SLD_X_CENT_MULT_PARAM_ID                   (0xDC0300A4u)

#define CapSense_SLD_PTR2NOISE_ENVLP_VALUE                  (CapSense_dsFlash.wdgtArray[3].ptr2NoiseEnvlp)
#define CapSense_SLD_PTR2NOISE_ENVLP_OFFSET                 (168u)
#define CapSense_SLD_PTR2NOISE_ENVLP_SIZE                   (4u)
#define CapSense_SLD_PTR2NOISE_ENVLP_PARAM_ID               (0xDF0300A8u)

#define CapSense_SLD_IIR_FILTER_COEFF_VALUE                 (CapSense_dsFlash.wdgtArray[3].iirFilterCoeff)
#define CapSense_SLD_IIR_FILTER_COEFF_OFFSET                (172u)
#define CapSense_SLD_IIR_FILTER_COEFF_SIZE                  (1u)
#define CapSense_SLD_IIR_FILTER_COEFF_PARAM_ID              (0x590300ACu)


#endif /* End CY_SENSE_CapSense_REGISTER_MAP_H */


/* [] END OF FILE */
