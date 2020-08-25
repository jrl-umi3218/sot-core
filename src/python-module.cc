#include "dynamic-graph/python/module.hh"

#include <sot/core/device.hh>

namespace dg = dynamicgraph;
namespace dgs = dynamicgraph::sot;

typedef bp::return_value_policy<bp::reference_existing_object> reference_existing_object;

BOOST_PYTHON_MODULE(wrap)
{
  bp::import("dynamic_graph");

  using dgs::PeriodicCall;
  bp::class_<PeriodicCall, boost::noncopyable>("PeriodicCall", bp::no_init)
    .def("addSignal", static_cast<void (PeriodicCall::*)(const std::string &, dg::SignalBase<int> &)> (&PeriodicCall::addSignal),
        "Add the signal to the refresh list", (bp::arg("name"), "signal"))
    .def("addSignal", static_cast<void (PeriodicCall::*)(const std::string &)> (&PeriodicCall::addSignal),
        "Add the signal to the refresh list", (bp::arg("signal_name")))

    .def("addDownsampledSignal", static_cast<void (PeriodicCall::*)(const std::string &, dg::SignalBase<int> &, const unsigned int &)> (&PeriodicCall::addDownsampledSignal),
        "Add the signal to the refresh list\n"
        "The downsampling factor: 1 means every time, "
        "2 means every other time, etc...",
        (bp::arg("name"), "signal", "factor"))
    .def("addDownsampledSignal", static_cast<void (PeriodicCall::*)(const std::string &, const unsigned int &)> (&PeriodicCall::addDownsampledSignal),
        "Add the signal to the refresh list\n"
        "The downsampling factor: 1 means every time, "
        "2 means every other time, etc...",
        (bp::arg("signal_name"), "factor"))

    .def("rmSignal", &PeriodicCall::rmSignal, "Remove the signal to the refresh list", bp::arg("name"))
    .def("clear", &PeriodicCall::clear, "Clear all signals and commands from the refresh list.")
    .def("__str__", +[](const PeriodicCall& e) {
          std::ostringstream os;
          e.display(os);
          return os.str();
        })
    ;

  dynamicgraph::python::exposeEntity<dgs::Device>()
    .add_property("after", 
        bp::make_function(&dgs::Device::periodicCallAfter, reference_existing_object()))
    .def_readonly("before", 
        bp::make_function(&dgs::Device::periodicCallBefore, reference_existing_object()))
    ;
}