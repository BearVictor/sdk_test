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
 * @file        crad_api_python.h
 *
 * @brief       Defines ConnectedRadioAPI for use in the Boost Python lib wrapper
 * @date        January 12, 2021
 */

#ifndef CRAD_BOOST_PYTHON_CRAD_PYTHON_H_
#define CRAD_BOOST_PYTHON_CRAD_PYTHON_H_

#include <pybind11/pybind11.h>

#include <crad/crad_api.h>
#include "crad_delegate_python.h"
#include "crad_delegate_impl_python.h"

namespace py = pybind11;
using crad::ConnectedRadioAPI;


void InitCradAPIModule(py::module &m) {
  py::class_<crad::ConnectedRadioAPI>(m, "ConnectedRadioAPI")
    .def(py::init<crad::ConnectedRadioDelegate *>())
    .def(py::init<ConnectedRadioDelegateImpl *>())
    .def("GetVersion",                  [](crad::ConnectedRadioAPI* this_api, string& str) {
                                            crad::CRAD_ERR_T res = this_api->GetVersion(str);
                                            return std::make_tuple(res, str);
                                        })
    .def("Start",                       &crad::ConnectedRadioAPI::Start)
    .def("Stop",                        &crad::ConnectedRadioAPI::Stop)
    .def("RegisterDevice",              &crad::ConnectedRadioAPI::RegisterDevice)
    .def("GetBroadcastData",            &crad::ConnectedRadioAPI::GetBroadcastData)
    .def("GetBroadcastList",            &crad::ConnectedRadioAPI::GetBroadcastList)
    .def("GetLiveData",                 &crad::ConnectedRadioAPI::GetLiveData)
    .def("GetGenres",                   &crad::ConnectedRadioAPI::GetGenres)
    .def("RegisterProgramInfo",         &crad::ConnectedRadioAPI::RegisterProgramInfo)
    .def("RegisterProgramList",         &crad::ConnectedRadioAPI::RegisterProgramList)
    .def("RegisterLocationInfo",        &crad::ConnectedRadioAPI::RegisterLocationInfo)
    .def("RegisterStreamInfo",          &crad::ConnectedRadioAPI::RegisterStreamInfo)
    .def("RegisterVolumeEvent",         &crad::ConnectedRadioAPI::RegisterVolumeEvent)
    .def("RegisterPresets",             &crad::ConnectedRadioAPI::RegisterPresets)
    .def("RegisterSignalStrength",      &crad::ConnectedRadioAPI::RegisterSignalStrength)
    .def("IdentifyAcrFingerprint",      &crad::ConnectedRadioAPI::IdentifyAcrFingerprint)
    .def("ReportAction",                &crad::ConnectedRadioAPI::ReportAction)
    .def("GetIpcCategories",            &crad::ConnectedRadioAPI::GetIpcCategories)
    .def("GetIpcContent",               &crad::ConnectedRadioAPI::GetIpcContent)
    .def("GetIpcSimilarContent",        &crad::ConnectedRadioAPI::GetIpcSimilarContent)
    .def("SearchIpcContent",            &crad::ConnectedRadioAPI::SearchIpcContent)
    .def("GetIpcContentPlayInfo",       &crad::ConnectedRadioAPI::GetIpcContentPlayInfo)
    .def("GetIpcPodcastEpisodes",       &crad::ConnectedRadioAPI::GetIpcPodcastEpisodes)
    .def("GetIpcPodcastLatestEpisode",  &crad::ConnectedRadioAPI::GetIpcPodcastLatestEpisode)
    .def("GetLocalEventData",           &crad::ConnectedRadioAPI::GetLocalEventData)
    .def("SearchLocalEvents",           &crad::ConnectedRadioAPI::SearchLocalEvents)
    .def("GetImages",                   &crad::ConnectedRadioAPI::GetImages)
#ifndef DEPRECATED_MARKED_FOR_REMOVAL_VER_3_2_0
    .def("SetImageMode",                &crad::ConnectedRadioAPI::SetImageMode)
    .def("GetImageMode",                &crad::ConnectedRadioAPI::GetImageMode)
#endif
    .def("SetConfig",                   &crad::ConnectedRadioAPI::SetConfig)
    .def("GetConfig",                   [](crad::ConnectedRadioAPI* this_api, crad::CONFIG_DATA_T& config) {
                                            crad::CRAD_ERR_T res = this_api->GetConfig(config);
                                            return std::make_tuple(res, config);
                                        })
    .def("FactoryReset",                &crad::ConnectedRadioAPI::FactoryReset)
  ;
}


#endif  // CRAD_BOOST_PYTHON_CRAD_PYTHON_H_