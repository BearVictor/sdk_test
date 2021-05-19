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
 * @file        crad_callback_data_python.h
 *
 * @brief       Defines data structures received by the ConnectedRadio's callbacks 
 *              for the pybind11 wrapper
 * @date        February 2, 2021
 */

#ifndef CRAD_PYTHON_CRAD_CALLBACK_DATA_PYTHON_H_
#define CRAD_PYTHON_CRAD_CALLBACK_DATA_PYTHON_H_

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <crad/crad_data.h>
#include <crad/crad_tuner_registration_data.h>

#include "crad_callback_data.h"

namespace py = pybind11;


void InitCradCallbackDataModule(py::module &m) {
  py::class_<RegisterDeviceAvailableCallbackData>(m, "Register  DeviceAvailableCallbackData").def(py::init<>())
    .def_readwrite("info",                  &RegisterDeviceAvailableCallbackData::info)
    .def_readwrite("counter",               &RegisterDeviceAvailableCallbackData::counter)
  ;

  py::class_<ConfigDataAvailableCallbackData>(m, "ConfigDataAvailableCallbackData").def(py::init<>())
    .def_readwrite("info",                  &ConfigDataAvailableCallbackData::info)
    .def_readwrite("counter",               &ConfigDataAvailableCallbackData::counter)
  ;

  py::class_<BroadcastsAvailableCallbackData>(m, "BroadcastsAvailableCallbackData").def(py::init<>())
    .def_readwrite("broadcasts",            &BroadcastsAvailableCallbackData::broadcasts)
    .def_readwrite("counter",               &BroadcastsAvailableCallbackData::counter)
  ;

  py::class_<BroadcastDataAvailableCallbackData>(m, "BroadcastDataAvailableCallbackData").def(py::init<>())
    .def_readwrite("broadcast_info",        &BroadcastDataAvailableCallbackData::broadcast_info)
    .def_readwrite("counter",               &BroadcastDataAvailableCallbackData::counter)
  ;

  py::class_<LiveDataAvailableCallbackData>(m, "LiveDataAvailableCallbackData").def(py::init<>())
    .def_readwrite("live_data",             &LiveDataAvailableCallbackData::live_data)
    .def_readwrite("counter",               &LiveDataAvailableCallbackData::counter)
  ;

  py::class_<GenresAvailableCallbackData>(m, "GenresAvailableCallbackData").def(py::init<>())
    .def_readwrite("genres",                &GenresAvailableCallbackData::genres)
    .def_readwrite("counter",               &GenresAvailableCallbackData::counter)
  ;

  py::class_<IpcCategoriesAvailableCallbackData>(m, "IpcCategoriesAvailableCallbackData").def(py::init<>())
    .def_readwrite("ipc_cat_path",          &IpcCategoriesAvailableCallbackData::ipc_cat_path)
    .def_readwrite("categories_str",        &IpcCategoriesAvailableCallbackData::categories_str)
    .def_readwrite("counter",               &IpcCategoriesAvailableCallbackData::counter)
  ;

  py::class_<IpcContentInfoAvailableCallbackData>(m, "IpcContentInfoAvailableCallbackData").def(py::init<>())
    .def_readwrite("ipc_content_id",        &IpcContentInfoAvailableCallbackData::ipc_content_id)
    .def_readwrite("response_str",          &IpcContentInfoAvailableCallbackData::response_str)
    .def_readwrite("counter",               &IpcContentInfoAvailableCallbackData::counter)
  ;

  py::class_<IpcContentPlayInfoAvailableCallbackData>(m, "IpcContentPlayInfoAvailableCallbackData").def(py::init<>())
    .def_readwrite("ipc_playback_id",       &IpcContentPlayInfoAvailableCallbackData::ipc_playback_id)
    .def_readwrite("response_str",          &IpcContentPlayInfoAvailableCallbackData::response_str)
    .def_readwrite("counter",               &IpcContentPlayInfoAvailableCallbackData::counter)
  ;

  py::class_<IpcSimilarContentAvailableCallbackData>(m, "IpcSimilarContentAvailableCallbackData").def(py::init<>())
    .def_readwrite("ipc_content_id",        &IpcSimilarContentAvailableCallbackData::ipc_content_id)
    .def_readwrite("response_str",          &IpcSimilarContentAvailableCallbackData::response_str)
    .def_readwrite("counter",               &IpcSimilarContentAvailableCallbackData::counter)
  ;

  py::class_<IpcSearchContentAvailableCallbackData>(m, "IpcSearchContentAvailableCallbackData").def(py::init<>())
    .def_readwrite("search_query",          &IpcSearchContentAvailableCallbackData::search_query)
    .def_readwrite("response_str",          &IpcSearchContentAvailableCallbackData::response_str)
    .def_readwrite("counter",               &IpcSearchContentAvailableCallbackData::counter)
  ;

  py::class_<IpcPodcastEpisodesAvailableCallbackData>(m, "IpcPodcastEpisodesAvailableCallbackData").def(py::init<>())
    .def_readwrite("ipc_content_id",        &IpcPodcastEpisodesAvailableCallbackData::ipc_content_id)
    .def_readwrite("response_str",          &IpcPodcastEpisodesAvailableCallbackData::response_str)
    .def_readwrite("counter",               &IpcPodcastEpisodesAvailableCallbackData::counter)
  ;

  py::class_<IpcPodcastLatestEpisodeAvailableCallbackData>(m, "IpcPodcastLatestEpisodeAvailableCallbackData").def(py::init<>())
    .def_readwrite("ipc_content_id",        &IpcPodcastLatestEpisodeAvailableCallbackData::ipc_content_id)
    .def_readwrite("response_str",          &IpcPodcastLatestEpisodeAvailableCallbackData::response_str)
    .def_readwrite("counter",               &IpcPodcastLatestEpisodeAvailableCallbackData::counter)
  ;

  py::class_<LeEventInfoAvailableCallbackData>(m, "LeEventInfoAvailableCallbackData").def(py::init<>())
    .def_readwrite("le_event_id",           &LeEventInfoAvailableCallbackData::le_event_id)
    .def_readwrite("response_str",          &LeEventInfoAvailableCallbackData::response_str)
    .def_readwrite("counter",               &LeEventInfoAvailableCallbackData::counter)
  ;

  py::class_<LeEventsAvailableCallbackData>(m, "LeEventsAvailableCallbackData").def(py::init<>())
    .def_readwrite("artist_name",           &LeEventsAvailableCallbackData::artist_name)
    .def_readwrite("genre_id",              &LeEventsAvailableCallbackData::genre_id)
    .def_readwrite("response_str",          &LeEventsAvailableCallbackData::response_str)
    .def_readwrite("counter",               &LeEventsAvailableCallbackData::counter)
  ;

  py::class_<ImagesAvailableCallbackData>(m, "ImagesAvailableCallbackData").def(py::init<>())
    .def_readwrite("images",                &ImagesAvailableCallbackData::images)
    .def_readwrite("counter",               &ImagesAvailableCallbackData::counter)
  ;

  py::class_<MessageCodeAvailableCallbackData>(m, "MessageCodeAvailableCallbackData").def(py::init<>())
    .def_readwrite("code",                  &MessageCodeAvailableCallbackData::code)
    .def_readwrite("counter",               &MessageCodeAvailableCallbackData::counter)
  ;

  py::class_<LocationInfoRequestedCallbackData>(m, "LocationInfoRequestedCallbackData").def(py::init<>())
    .def_readwrite("counter",               &LocationInfoRequestedCallbackData::counter)
  ;

  py::class_<AcrFingerprintIdentifiedCallbackData>(m, "AcrFingerprintIdentifiedCallbackData").def(py::init<>())
    .def_readwrite("acr_metadata",          &AcrFingerprintIdentifiedCallbackData::acr_metadata)
    .def_readwrite("counter",               &AcrFingerprintIdentifiedCallbackData::counter)
  ;
}


#endif  // CRAD_PYTHON_CRAD_CALLBACK_DATA_PYTHON_H_

