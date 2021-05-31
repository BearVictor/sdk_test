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
 * @file        crad_delegate_python.h
 *
 * @brief       Defines ConnectedRadioDelegate for use in the Boost Python lib wrapper
 * @date        January 4, 2021
 */

#ifndef CRAD_BOOST_PYTHON_CRAD_DELEGATE_PYTHON_H_
#define CRAD_BOOST_PYTHON_CRAD_DELEGATE_PYTHON_H_

#include <pybind11/pybind11.h>

#include <crad/crad_delegate.h>
#include <iostream>
namespace py = pybind11;

using crad::ConnectedRadioDelegate;


struct ConnectedRadioDelegateWrap : public crad::ConnectedRadioDelegate {

  void OnRegisterDeviceAvailable (const crad::MFG_INFO_T& info) override { 
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnRegisterDeviceAvailable, info);
  }
  
  void OnConfigDataAvailable (const crad::MFG_INFO_T& info) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnConfigDataAvailable, info);
  }
  
  void OnBroadcastsAvailable (const crad::CONRAD_BROADCAST_LIST_T& broadcasts) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnBroadcastsAvailable, broadcasts); 
  }
  
  void OnBroadcastDataAvailable (const crad::BROADCAST_MODEL_T &broadcast) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnBroadcastDataAvailable, broadcast); 
  }
  
  void OnLiveDataAvailable (const crad::LIVE_DATA_T &live_data) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnLiveDataAvailable, live_data); 
  }
  
  void OnGenresAvailable (const crad::GENRE_LIST_T& genres) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnGenresAvailable, genres);
  }
  
  void OnIpcCategoriesAvailable (const STRING &ipc_cat_path, const STRING& categories_str) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnIpcCategoriesAvailable, ipc_cat_path, categories_str); 
  }
  
  void OnIpcContentInfoAvailable (const STRING &ipc_content_id, const STRING& response_str) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnIpcContentInfoAvailable, ipc_content_id, response_str); 
  }
  
  void OnIpcContentPlayInfoAvailable (const STRING &ipc_playback_id, const STRING& response_str) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnIpcContentPlayInfoAvailable, ipc_playback_id, response_str); 
  }
  
  void OnIpcSimilarContentAvailable (const STRING &ipc_content_id, const STRING& response_str) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnIpcSimilarContentAvailable, ipc_content_id, response_str); 
  }
  
  void OnIpcSearchContentAvailable (const STRING &search_query, const STRING& response_str) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnIpcSearchContentAvailable, search_query, response_str); 
  }
  
  void OnIpcPodcastEpisodesAvailable (const STRING &ipc_content_id, const STRING& response_str) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnIpcPodcastEpisodesAvailable, ipc_content_id, response_str); 
  }
  
  void OnIpcPodcastLatestEpisodeAvailable (const STRING &ipc_content_id, const STRING& response_str) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnIpcPodcastLatestEpisodeAvailable, ipc_content_id, response_str); 
  }
  
  void OnLeEventInfoAvailable (const STRING &le_event_id, const STRING& response_str) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnLeEventInfoAvailable, le_event_id, response_str); 
  }
  
  void OnLeEventsAvailable (const STRING &artist_name, const crad::UINT8 genre_id, const STRING& response_str)  {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnLeEventsAvailable, artist_name, genre_id, response_str); 
  }
  
  void OnImagesAvailable (const crad::IMAGES_LIST_T &images) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnImagesAvailable, images); 
  }
  
  void OnMessageCodeAvailable (const crad::CRAD_MESSAGE_CODES_T &code) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnMessageCodeAvailable, code); 
  }
  
  void OnLocationInfoRequested () override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnLocationInfoRequested); 
  }
  
  void OnAcrFingerprintIdentified (const crad::ACR_META_DATA_T &acr_metadata) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnAcrFingerprintIdentified, acr_metadata); 
  }

  void OnConfigSettingsChange (const std::bitset<crad::kConfigDataChangeMaskSize> &change_mask, const crad::CONFIG_DATA_T& config) override {
    PYBIND11_OVERRIDE_PURE(void, ConnectedRadioDelegate, OnConfigSettingsChange, change_mask, config);
  }
};


void InitCradDelegateModule(py::module &m) {
  py::class_<crad::ConnectedRadioDelegate, ConnectedRadioDelegateWrap>(m, "ConnectedRadioDelegate").def(py::init<>())
    .def("OnRegisterDeviceAvailable",           &crad::ConnectedRadioDelegate::OnRegisterDeviceAvailable)
    .def("OnConfigDataAvailable",               &crad::ConnectedRadioDelegate::OnConfigDataAvailable)
    .def("OnBroadcastsAvailable",               &crad::ConnectedRadioDelegate::OnBroadcastsAvailable)
    .def("OnBroadcastDataAvailable",            &crad::ConnectedRadioDelegate::OnBroadcastDataAvailable)
    .def("OnLiveDataAvailable",                 &crad::ConnectedRadioDelegate::OnLiveDataAvailable)
    .def("OnGenresAvailable",                   &crad::ConnectedRadioDelegate::OnGenresAvailable)
    .def("OnIpcCategoriesAvailable",            &crad::ConnectedRadioDelegate::OnIpcCategoriesAvailable)
    .def("OnIpcContentInfoAvailable",           &crad::ConnectedRadioDelegate::OnIpcContentInfoAvailable)
    .def("OnIpcContentPlayInfoAvailable",       &crad::ConnectedRadioDelegate::OnIpcContentPlayInfoAvailable)
    .def("OnIpcSimilarContentAvailable",        &crad::ConnectedRadioDelegate::OnIpcSimilarContentAvailable)
    .def("OnIpcSearchContentAvailable",         &crad::ConnectedRadioDelegate::OnIpcSearchContentAvailable)
    .def("OnIpcPodcastEpisodesAvailable",       &crad::ConnectedRadioDelegate::OnIpcPodcastEpisodesAvailable)
    .def("OnIpcPodcastLatestEpisodeAvailable",  &crad::ConnectedRadioDelegate::OnIpcPodcastLatestEpisodeAvailable)
    .def("OnLeEventInfoAvailable",              &crad::ConnectedRadioDelegate::OnLeEventInfoAvailable)
    .def("OnLeEventsAvailable",                 &crad::ConnectedRadioDelegate::OnLeEventsAvailable)
    .def("OnImagesAvailable",                   &crad::ConnectedRadioDelegate::OnImagesAvailable)
    .def("OnMessageCodeAvailable",              &crad::ConnectedRadioDelegate::OnMessageCodeAvailable)
    .def("OnLocationInfoRequested",             &crad::ConnectedRadioDelegate::OnLocationInfoRequested)
    .def("OnAcrFingerprintIdentified",          &crad::ConnectedRadioDelegate::OnAcrFingerprintIdentified)
    .def("OnConfigSettingsChange",              &crad::ConnectedRadioDelegate::OnConfigSettingsChange)
    ;
}


#endif  // CRAD_BOOST_PYTHON_CRAD_DELEGATE_PYTHON_H_
