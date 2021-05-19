#include <pybind11/pybind11.h>

#include "crad_data_python.h"
#include "crad_callback_data_python.h"
#include "crad_delegate_python.h"
#include "crad_delegate_impl_python.h"
#include "crad_api_python.h"

namespace py = pybind11;


void InitCradDataModule(py::module &m);
void InitCradCallbackDataModule(py::module &m);
void InitCradDelegateModule(py::module &m);
void InitCradDelegateImplModule(py::module &m);
void InitCradAPIModule(py::module &m);


PYBIND11_MODULE(cradpy, m) {
  m.doc() = "Connected Radio API Python Library";

  InitCradDataModule(m);
  InitCradCallbackDataModule(m);
  InitCradDelegateModule(m);
  InitCradDelegateImplModule(m);
  InitCradAPIModule(m);
}
