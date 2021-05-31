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
 * @file        crad_delegate_impl_python.h
 *
 * @brief       Defines ConnectedRadioDelegate for use in the Boost Python lib wrapper
 * @date        January 4, 2021
 */

#ifndef CRAD_BOOST_PYTHON_CRAD_DELEGATE_IMPL_PYTHON_H_
#define CRAD_BOOST_PYTHON_CRAD_DELEGATE_IMPL_PYTHON_H_

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "crad_delegate_impl.h"

namespace py = pybind11;


void InitCradDelegateImplModule(py::module &m) {
  py::class_<ConnectedRadioDelegateImpl>(m, "ConnectedRadioDelegateImpl")
    .def(py::init<>())
    .def("OnRegisterDeviceAvailable",           &ConnectedRadioDelegateImpl::OnRegisterDeviceAvailable)
    .def("OnConfigDataAvailable",               &ConnectedRadioDelegateImpl::OnConfigDataAvailable) 
    .def("OnBroadcastsAvailable",               &ConnectedRadioDelegateImpl::OnBroadcastsAvailable) 
    .def("OnBroadcastDataAvailable",            &ConnectedRadioDelegateImpl::OnBroadcastDataAvailable) 
    .def("OnLiveDataAvailable",                 &ConnectedRadioDelegateImpl::OnLiveDataAvailable) 
    .def("OnGenresAvailable",                   &ConnectedRadioDelegateImpl::OnGenresAvailable) 
    .def("OnIpcCategoriesAvailable",            &ConnectedRadioDelegateImpl::OnIpcCategoriesAvailable) 
    .def("OnIpcContentInfoAvailable",           &ConnectedRadioDelegateImpl::OnIpcContentInfoAvailable) 
    .def("OnIpcContentPlayInfoAvailable",       &ConnectedRadioDelegateImpl::OnIpcContentPlayInfoAvailable) 
    .def("OnIpcSimilarContentAvailable",        &ConnectedRadioDelegateImpl::OnIpcSimilarContentAvailable) 
    .def("OnIpcSearchContentAvailable",         &ConnectedRadioDelegateImpl::OnIpcSearchContentAvailable) 
    .def("OnIpcPodcastEpisodesAvailable",       &ConnectedRadioDelegateImpl::OnIpcPodcastEpisodesAvailable) 
    .def("OnIpcPodcastLatestEpisodeAvailable",  &ConnectedRadioDelegateImpl::OnIpcPodcastLatestEpisodeAvailable)
    .def("OnLeEventInfoAvailable",              &ConnectedRadioDelegateImpl::OnLeEventInfoAvailable) 
    .def("OnLeEventsAvailable",                 &ConnectedRadioDelegateImpl::OnLeEventsAvailable) 
    .def("OnImagesAvailable",                   &ConnectedRadioDelegateImpl::OnImagesAvailable) 
    .def("OnMessageCodeAvailable",              &ConnectedRadioDelegateImpl::OnMessageCodeAvailable) 
    .def("OnLocationInfoRequested",             &ConnectedRadioDelegateImpl::OnLocationInfoRequested) 
    .def("OnAcrFingerprintIdentified",          &ConnectedRadioDelegateImpl::OnAcrFingerprintIdentified)
    .def("OnConfigSettingsChange",              &ConnectedRadioDelegateImpl::OnConfigSettingsChange)
    
    .def_readwrite("RegisterDeviceAvailable",           &ConnectedRadioDelegateImpl::m_register_device_available)
    .def_readwrite("ConfigDataAvailable",               &ConnectedRadioDelegateImpl::m_config_data_available)
    .def_readwrite("BroadcastsAvailable",               &ConnectedRadioDelegateImpl::m_broadcasts_available)
    .def_readwrite("BroadcastDataAvailable",            &ConnectedRadioDelegateImpl::m_broadcast_data_available)
    .def_readwrite("LiveDataAvailable",                 &ConnectedRadioDelegateImpl::m_live_data_available)
    .def_readwrite("GenresAvailable",                   &ConnectedRadioDelegateImpl::m_genres_available)
    .def_readwrite("IpcCategoriesAvailable",            &ConnectedRadioDelegateImpl::m_ipc_categories_available)
    .def_readwrite("IpcContentInfoAvailable",           &ConnectedRadioDelegateImpl::m_ipc_content_info_available)
    .def_readwrite("IpcContentPlayInfoAvailable",       &ConnectedRadioDelegateImpl::m_ipc_content_play_info_available)
    .def_readwrite("IpcSimilarContentAvailable",        &ConnectedRadioDelegateImpl::m_ipc_similar_content_available)
    .def_readwrite("IpcSearchContentAvailable",         &ConnectedRadioDelegateImpl::m_ipc_search_content_available)
    .def_readwrite("IpcPodcastEpisodesAvailable",       &ConnectedRadioDelegateImpl::m_ipc_podcast_episodes_available)
    .def_readwrite("IpcPodcastLatestEpisodeAvailable",  &ConnectedRadioDelegateImpl::m_ipc_podcast_latest_episode_available)
    .def_readwrite("LeEventInfoAvailable",              &ConnectedRadioDelegateImpl::m_le_event_info_available)
    .def_readwrite("LeEventsAvailable",                 &ConnectedRadioDelegateImpl::m_le_events_available)
    .def_readwrite("ImagesAvailable",                   &ConnectedRadioDelegateImpl::m_images_available)
    .def_readwrite("MessageCodeAvailable",              &ConnectedRadioDelegateImpl::m_message_code_available)
    .def_readwrite("LocationInfoRequested",             &ConnectedRadioDelegateImpl::m_location_info_requested)
    .def_readwrite("AcrFingerprintIdentified",          &ConnectedRadioDelegateImpl::m_acr_fingerprint_identified)
    .def_readwrite("ConfigSettingsChange",              &ConnectedRadioDelegateImpl::m_config_data_changed)

    .def_readwrite("CallbacksList",      &ConnectedRadioDelegateImpl::m_last_callbacks)
    
    .def("RestartCallbackCounter", &ConnectedRadioDelegateImpl::RestartCallbackCounter)
    .def("ClearCallbacksList",     &ConnectedRadioDelegateImpl::ClearCallbacksList)
  ;
}


#endif  // CRAD_BOOST_PYTHON_CRAD_DELEGATE_IMPL_PYTHON_H_
