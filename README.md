# comedi-eeros
Wrapper library for [EEROS](https://github.com/eeros-project/eeros-framework) to interface with the [Comedi](http://comedi.org/) project. The Comedi project develops open-source drivers, tools, and libraries for data acquisition hardware.

## Documentation
- About Comedi: https://www.comedi.org/
- About the wrapper library: http://wiki.eeros.org/eeros_architecture/hal/hardware_libraries#comedi
- How to install: http://wiki.eeros.org/getting_started/install_wrapper#comedi

## Getting Started

The easiest way to get started using EEROS together with comedi is described in [Installation and Setup](https://wiki.eeros.org/getting_started/install_and_setup_development_environment) and more specifically in [Use with Comedi](https://wiki.eeros.org/getting_started/install_and_setup_development_environment/use_with_comedi).

The EEROS framework uses various [hardware libraries](http://wiki.eeros.org/eeros_architecture/hal/hardware_libraries) to access the underlying hardware. For the data acquisition boards, the [comedi library](https://www.comedi.org/) is used through this hardware wrapper library. 

The EEROS [Hardware Abstraction Layer](http://wiki.eeros.org/eeros_architecture/hal/start) needs a [configuration file](http://wiki.eeros.org/eeros_architecture/hal/configuration_file) which describes the hardware. A hardware configuration file describing some features in this hardware wrapper library can be found at (https://github.com/eeros-project/eeros-framework/tree/master/examples/hal). It is called *HalTest2ConfigComedi.json*.


## Projects using EEROS together with comedi

### Simple Motor Controller
The EEROS tutorial encompasses an application demonstrating the control of a simple motor, see [EEROS Tutorial: Control a Single Motor](https://wiki.eeros.org/getting_started/tutorials/oneaxis).


## How to contribute to comedi-eeros

The [EEROS Team](http://eeros.org/eeros-team/) would love to accept your contributions! The development on the EEROS Framework is done with the work flow “**develop with a fork**”. So please fork the repository, develop and test your code changes. For code quality, please follow the guidelines put together [here](http://wiki.eeros.org/for_developers/start). In general, the code should adheres to the existing style in the project. Once the changes are ready, a pull request is submitted. Each logical change should be submitted separately to ensure that the history will be understandable.

