=====================================
Symbols From Another External Module
=====================================

Sometimes, an external module uses exported symbols from another external module.

kbuild needs  to have full knowledge of all symbols to avoid spitting out warnings about undefined 	symbols.

When an external module is built, a Module.symvers file is generated containing all exported symbols which are not defined in the kernel.

Use KBUILD_EXTRA_SYMBOLS and provide it the path of the Module.symvers file if it is present in some other directory other than the module directory.

https://stackoverflow.com/questions/16360689/invalid-parameters-error-when-trying-to-insert-module-that-accesses-exported-s

