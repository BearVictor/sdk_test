/*
 * DTS, INC.
 * 5220 LAS VIRGENES ROAD
 * CALABASAS, CA 91302 USA
 *
 * ©DTS,INC. ALL RIGHTS RESERVED.
 *
 * THIS SOFTWARE, ANY COMPONENTS THEREOF, AND ANY RELATED DOCUMENTATION (THE “PRODUCT”) CONTAINS
 * CONFIDENTIAL PROPRIETARY INFORMATION OWNED BY DTS, INC. AND/OR ITS AFFILIATES (“DTS”) INCLUDING
 * BUT NOT LIMITED TO TRADE SECRETS, KNOW-HOW, TECHNICAL, AND BUSINESS INFORMATION. UNLESS OTHERWISE
 * PROVIDED UNDER THE TERMS OF A FULLY-EXECUTED WRITTEN AGREEMENT BY AND BETWEEN THE RECIPIENT
 * HEREOF AND DTS, ALL USE, DUPLICATION, DISCLOSURE, OR DISTRIBUTION OF THE PRODUCT, IN ANY FORM,
 * IS PROHIBITED AND IS A VIOLATION OF STATE, FEDERAL, AND INTERNATIONAL LAWS. THE PRODUCT CONTAINS
 * CONFIDENTIAL, PROPRIETARY TRADE SECRETS, AND IS PROTECTED BY APPLICABLE COPYRIGHT LAW AND/OR PATENT
 * LAW. BOTH CIVIL AND CRIMINAL PENALTIES APPLY.
 *
 * ALGORITHMS, DATA STRUCTURES AND METHODS CONTAINED IN THE PRODUCT MAY BE PROTECTED BY ONE OR MORE
 * PATENTS OR PATENT APPLICATIONS. UNLESS OTHERWISE PROVIDED UNDER THE TERMS OF A FULLY-EXECUTED
 * WRITTEN AGREEMENT BY AND BETWEEN THE RECIPIENT HEREOF AND DTS, THE FOLLOWING TERMS SHALL APPLY
 * TO ANY USE OF THE PRODUCT:  (I) USE OF THE PRODUCT IS AT THE RECIPIENT'S SOLE RISK; (II) THE
 * PRODUCT IS PROVIDED "AS IS" AND WITHOUT WARRANTY OF ANY KIND AND DTS EXPRESSLY DISCLAIMS ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO ANY IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE, REGARDLESS OF WHETHER DTS KNOWS OR HAS REASON TO KNOW OF THE
 * USER'S PARTICULAR NEEDS; (III) DTS DOES NOT WARRANT THAT THE PRODUCT MEET USER'S REQUIREMENTS,
 * OR THAT ANY ALLEGED DEFECTS IN THE PRODUCT WILL BE CORRECTED; (IV) DTS DOES NOT WARRANT THAT
 * THE OPERATION OF ANY HARDWARE OR SOFTWARE ASSOCIATED WITH THE PRODUCT WILL BE UNINTERRUPTED
 * OR ERROR-FREE; AND (V) UNDER NO CIRCUMSTANCES, INCLUDING NEGLIGENCE, SHALL DTS OR THE DIRECTORS,
 * OFFICERS, EMPLOYEES, OR AGENTS OF DTS, BE LIABLE TO USER FOR ANY INCIDENTAL, INDIRECT, SPECIAL,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO DAMAGES FOR LOSS OF BUSINESS PROFITS,
 * BUSINESS INTERRUPTION, AND LOSS OF BUSINESS INFORMATION) ARISING OUT OF THE USE, MISUSE,
 * OR INABILITY TO USE THE PRODUCT.
 */
/**
 * @file        crad_delegate_impl.h
 *
 * @brief       Connected Radio SDK Client App Version Description File
 * @details     This file defines crad-client-cli app version
 */

#ifndef CRAD_PYTHON_CRAD_DELEGATE_IMPL_H
#define CRAD_PYTHON_CRAD_DELEGATE_IMPL_H

#include <crad/crad_delegate.h>

#include <fstream>
#include <unordered_map>
#include <memory>

#include "crad_callback_data.h"


