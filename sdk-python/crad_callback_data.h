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
 * @date        February 2, 2021
 */

#ifndef CRAD_PYTHON_CRAD_CALLBACK_DATA_H
#define CRAD_PYTHON_CRAD_CALLBACK_DATA_H

#include <crad/crad_delegate.h>


#define REGISTER_DEVICE_AVAILABLE_CALLBACK            "OnRegisterDeviceAvailable"
#define CONFIG_DATA_AVAILABLE_CALLBACK                "OnConfigDataAvailable"
#define BROADCASTS_AVAILABLE_CALLBACK                 "OnBroadcastsAvailable"
#define BROADCAST_DATA_AVAILABLE_CALLBACK             "OnBroadcastDataAvailable"
#define LIVE_DATA_AVAILABLE_CALLBACK                  "OnLiveDataAvailable"
#define GENRES_AVAILABLE_CALLBACK                     "OnGenresAvailable"
#define IPC_CATEGORIES_AVAILABLE_CALLBACK             "OnIpcCategoriesAvailable"
#define IPC_CONTENT_INFO_AVAILABLE_CALLBACK           "OnIpcContentInfoAvailable"
#define IPC_CONTENT_PLAY_INFO_AVAILABLE_CALLBACK      "OnIpcContentPlayInfoAvailable"
#define IPC_SIMILAR_CONTENT_AVAILABLE_CALLBACK        "OnIpcSimilarContentAvailable"
#define IPC_SEARCH_CONTENT_AVAILABLE_CALLBACK         "OnIpcSearchContentAvailable"
#define IPC_PODCAST_EPISODES_AVAILABLE_CALLBACK       "OnIpcPodcastEpisodesAvailable"
#define IPC_PODCAST_LATEST_EPISODE_AVAILABLE_CALLBACK "OnIpcPodcastLatestEpisodeAvailable"
#define LE_EVENT_INFO_AVAILABLE_CALLBACK              "OnLeEventInfoAvailable"
#define LE_EVENTS_AVAILABLE_CALLBACK                  "OnLeEventsAvailable"
#define IMAGES_AVAILABLE_CALLBACK                     "OnImagesAvailable"
#define MESSAGE_CODE_AVAILABLE_CALLBACK               "OnMessageCodeAvailable"
#define LOCATION_INFO_REQUESTED_CALLBACK              "OnLocationInfoRequested"
#define ACR_FINGERPRINT_IDENTIFIED_CALLBACK           "OnAcrFingerprintIdentified"


struct RegisterDeviceAvailableCallbackData {
  crad::MFG_INFO_T info;
  
  int counter;
};

struct ConfigDataAvailableCallbackData {
  crad::MFG_INFO_T info;
  
  int counter;
};

struct BroadcastsAvailableCallbackData {
  crad::CONRAD_BROADCAST_LIST_T broadcasts;
  
  int counter;
};

struct BroadcastDataAvailableCallbackData {
  crad::BROADCAST_MODEL_T broadcast_info;
  
  int counter;
};

struct LiveDataAvailableCallbackData {
  crad::LIVE_DATA_T live_data;
  
  int counter;
};

struct GenresAvailableCallbackData {
  crad::GENRE_LIST_T genres;
  
  int counter;
};

struct IpcCategoriesAvailableCallbackData {
  std::string ipc_cat_path;
  std::string categories_str;
  
  int counter;
};

struct IpcContentInfoAvailableCallbackData {
  std::string ipc_content_id;
  std::string response_str;
  
  int counter;
};

struct IpcContentPlayInfoAvailableCallbackData {
  std::string ipc_playback_id;
  std::string response_str;
  
  int counter;
};

struct IpcSimilarContentAvailableCallbackData {
  std::string ipc_content_id;
  std::string response_str;
  
  int counter;
};

struct IpcSearchContentAvailableCallbackData {
  std::string search_query;
  std::string response_str;
  
  int counter;
};

struct IpcPodcastEpisodesAvailableCallbackData {
  std::string ipc_content_id;
  std::string response_str;
  
  int counter;
};

struct IpcPodcastLatestEpisodeAvailableCallbackData {
  std::string ipc_content_id;
  std::string response_str;
  
  int counter;
};

struct LeEventInfoAvailableCallbackData {
  std::string le_event_id;
  std::string response_str;
  
  int counter;
};

struct LeEventsAvailableCallbackData {
  std::string artist_name;
  crad::UINT8 genre_id;
  std::string response_str;
  
  int counter;
};

struct ImagesAvailableCallbackData {
  crad::IMAGES_LIST_T images;
  
  int counter;
};

struct MessageCodeAvailableCallbackData {
  crad::CRAD_MESSAGE_CODES_T code;
  
  int counter;
};

struct LocationInfoRequestedCallbackData {
  int counter;
};

struct AcrFingerprintIdentifiedCallbackData {
  crad::ACR_META_DATA_T acr_metadata;
  
  int counter;
};


#endif  // CRAD_PYTHON_CRAD_CALLBACK_DATA_H
