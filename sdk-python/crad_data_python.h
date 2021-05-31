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
 * CONFIDENTIAL, PROPRIETARY TRADE SECRETS, AND IS PROTECTED BY APPLICABLE COPYRIGHT LAW AND/OR
 * PATENT LAW. BOTH CIVIL AND CRIMINAL PENALTIES APPLY.
 *
 * ALGORITHMS, DATA STRUCTURES AND METHODS CONTAINED IN THE PRODUCT MAY BE PROTECTED BY ONE OR MORE
 * PATENTS OR PATENT APPLICATIONS. UNLESS OTHERWISE PROVIDED UNDER THE TERMS OF A FULLY-EXECUTED
 * WRITTEN AGREEMENT BY AND BETWEEN THE RECIPIENT HEREOF AND DTS, THE FOLLOWING TERMS SHALL APPLY
 * TO ANY USE OF THE PRODUCT:  (I) USE OF THE PRODUCT IS AT THE RECIPIENT'S SOLE RISK; (II) THE
 * PRODUCT IS PROVIDED "AS IS" AND WITHOUT WARRANTY OF ANY KIND AND DTS EXPRESSLY DISCLAIMS ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO ANY IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, REGARDLESS OF WHETHER DTS KNOWS OR HAS
 * REASON TO KNOW OF THE USER'S PARTICULAR NEEDS; (III) DTS DOES NOT WARRANT THAT THE PRODUCT MEET
 * USER'S REQUIREMENTS, OR THAT ANY ALLEGED DEFECTS IN THE PRODUCT WILL BE CORRECTED; (IV) DTS DOES
 * NOT WARRANT THAT THE OPERATION OF ANY HARDWARE OR SOFTWARE ASSOCIATED WITH THE PRODUCT WILL BE
 * UNINTERRUPTED OR ERROR-FREE; AND (V) UNDER NO CIRCUMSTANCES, INCLUDING NEGLIGENCE, SHALL DTS OR
 * THE DIRECTORS, OFFICERS, EMPLOYEES, OR AGENTS OF DTS, BE LIABLE TO USER FOR ANY INCIDENTAL,
 * INDIRECT, SPECIAL, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO DAMAGES FOR LOSS OF
 * BUSINESS PROFITS, BUSINESS INTERRUPTION, AND LOSS OF BUSINESS INFORMATION) ARISING OUT OF THE
 * USE, MISUSE, OR INABILITY TO USE THE PRODUCT.
 */

/*
 *  Copyright [2015] <Copyright iBiquity>
 */

/**
 * @file        crad_data_python.h
 *
 * @brief       Defines data structures used in the ConnectedRadio SDK for 
 *              the Boost Python lib wrapper
 * @date        January 4, 2021
 */

#ifndef CRAD_BOOST_PYTHON_CRAD_DATA_PYTHON_H_
#define CRAD_BOOST_PYTHON_CRAD_DATA_PYTHON_H_

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <crad/crad_data.h>
#include <crad/crad_tuner_registration_data.h>

namespace py = pybind11;