class ConnectedRadioDelegateImpl : public crad::ConnectedRadioDelegate {
 public:
  ConnectedRadioDelegateImpl();
  ~ConnectedRadioDelegateImpl();
  void OnRegisterDeviceAvailable(const crad::MFG_INFO_T &info) override;
  void OnConfigDataAvailable(const crad::MFG_INFO_T& info) override;
  void OnBroadcastsAvailable(const crad::CONRAD_BROADCAST_LIST_T &broadcasts) override;
  void OnBroadcastDataAvailable(const crad::BROADCAST_MODEL_T &broadcast_info) override;
  void OnLiveDataAvailable(const crad::LIVE_DATA_T &live_data) override;
  void OnGenresAvailable(const crad::GENRE_LIST_T &genres) override;
  void OnIpcCategoriesAvailable(const std::string &ipc_cat_path, const std::string &categories_str) override;
  void OnIpcContentInfoAvailable(const std::string &ipc_content_id, const std::string &response_str) override;
  void OnIpcContentPlayInfoAvailable(const std::string &ipc_playback_id, const std::string &response_str) override;
  void OnIpcSimilarContentAvailable(const std::string &ipc_content_id, const std::string &response_str) override;
  void OnIpcSearchContentAvailable(const std::string &search_query, const std::string &response_str) override;
  void OnIpcPodcastEpisodesAvailable(const std::string &ipc_content_id, const std::string &response_str) override;
  void OnIpcPodcastLatestEpisodeAvailable(const std::string &ipc_content_id, const std::string &response_str) override;
  void OnLeEventInfoAvailable(const std::string &le_event_id, const std::string &response_str) override;
  void OnLeEventsAvailable(const std::string &artist_name, const crad::UINT8 genre_id, const string &response_str) override;
  void OnImagesAvailable(const crad::IMAGES_LIST_T &images) override;
  void OnMessageCodeAvailable(const crad::CRAD_MESSAGE_CODES_T &code) override;
  void OnLocationInfoRequested() override;
  void OnAcrFingerprintIdentified(const crad::ACR_META_DATA_T &acr_metadata) override;
  void OnConfigSettingsChange(const std::bitset<crad::kConfigDataChangeMaskSize> &change_mask, const crad::CONFIG_DATA_T& config) override;

  void RestartCallbackCounter();
  void ClearCallbacksList();

  RegisterDeviceAvailableCallbackData           m_register_device_available;
  ConfigDataAvailableCallbackData               m_config_data_available;
  BroadcastsAvailableCallbackData               m_broadcasts_available;
  BroadcastDataAvailableCallbackData            m_broadcast_data_available;
  LiveDataAvailableCallbackData                 m_live_data_available;
  GenresAvailableCallbackData                   m_genres_available;
  IpcCategoriesAvailableCallbackData            m_ipc_categories_available;
  IpcContentInfoAvailableCallbackData           m_ipc_content_info_available;
  IpcContentPlayInfoAvailableCallbackData       m_ipc_content_play_info_available;
  IpcSimilarContentAvailableCallbackData        m_ipc_similar_content_available;
  IpcSearchContentAvailableCallbackData         m_ipc_search_content_available;
  IpcPodcastEpisodesAvailableCallbackData       m_ipc_podcast_episodes_available;
  IpcPodcastLatestEpisodeAvailableCallbackData  m_ipc_podcast_latest_episode_available;
  LeEventInfoAvailableCallbackData              m_le_event_info_available;
  LeEventsAvailableCallbackData                 m_le_events_available;
  ImagesAvailableCallbackData                   m_images_available;
  MessageCodeAvailableCallbackData              m_message_code_available;
  LocationInfoRequestedCallbackData             m_location_info_requested;
  AcrFingerprintIdentifiedCallbackData          m_acr_fingerprint_identified;
  ConfigSettingsChangeCallbackData              m_config_data_changed;

  std::vector<std::string> m_last_callbacks;

 private:
  std::ofstream m_out_file;
  int m_callback_counter;

  std::unordered_map<std::string, std::shared_ptr<void*>> m_last_received;
};


#endif // CRAD_PYTHON_CRAD_DELEGATE_IMPL_H
