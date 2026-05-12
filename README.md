# comedi-eeros
The [EEROS Robotics Framework](https://github.com/eeros-project/eeros-framework) uses various [hardware libraries](http://wiki.eeros.org/eeros_architecture/hal/hardware_libraries) to access the underlying hardware. This wrapper library enables the usage of the [Comedi](http://comedi.org/) project. The Comedi project develops open-source drivers, tools, and libraries for data acquisition hardware.

## Documentation
- About Comedi: https://www.comedi.org/
- About the wrapper library: http://wiki.eeros.org/eeros_architecture/hal/hardware_libraries#comedi
- How to install: http://wiki.eeros.org/getting_started/install_wrapper#comedi

## Getting Started
Check the following examples for the use of the wrapper library.
- [EEROS Tutorial: Control a Single Motor](https://wiki.eeros.org/getting_started/tutorials/oneaxis_comedi).

The EEROS [Hardware Abstraction Layer](http://wiki.eeros.org/eeros_architecture/hal/start) needs a [configuration file](http://wiki.eeros.org/eeros_architecture/hal/configuration_file) which describes the hardware. A sample hardware configuration file for this wrapper library can be found at
https://github.com/eeros-project/eeros-framework/blob/master/examples/hal/HalTest2ConfigComedi.json.


## How to contribute

The EEROS team would love to accept your contributions! The development on the EEROS Framework is done with the work flow “**develop with a fork**”. So please fork the repository, develop and test your code changes. For code quality, please follow the guidelines put together [here](http://wiki.eeros.org/for_developers/start). In general, the code should adheres to the existing style in the project. Once the changes are ready, a pull request is submitted. Each logical change should be submitted separately to ensure that the history will be understandable.
