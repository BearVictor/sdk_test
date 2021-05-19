/*
 *  Copyright [2017] <Copyright iBiquity>
 */
#include "crad_delegate_impl.h"

#include <iostream>

#include <crad/utils/crad_data_stream_output.h>

#define CALL std::cout << __FUNCTION__ << std::endl
#define JSON_CALL(stream) stream << "\t" << m_callback_counter << ": { callback_name: " << __FUNCTION__ << ",\n\t\t "
#define JSON_CALL_END(stream) stream << "\t},\n"
#define OUTPUT_FILE_NAME "delegate_output.json"

ConnectedRadioDelegateImpl::ConnectedRadioDelegateImpl():
    m_register_device_available(),
    m_config_data_available(),
    m_broadcasts_available(),
    m_broadcast_data_available(),
    m_live_data_available(),
    m_genres_available(),
    m_ipc_categories_available(),
    m_ipc_content_info_available(),
    m_ipc_content_play_info_available(),
    m_ipc_similar_content_available(),
    m_ipc_search_content_available(),
    m_ipc_podcast_episodes_available(),
    m_ipc_podcast_latest_episode_available(),
    m_le_event_info_available(),
    m_le_events_available(),
    m_images_available(),
    m_message_code_available(),
    m_location_info_requested(),
    m_acr_fingerprint_identified(),
    m_callback_counter(0) {
}

ConnectedRadioDelegateImpl::~ConnectedRadioDelegateImpl() {
  m_out_file.close();
}