void InitCradDataModule(py::module &m) {
  py::class_<crad::VEHICLE_INFO_T>(m, "VEHICLE_INFO_T").def(py::init<>())
    .def_readwrite("make",                  &crad::VEHICLE_INFO_T::make)
    .def_readwrite("model",                 &crad::VEHICLE_INFO_T::model)
    .def_readwrite("year",                  &crad::VEHICLE_INFO_T::year)
  ;

  py::class_<crad::MFG_INFO_T>(m, "MFG_INFO_T").def(py::init<>())
    .def_readwrite("lat",                   &crad::MFG_INFO_T::lat)
    .def_readwrite("lng",                   &crad::MFG_INFO_T::lng)
    .def_readwrite("url",                   &crad::MFG_INFO_T::url)
    .def_readwrite("mfg_id",                &crad::MFG_INFO_T::mfg_id)
    .def_readwrite("device_id",             &crad::MFG_INFO_T::device_id)
    .def_readwrite("hash",                  &crad::MFG_INFO_T::hash)
    .def_readwrite("geo_code",              &crad::MFG_INFO_T::geo_code)
  ;

  py::class_<crad::DEVICE_REGISTER_INFO_T>(m, "DEVICE_REGISTER_INFO_T").def(py::init<>())
    .def_readwrite("url",                   &crad::DEVICE_REGISTER_INFO_T::url)
    .def_readwrite("mfg_id",                &crad::DEVICE_REGISTER_INFO_T::mfg_id)
    .def_readwrite("mfg_secret",            &crad::DEVICE_REGISTER_INFO_T::mfg_secret)
    .def_readwrite("lat",                   &crad::DEVICE_REGISTER_INFO_T::lat)
    .def_readwrite("lng",                   &crad::DEVICE_REGISTER_INFO_T::lng)
    .def_readwrite("mfg",                   &crad::DEVICE_REGISTER_INFO_T::mfg)
    .def_readwrite("brand",                 &crad::DEVICE_REGISTER_INFO_T::brand)
    .def_readwrite("device",                &crad::DEVICE_REGISTER_INFO_T::device)
    .def_readwrite("model",                 &crad::DEVICE_REGISTER_INFO_T::model)
    .def_readwrite("serial",                &crad::DEVICE_REGISTER_INFO_T::serial)
    .def_readwrite("version",               &crad::DEVICE_REGISTER_INFO_T::version)
  ;

  py::class_<crad::LOCATION_INFO_T>(m, "LOCATION_INFO_T").def(py::init<>())
    .def_readwrite("latitude",              &crad::LOCATION_INFO_T::latitude)
    .def_readwrite("longitude",             &crad::LOCATION_INFO_T::longitude)
  ;

  py::enum_<crad::eLiveDataDisplayPurpose>(m, "eLiveDataDisplayPurpose")
    .value("eGuide",                        crad::eLiveDataDisplayPurpose::eGuide)
    .value("eTuned",                        crad::eLiveDataDisplayPurpose::eTuned)
    .value("ePreset",                       crad::eLiveDataDisplayPurpose::ePreset)
    .export_values();
  ;

  py::enum_<crad::REPORT_ACTION_TYPE_E>(m, "REPORT_ACTION_TYPE_E")
    .value("eReportActionTypeExit",         crad::REPORT_ACTION_TYPE_E::eReportActionTypeExit)
    .value("eReportActionTypeSMS",          crad::REPORT_ACTION_TYPE_E::eReportActionTypeSMS)
    .value("eReportActionTypePhone",        crad::REPORT_ACTION_TYPE_E::eReportActionTypePhone)
    .value("eReportActionTypeShare",        crad::REPORT_ACTION_TYPE_E::eReportActionTypeShare)
    .value("eReportActionTypeNav",          crad::REPORT_ACTION_TYPE_E::eReportActionTypeNav)
    .value("eReportActionTypeThumbs",       crad::REPORT_ACTION_TYPE_E::eReportActionTypeThumbs)
    .export_values();
  ;

  py::class_<crad::ACTION_DATA_T>(m, "ACTION_DATA_T").def(py::init<>())
    .def_readwrite("type",                  &crad::ACTION_DATA_T::type)
    .def_readwrite("broadcastId",           &crad::ACTION_DATA_T::broadcastId)
    .def_readwrite("lat",                   &crad::ACTION_DATA_T::lat)
    .def_readwrite("lng",                   &crad::ACTION_DATA_T::lng)
    .def_readwrite("liveId",                &crad::ACTION_DATA_T::liveId)
    .def_readwrite("target",                &crad::ACTION_DATA_T::target)
    .def_readwrite("content",               &crad::ACTION_DATA_T::content)
  ;

  py::class_<crad::IPC_CATEGORY_QUERY_T>(m, "IPC_CATEGORY_QUERY_T").def(py::init<>())
    .def_readwrite("ipcCatPath",            &crad::IPC_CATEGORY_QUERY_T::ipcCatPath)
    .def_readwrite("sort",                  &crad::IPC_CATEGORY_QUERY_T::sort)
    .def_readwrite("limit",                 &crad::IPC_CATEGORY_QUERY_T::limit)
    .def_readwrite("cursor",                &crad::IPC_CATEGORY_QUERY_T::cursor)
  ;

  py::class_<crad::IPC_CONTENT_INFO_QUERY_T>(m, "IPC_CONTENT_INFO_QUERY_T").def(py::init<>())
    .def_readwrite("ipcContentId",          &crad::IPC_CONTENT_INFO_QUERY_T::ipcContentId)
    .def_readwrite("type",                  &crad::IPC_CONTENT_INFO_QUERY_T::type)
  ;

  py::class_<crad::IPC_CONTENT_QUERY_T>(m, "IPC_CONTENT_QUERY_T").def(py::init<>())
    .def_readwrite("ipcContentId",          &crad::IPC_CONTENT_QUERY_T::ipcContentId)
    .def_readwrite("limit",                 &crad::IPC_CONTENT_QUERY_T::limit)
    .def_readwrite("cursor",                &crad::IPC_CONTENT_QUERY_T::cursor)
  ;

  py::class_<crad::IPC_SEARCH_DATA_T>(m, "IPC_SEARCH_DATA_T").def(py::init<>())
    .def_readwrite("search",                &crad::IPC_SEARCH_DATA_T::search)
    .def_readwrite("type",                  &crad::IPC_SEARCH_DATA_T::type)
    .def_readwrite("limit",                 &crad::IPC_SEARCH_DATA_T::limit)
    .def_readwrite("cursor",                &crad::IPC_SEARCH_DATA_T::cursor)
    .def_readwrite("location",              &crad::IPC_SEARCH_DATA_T::location)
    .def_readwrite("priority",              &crad::IPC_SEARCH_DATA_T::priority)
    .def_readwrite("language",              &crad::IPC_SEARCH_DATA_T::language)
    .def_readwrite("country",               &crad::IPC_SEARCH_DATA_T::country)
  ;

  py::class_<crad::LE_SEARCH_DATA_T>(m, "LE_SEARCH_DATA_T").def(py::init<>())
    .def_readwrite("lat",                   &crad::LE_SEARCH_DATA_T::lat)
    .def_readwrite("lng",                   &crad::LE_SEARCH_DATA_T::lng)
    .def_readwrite("type",                  &crad::LE_SEARCH_DATA_T::type)
    .def_readwrite("artistName",            &crad::LE_SEARCH_DATA_T::artistName)
    .def_readwrite("genreId",               &crad::LE_SEARCH_DATA_T::genreId)
    .def_readwrite("range",                 &crad::LE_SEARCH_DATA_T::range)
    .def_readwrite("lang",                  &crad::LE_SEARCH_DATA_T::lang)
    .def_readwrite("dayLimit",              &crad::LE_SEARCH_DATA_T::dayLimit)
    .def_readwrite("compact",               &crad::LE_SEARCH_DATA_T::compact)
    .def_readwrite("limit",                 &crad::LE_SEARCH_DATA_T::limit)
    .def_readwrite("cursor",                &crad::LE_SEARCH_DATA_T::cursor)
    .def_readwrite("stripHTML",             &crad::LE_SEARCH_DATA_T::stripHTML)
    .def_readwrite("nonMusicResults",       &crad::LE_SEARCH_DATA_T::nonMusicResults)
  ;

  py::class_<crad::ACR_IDENTIFY_QUERY_DATA_T>(m, "ACR_IDENTIFY_QUERY_DATA_T").def(py::init<>())
    .def_readwrite("fingerprintBytes",      &crad::ACR_IDENTIFY_QUERY_DATA_T::fingerprintBytes)
    .def_readwrite("fingerprint",           &crad::ACR_IDENTIFY_QUERY_DATA_T::fingerprint)
    .def_readwrite("source",                &crad::ACR_IDENTIFY_QUERY_DATA_T::source)
    .def_readwrite("broadcastId",           &crad::ACR_IDENTIFY_QUERY_DATA_T::broadcastId)
    .def_readwrite("sampleOrigin",          &crad::ACR_IDENTIFY_QUERY_DATA_T::sampleOrigin)
  ;

  py::class_<crad::client::tuner::TUNER_REGISTER_INFO_T>(m, "TUNER_REGISTER_INFO_T").def(py::init<>())
    .def_readwrite("band",                  &crad::client::tuner::TUNER_REGISTER_INFO_T::band)
    .def_readwrite("freq_khz",              &crad::client::tuner::TUNER_REGISTER_INFO_T::freq_khz)
    .def_readwrite("channel_sid",           &crad::client::tuner::TUNER_REGISTER_INFO_T::channel_sid)
    .def_readwrite("is_digital",            &crad::client::tuner::TUNER_REGISTER_INFO_T::is_digital)
  ;

  py::class_<crad::client::tuner::FM_REGISTER_INFO_T>(m, "FM_REGISTER_INFO_T").def(py::init<>())
    .def_readwrite("pi_code",               &crad::client::tuner::FM_REGISTER_INFO_T::pi_code)
    .def_readwrite("callsign",              &crad::client::tuner::FM_REGISTER_INFO_T::callsign)
  ;

  py::class_<crad::client::tuner::HD_REGISTER_INFO_T>(m, "HD_REGISTER_INFO_T").def(py::init<>())
    .def_readwrite("ssn",                   &crad::client::tuner::HD_REGISTER_INFO_T::ssn)
    .def_readwrite("station_id",            &crad::client::tuner::HD_REGISTER_INFO_T::station_id)
    .def_readwrite("country_code",          &crad::client::tuner::HD_REGISTER_INFO_T::country_code)
    .def_readwrite("station_lat",           &crad::client::tuner::HD_REGISTER_INFO_T::station_lat)
    .def_readwrite("station_lon",           &crad::client::tuner::HD_REGISTER_INFO_T::station_lon)
    .def_readwrite("service_display_name",  &crad::client::tuner::HD_REGISTER_INFO_T::service_display_name)
  ;

  py::class_<crad::client::tuner::DAB_REGISTER_INFO_T>(m, "DAB_REGISTER_INFO_T").def(py::init<>())
    .def_readwrite("ens_id",                &crad::client::tuner::DAB_REGISTER_INFO_T::ens_id)
    .def_readwrite("service_id",            &crad::client::tuner::DAB_REGISTER_INFO_T::service_id)
    .def_readwrite("scids",                 &crad::client::tuner::DAB_REGISTER_INFO_T::scids)
    .def_readwrite("ecc",                   &crad::client::tuner::DAB_REGISTER_INFO_T::ecc)
    .def_readwrite("service_label",         &crad::client::tuner::DAB_REGISTER_INFO_T::service_label)
  ;

  py::class_<crad::client::tuner::PROGRAM_REGISTRATION_INFO_T>(m, "PROGRAM_REGISTRATION_INFO_T").def(py::init<>())
    .def_readwrite("verified",              &crad::client::tuner::PROGRAM_REGISTRATION_INFO_T::verified)
    .def_readwrite("tuner",                 &crad::client::tuner::PROGRAM_REGISTRATION_INFO_T::tuner)
    .def_readwrite("fm",                    &crad::client::tuner::PROGRAM_REGISTRATION_INFO_T::fm)
    .def_readwrite("hd",                    &crad::client::tuner::PROGRAM_REGISTRATION_INFO_T::hd)
    .def_readwrite("dab",                   &crad::client::tuner::PROGRAM_REGISTRATION_INFO_T::dab)
  ;

  py::class_<crad::client::tuner::PROGRAM_REGISTRATION_LIST_INFO_T>(m, "PROGRAM_REGISTRATION_LIST_INFO_T").def(py::init<>())
    .def_readwrite("list",                  &crad::client::tuner::PROGRAM_REGISTRATION_LIST_INFO_T::list)
  ;

  py::class_<crad::STREAMING_SERVICE_INFO_T>(m, "STREAMING_SERVICE_INFO_T").def(py::init<>())
    .def_readwrite("service_name",          &crad::STREAMING_SERVICE_INFO_T::service_name)
    .def_readwrite("station",               &crad::STREAMING_SERVICE_INFO_T::station)
    .def_readwrite("format",                &crad::STREAMING_SERVICE_INFO_T::format)
    .def_readwrite("bit_rate",              &crad::STREAMING_SERVICE_INFO_T::bit_rate)
    .def_readwrite("stream_url",            &crad::STREAMING_SERVICE_INFO_T::stream_url)
    .def_readwrite("broadcast_id",          &crad::STREAMING_SERVICE_INFO_T::broadcast_id)
    .def_readwrite("serv_follow",           &crad::STREAMING_SERVICE_INFO_T::serv_follow)
    .def_readwrite("duration",              &crad::STREAMING_SERVICE_INFO_T::duration)
    .def_readwrite("error_status_code",     &crad::STREAMING_SERVICE_INFO_T::error_status_code)
    .def_readwrite("location",              &crad::STREAMING_SERVICE_INFO_T::location)
  ;

  py::class_<crad::VOLUME_LEVEL_INFO_T>(m, "VOLUME_LEVEL_INFO_T").def(py::init<>())
    .def_readwrite("level",                 &crad::VOLUME_LEVEL_INFO_T::level)
  ;

  py::class_<crad::PRESET_INFO_T>(m, "PRESET_INFO_T").def(py::init<>())
    .def_readwrite("frequency_khz",         &crad::PRESET_INFO_T::frequency_khz)
    .def_readwrite("channel_sid",           &crad::PRESET_INFO_T::channel_sid)
    .def_readwrite("broadcast_id",          &crad::PRESET_INFO_T::broadcast_id)
  ;

  py::class_<crad::PRESET_STATIONS_INFO_T>(m, "PRESET_STATIONS_INFO_T").def(py::init<>())
    .def_readwrite("stations_list",         &crad::PRESET_STATIONS_INFO_T::stations_list)
  ;

  py::class_<crad::client::tuner::SIGNAL_DATA_T>(m, "SIGNAL_DATA_T").def(py::init<>())
    .def_readwrite("cdno",                  &crad::client::tuner::SIGNAL_DATA_T::cdno)
    .def_readwrite("rssi",                  &crad::client::tuner::SIGNAL_DATA_T::rssi)
    .def_readwrite("lat",                   &crad::client::tuner::SIGNAL_DATA_T::lat)
    .def_readwrite("lng",                   &crad::client::tuner::SIGNAL_DATA_T::lng)
  ;

  py::enum_<crad::eImageTypes>(m, "eImageTypes")
    .value("eImageTypeLogo",                crad::eImageTypes::eImageTypeLogo)
    .value("eImageTypeAlbum",               crad::eImageTypes::eImageTypeAlbum)
    .value("eImageTypeArtist",              crad::eImageTypes::eImageTypeArtist)
    .value("eImageTypeOther",               crad::eImageTypes::eImageTypeOther)
    .export_values();
  ;

  py::enum_<crad::eImageIdTypes>(m, "eImageIdTypes")
    .value("eImageIdTypeDefault",           crad::eImageIdTypes::eImageIdTypeDefault)
    .value("eImageIdTypeBroadcastId",       crad::eImageIdTypes::eImageIdTypeBroadcastId)
    .value("eImageIdTypeIpcContent",        crad::eImageIdTypes::eImageIdTypeIpcContent)
    .value("eImageIdTypeIpcCatPath",        crad::eImageIdTypes::eImageIdTypeIpcCatPath)
    .value("eImageIdTypeHdRadio",           crad::eImageIdTypes::eImageIdTypeHdRadio)
    .value("eImageIdTypeDab",               crad::eImageIdTypes::eImageIdTypeDab)
    .value("eImageIdTypeACR",               crad::eImageIdTypes::eImageIdTypeACR)
    .export_values();
  ;

  py::class_<crad::IMAGE_ID_T>(m, "IMAGE_ID_T").def(py::init<>())
    .def_readwrite("type",                  &crad::IMAGE_ID_T::type)
    .def_readwrite("id",                    &crad::IMAGE_ID_T::id)
  ;

  py::class_<crad::IMAGE_DATA_REQ_MODEL>(m, "IMAGE_DATA_REQ_MODEL").def(py::init<>())
    .def_readwrite("image_type",            &crad::IMAGE_DATA_REQ_MODEL::image_type)
    .def_readwrite("image_id",              &crad::IMAGE_DATA_REQ_MODEL::image_id)
    .def_readwrite("url",                   &crad::IMAGE_DATA_REQ_MODEL::url)
  ;

  py::class_<crad::IMAGES_DATA_REQ_LIST_T>(m, "IMAGES_DATA_REQ_LIST_T").def(py::init<>())
    .def_readwrite("imageDataList",         &crad::IMAGES_DATA_REQ_LIST_T::imageDataList)
  ;

  py::enum_<crad::IMAGE_MODE_T>(m, "IMAGE_MODE_T")
    .value("eImageModeNone",                crad::IMAGE_MODE_T::eImageModeNone)
    .value("eImageModeStandard",            crad::IMAGE_MODE_T::eImageModeStandard)
    .value("eImageModeHighRes",             crad::IMAGE_MODE_T::eImageModeHighRes)
    .export_values();
  ;

  py::class_<crad::IMAGE_SOURCE_DATA_T>(m, "IMAGE_SOURCE_DATA_T").def(py::init<>())
    .def_readwrite("image_id",              &crad::IMAGE_SOURCE_DATA_T::image_id)
    .def_readwrite("freqKHz",               &crad::IMAGE_SOURCE_DATA_T::freqKHz)
    .def_readwrite("channelSid",            &crad::IMAGE_SOURCE_DATA_T::channelSid)
  ;

  py::enum_<crad::CRAD_IMAGE_TYPE_T>(m, "CRAD_IMAGE_TYPE_T")
    .value("IMAGE_TYPE_UNKNOWN",            crad::CRAD_IMAGE_TYPE_T::IMAGE_TYPE_UNKNOWN)
    .value("IMAGE_TYPE_PNG",                crad::CRAD_IMAGE_TYPE_T::IMAGE_TYPE_PNG)
    .value("IMAGE_TYPE_JPG",                crad::CRAD_IMAGE_TYPE_T::IMAGE_TYPE_JPG)
    .export_values();
  ;

  py::class_<crad::CRAD_IMAGE_T>(m, "CRAD_IMAGE_T").def(py::init<>())
    .def_property_readonly("image_bytes",   &crad::CRAD_IMAGE_T::getBytes)
    .def_property_readonly("image_type",    &crad::CRAD_IMAGE_T::getImageType)
  ;

  py::class_<crad::IMAGE_INFO_DATA_T>(m, "IMAGE_INFO_DATA_T").def(py::init<>())
    .def_readwrite("type",                  &crad::IMAGE_INFO_DATA_T::type)
    .def_readwrite("image",                 &crad::IMAGE_INFO_DATA_T::image)
  ;

  py::class_<crad::IMAGES_LIST_T>(m, "IMAGES_LIST_T").def(py::init<>())
    .def_readwrite("source",                &crad::IMAGES_LIST_T::source)
    .def_readwrite("images_list",           &crad::IMAGES_LIST_T::images_list)
  ;

  py::class_<crad::BCAST_URL_MODEL_T>(m, "BCAST_URL_MODEL_T").def(py::init<>())
    .def_readwrite("website",               &crad::BCAST_URL_MODEL_T::website)
    .def_readwrite("facebook",              &crad::BCAST_URL_MODEL_T::facebook)
    .def_readwrite("twitter",               &crad::BCAST_URL_MODEL_T::twitter)
  ;

  py::class_<crad::BROADCAST_STREAM_DATA_T>(m, "BROADCAST_STREAM_DATA_T").def(py::init<>())
    .def_readwrite("url",                   &crad::BROADCAST_STREAM_DATA_T::url)
    .def_readwrite("format",                &crad::BROADCAST_STREAM_DATA_T::format)
    .def_readwrite("sampleRate",            &crad::BROADCAST_STREAM_DATA_T::sampleRate)
    .def_readwrite("bitrate",               &crad::BROADCAST_STREAM_DATA_T::bitrate)
    .def_readwrite("preroll",               &crad::BROADCAST_STREAM_DATA_T::preroll)
  ;

  py::class_<crad::BROADCAST_DATA_MODEL_T>(m, "BROADCAST_DATA_MODEL_T").def(py::init<>())
    .def_readwrite("name",                  &crad::BROADCAST_DATA_MODEL_T::name)
    .def_readwrite("slogan",                &crad::BROADCAST_DATA_MODEL_T::slogan)
    .def_readwrite("stationId",             &crad::BROADCAST_DATA_MODEL_T::stationId)
    .def_readwrite("contentId",             &crad::BROADCAST_DATA_MODEL_T::contentId)
    .def_readwrite("languages",             &crad::BROADCAST_DATA_MODEL_T::languages)
    .def_readwrite("callSign",              &crad::BROADCAST_DATA_MODEL_T::callSign)
    .def_readwrite("translator",            &crad::BROADCAST_DATA_MODEL_T::translator)
    .def_readwrite("enableThumbs",          &crad::BROADCAST_DATA_MODEL_T::enableThumbs)
    .def_readwrite("enableShare",           &crad::BROADCAST_DATA_MODEL_T::enableShare)
    .def_readwrite("format",                &crad::BROADCAST_DATA_MODEL_T::format)
    .def_readwrite("description",           &crad::BROADCAST_DATA_MODEL_T::description)
    .def_readwrite("longDescription",       &crad::BROADCAST_DATA_MODEL_T::longDescription)
    .def_readwrite("logoURL",               &crad::BROADCAST_DATA_MODEL_T::logoURL)
    .def_readwrite("logoURLHiRes",          &crad::BROADCAST_DATA_MODEL_T::logoURLHiRes)
    .def_readwrite("sfOnIconURL",           &crad::BROADCAST_DATA_MODEL_T::sfOnIconURL)
    .def_readwrite("sfOffIconURL",          &crad::BROADCAST_DATA_MODEL_T::sfOffIconURL)
    .def_readwrite("sfOnIconURLWide",       &crad::BROADCAST_DATA_MODEL_T::sfOnIconURLWide)
    .def_readwrite("sfOffIconURLWide",      &crad::BROADCAST_DATA_MODEL_T::sfOffIconURLWide)
    .def_readwrite("mqURI",                 &crad::BROADCAST_DATA_MODEL_T::mqURI)
    .def_readwrite("mqExchange",            &crad::BROADCAST_DATA_MODEL_T::mqExchange)
    .def_readwrite("mqKey",                 &crad::BROADCAST_DATA_MODEL_T::mqKey)
    .def_readwrite("sortKey",               &crad::BROADCAST_DATA_MODEL_T::sortKey)

    .def_readwrite("genreIds",              &crad::BROADCAST_DATA_MODEL_T::genreIds)
    .def_readwrite("hasLiveData",           &crad::BROADCAST_DATA_MODEL_T::hasLiveData)
    .def_readwrite("useLiveUnverified",     &crad::BROADCAST_DATA_MODEL_T::useLiveUnverified)
    .def_readwrite("email",                 &crad::BROADCAST_DATA_MODEL_T::email)
    .def_readwrite("urls",                  &crad::BROADCAST_DATA_MODEL_T::urls)
    .def_readwrite("phone",                 &crad::BROADCAST_DATA_MODEL_T::phone)
    .def_readwrite("sms",                   &crad::BROADCAST_DATA_MODEL_T::sms)
    .def_readwrite("streams",               &crad::BROADCAST_DATA_MODEL_T::streams)
  ;

  py::class_<crad::BROADCAST_MODEL_T>(m, "BROADCAST_MODEL_T").def(py::init<>())
    .def_readwrite("isAnalogValid",         &crad::BROADCAST_MODEL_T::isAnalogValid)
    .def_readwrite("isHDRadioValid",        &crad::BROADCAST_MODEL_T::isHDRadioValid)
    .def_readwrite("isDabValid",            &crad::BROADCAST_MODEL_T::isDabValid)

    .def_readwrite("broadcastId",           &crad::BROADCAST_MODEL_T::broadcastId)
    .def_readwrite("country",               &crad::BROADCAST_MODEL_T::country)
    .def_readwrite("freqKHz",               &crad::BROADCAST_MODEL_T::freqKHz)
    .def_readwrite("band",                  &crad::BROADCAST_MODEL_T::band)
    .def_readwrite("channel_sid",           &crad::BROADCAST_MODEL_T::channel_sid)

    .def_readwrite("dab_channel",           &crad::BROADCAST_MODEL_T::dab_channel)
    .def_readwrite("piCode",                &crad::BROADCAST_MODEL_T::piCode)
    .def_readwrite("ecc",                   &crad::BROADCAST_MODEL_T::ecc)
    .def_readwrite("stationId",             &crad::BROADCAST_MODEL_T::stationId)
    .def_readwrite("countryCode",           &crad::BROADCAST_MODEL_T::countryCode)
    .def_readwrite("location",              &crad::BROADCAST_MODEL_T::location)

    .def_readwrite("eid",                   &crad::BROADCAST_MODEL_T::eid)
    .def_readwrite("sid",                   &crad::BROADCAST_MODEL_T::sid)
    .def_readwrite("scids",                 &crad::BROADCAST_MODEL_T::scids)
    
    .def_readwrite("broadcastData",         &crad::BROADCAST_MODEL_T::broadcastData)
  ;

  py::class_<crad::CONRAD_BROADCAST_LIST_T>(m, "CONRAD_BROADCAST_LIST_T").def(py::init<>())
    .def_readwrite("broadcasts",            &crad::CONRAD_BROADCAST_LIST_T::broadcasts)
  ;

  py::class_<crad::IMAGE_DATA_T>(m, "IMAGE_DATA_T").def(py::init<>())
    .def_readwrite("type",                  &crad::IMAGE_DATA_T::type)
    .def_readwrite("isDefault",             &crad::IMAGE_DATA_T::isDefault)
    .def_readwrite("url",                   &crad::IMAGE_DATA_T::url)
    .def_readwrite("urlHiRes",              &crad::IMAGE_DATA_T::urlHiRes)
  ;

  py::class_<crad::MUSIC_DATA_T>(m, "MUSIC_DATA_T").def(py::init<>())
    .def_readwrite("title",                 &crad::MUSIC_DATA_T::title)
    .def_readwrite("album",                 &crad::MUSIC_DATA_T::album)
    .def_readwrite("artist",                &crad::MUSIC_DATA_T::artist)
    .def_readwrite("enableThumbs",          &crad::MUSIC_DATA_T::enableThumbs)
    .def_readwrite("enableShare",           &crad::MUSIC_DATA_T::enableShare)
    .def_readwrite("conradArtistId",        &crad::MUSIC_DATA_T::conradArtistId)
    .def_readwrite("conradTrackId",         &crad::MUSIC_DATA_T::conradTrackId)
    .def_readwrite("conradAlbumId",         &crad::MUSIC_DATA_T::conradAlbumId)
    .def_readwrite("images",                &crad::MUSIC_DATA_T::images)
    .def_readwrite("genreIds",              &crad::MUSIC_DATA_T::genreIds)
  ;

  py::class_<crad::NMP_DATA_T>(m, "NMP_DATA_T").def(py::init<>())
    .def_readwrite("title",                 &crad::NMP_DATA_T::title)
    .def_readwrite("program",               &crad::NMP_DATA_T::program)
    .def_readwrite("subject",               &crad::NMP_DATA_T::subject)
    .def_readwrite("enableThumbs",          &crad::NMP_DATA_T::enableThumbs)
    .def_readwrite("enableShare",           &crad::NMP_DATA_T::enableShare)
    .def_readwrite("conradArtistId",        &crad::NMP_DATA_T::conradArtistId)
    .def_readwrite("conradTrackId",         &crad::NMP_DATA_T::conradTrackId)
    .def_readwrite("images",                &crad::NMP_DATA_T::images)
  ;

  py::class_<crad::DATA_FIELD_T>(m, "DATA_FIELD_T").def(py::init<>())
    .def_readwrite("type",                  &crad::DATA_FIELD_T::type)
    .def_readwrite("target",                &crad::DATA_FIELD_T::target)
    .def_readwrite("content",               &crad::DATA_FIELD_T::content)
    .def_readwrite("text",                  &crad::DATA_FIELD_T::text)
  ;

  py::class_<crad::AD_DATA_T>(m, "AD_DATA_T").def(py::init<>())
    .def_readwrite("type",                  &crad::AD_DATA_T::type)
    .def_readwrite("data",                  &crad::AD_DATA_T::data)
  ;

  py::class_<crad::LIVE_DATA_T>(m, "LIVE_DATA_T").def(py::init<>())
    .def_readwrite("broadcastId",           &crad::LIVE_DATA_T::broadcastId)
    .def_readwrite("id",                    &crad::LIVE_DATA_T::id)
    .def_readwrite("type",                  &crad::LIVE_DATA_T::type)
    .def_readwrite("duration",              &crad::LIVE_DATA_T::duration)
    .def_readwrite("musicData",             &crad::LIVE_DATA_T::musicData)
    .def_readwrite("nmpData",               &crad::LIVE_DATA_T::nmpData)
    .def_readwrite("adData",                &crad::LIVE_DATA_T::adData)
  ;

  py::class_<crad::SUB_GENRE_DATA_T>(m, "SUB_GENRE_DATA_T").def(py::init<>())
    .def_readwrite("id",                    &crad::SUB_GENRE_DATA_T::id)
    .def_readwrite("name",                  &crad::SUB_GENRE_DATA_T::name)
  ;

  py::class_<crad::GENRE_DATA_T>(m, "GENRE_DATA_T").def(py::init<>())
    .def_readwrite("id",                    &crad::GENRE_DATA_T::id)
    .def_readwrite("name",                  &crad::GENRE_DATA_T::name)
    .def_readwrite("subGenres",             &crad::GENRE_DATA_T::subGenres)
  ;

  py::class_<crad::GENRE_LIST_T>(m, "GENRE_LIST_T").def(py::init<>())
    .def_readwrite("genres",                &crad::GENRE_LIST_T::genres)
  ;

  py::class_<crad::ACR_META_DATA_T>(m, "ACR_META_DATA_T").def(py::init<>())
    .def_readwrite("id",                    &crad::ACR_META_DATA_T::id)
    .def_readwrite("start_time",            &crad::ACR_META_DATA_T::start_time)
    .def_readwrite("play_offset_ms",        &crad::ACR_META_DATA_T::play_offset_ms)
    .def_readwrite("duration",              &crad::ACR_META_DATA_T::duration)
    .def_readwrite("source",                &crad::ACR_META_DATA_T::source)
    .def_readwrite("score",                 &crad::ACR_META_DATA_T::score)
    .def_readwrite("music_data",            &crad::ACR_META_DATA_T::music_data)
  ;

  py::class_<crad::CONFIG_DATA_T>(m, "CONFIG_DATA_T").def(py::init<>())
      .def_readwrite("image_mode",                 &crad::CONFIG_DATA_T::image_mode)
      .def_readwrite("db_path",                    &crad::CONFIG_DATA_T::db_path)
      .def_readwrite("disable_live_data_download", &crad::CONFIG_DATA_T::disable_live_data_download)
      ;

  py::class_<std::bitset<crad::kConfigDataChangeMaskSize>>(m, "bitset")
       .def(py::init<>())
       .def(py::init<unsigned long long>())
      ;
}

#endif  // CRAD_BOOST_PYTHON_CRAD_DATA_PYTHON_H_