void ConnectedRadioDelegateImpl::OnRegisterDeviceAvailable(const crad::MFG_INFO_T &info) {
  m_register_device_available.info = info;
  m_last_callbacks.push_back(REGISTER_DEVICE_AVAILABLE_CALLBACK);

  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnConfigDataAvailable(const crad::MFG_INFO_T& info) {
  m_config_data_available.info = info;
  m_last_callbacks.push_back(CONFIG_DATA_AVAILABLE_CALLBACK);

  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnBroadcastsAvailable(const crad::CONRAD_BROADCAST_LIST_T &broadcasts) {
  m_broadcasts_available.broadcasts = broadcasts;
  m_last_callbacks.push_back(BROADCASTS_AVAILABLE_CALLBACK);

  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnBroadcastDataAvailable(const crad::BROADCAST_MODEL_T &broadcast_info) {
  m_broadcast_data_available.broadcast_info = broadcast_info;
  m_last_callbacks.push_back(BROADCAST_DATA_AVAILABLE_CALLBACK);

  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnLiveDataAvailable(const crad::LIVE_DATA_T &live_data) {
  m_live_data_available.live_data = live_data;
  m_last_callbacks.push_back(LIVE_DATA_AVAILABLE_CALLBACK);

  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnGenresAvailable(const crad::GENRE_LIST_T &genres) {
  m_genres_available.genres = genres;
  m_last_callbacks.push_back(GENRES_AVAILABLE_CALLBACK);

  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnIpcCategoriesAvailable(const STRING &ipc_cat_path, const STRING &categories_str) {
  m_ipc_categories_available.ipc_cat_path   = ipc_cat_path;
  m_ipc_categories_available.categories_str = categories_str;
  m_last_callbacks.push_back(IPC_CATEGORIES_AVAILABLE_CALLBACK);

  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnIpcContentInfoAvailable(const STRING &ipc_content_id, const STRING &response_str) {
  m_ipc_content_info_available.ipc_content_id = ipc_content_id;
  m_ipc_content_info_available.response_str   = response_str;
  m_last_callbacks.push_back(IPC_CONTENT_INFO_AVAILABLE_CALLBACK);

  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnIpcContentPlayInfoAvailable(const STRING &ipc_playback_id, const STRING &response_str)
{
  m_ipc_content_play_info_available.ipc_playback_id = ipc_playback_id;
  m_ipc_content_play_info_available.response_str    = response_str;
  m_last_callbacks.push_back(IPC_CONTENT_PLAY_INFO_AVAILABLE_CALLBACK);

  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnIpcSimilarContentAvailable(const STRING &ipc_content_id, const string &response_str) {
  m_ipc_similar_content_available.ipc_content_id = ipc_content_id;
  m_ipc_similar_content_available.response_str   = response_str;
  m_last_callbacks.push_back(IPC_SIMILAR_CONTENT_AVAILABLE_CALLBACK);

  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnIpcSearchContentAvailable(const STRING &search_query, const string &response_str) {
  m_ipc_search_content_available.search_query = search_query;
  m_ipc_search_content_available.response_str = response_str;
  m_last_callbacks.push_back(IPC_SEARCH_CONTENT_AVAILABLE_CALLBACK);

  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnIpcPodcastEpisodesAvailable(const STRING &ipc_content_id, const string &response_str) {
  m_ipc_podcast_episodes_available.ipc_content_id = ipc_content_id;
  m_ipc_podcast_episodes_available.response_str   = response_str;
  m_last_callbacks.push_back(IPC_PODCAST_EPISODES_AVAILABLE_CALLBACK);

  ++m_callback_counter;
}

void
ConnectedRadioDelegateImpl::OnIpcPodcastLatestEpisodeAvailable(const STRING &ipc_content_id, const string &response_str) {
  m_ipc_podcast_latest_episode_available.ipc_content_id  = ipc_content_id;
  m_ipc_podcast_latest_episode_available.response_str    = response_str;
  m_last_callbacks.push_back(IPC_PODCAST_LATEST_EPISODE_AVAILABLE_CALLBACK);

  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnLeEventInfoAvailable(const STRING &le_event_id, const string &response_str) {
  m_le_event_info_available.le_event_id  = le_event_id;
  m_le_event_info_available.response_str = response_str;
  m_last_callbacks.push_back(LE_EVENT_INFO_AVAILABLE_CALLBACK);

  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnLeEventsAvailable(const STRING &artist_name, const crad::UINT8 genre_id,
                                                     const string &response_str) {
  m_le_events_available.artist_name  = artist_name;
  m_le_events_available.genre_id     = genre_id;
  m_le_events_available.response_str = response_str;
  m_last_callbacks.push_back(LE_EVENTS_AVAILABLE_CALLBACK);

  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnImagesAvailable(const crad::IMAGES_LIST_T &images) {
  m_images_available.images = images;
  m_last_callbacks.push_back(IMAGES_AVAILABLE_CALLBACK);
  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnMessageCodeAvailable(const crad::CRAD_MESSAGE_CODES_T &code) {
  m_message_code_available.code = code;
  m_last_callbacks.push_back(MESSAGE_CODE_AVAILABLE_CALLBACK);
  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnLocationInfoRequested() {
  m_last_callbacks.push_back(LOCATION_INFO_REQUESTED_CALLBACK);
  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnAcrFingerprintIdentified(const crad::ACR_META_DATA_T& acr_metadata) {
  m_acr_fingerprint_identified.acr_metadata = acr_metadata;
  m_last_callbacks.push_back(ACR_FINGERPRINT_IDENTIFIED_CALLBACK);
  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::OnConfigSettingsChange(const std::bitset<8> &change_mask,
                                                        const crad::CONFIG_DATA_T& config) {
  m_config_data_changed.change_mask = change_mask;
  m_config_data_changed.config = config;
  m_last_callbacks.push_back(ACR_FINGERPRINT_IDENTIFIED_CALLBACK);
  ++m_callback_counter;
}

void ConnectedRadioDelegateImpl::RestartCallbackCounter() {
  m_callback_counter = 0;
}

void ConnectedRadioDelegateImpl::ClearCallbacksList() {
  m_register_device_available             = RegisterDeviceAvailableCallbackData();
  m_config_data_available                 = ConfigDataAvailableCallbackData();
  m_broadcasts_available                  = BroadcastsAvailableCallbackData();
  m_broadcast_data_available              = BroadcastDataAvailableCallbackData();
  m_live_data_available                   = LiveDataAvailableCallbackData();
  m_genres_available                      = GenresAvailableCallbackData();
  m_ipc_categories_available              = IpcCategoriesAvailableCallbackData();
  m_ipc_content_info_available            = IpcContentInfoAvailableCallbackData();
  m_ipc_content_play_info_available       = IpcContentPlayInfoAvailableCallbackData();
  m_ipc_similar_content_available         = IpcSimilarContentAvailableCallbackData();
  m_ipc_search_content_available          = IpcSearchContentAvailableCallbackData();
  m_ipc_podcast_episodes_available        = IpcPodcastEpisodesAvailableCallbackData();
  m_ipc_podcast_latest_episode_available  = IpcPodcastLatestEpisodeAvailableCallbackData();
  m_le_event_info_available               = LeEventInfoAvailableCallbackData();
  m_le_events_available                   = LeEventsAvailableCallbackData();
  m_images_available                      = ImagesAvailableCallbackData();
  m_message_code_available                = MessageCodeAvailableCallbackData();
  m_location_info_requested               = LocationInfoRequestedCallbackData();
  m_acr_fingerprint_identified            = AcrFingerprintIdentifiedCallbackData();
  m_config_data_changed                   = OnConfigSettingsChangeCallbackData();

  m_last_callbacks.clear();
}
