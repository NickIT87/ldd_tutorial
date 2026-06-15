G if all modules loaded have a GPL or compatible license, P if any proprietary module has been loaded. Modules without a MODULE_LICENSE or with a MODULE_LICENSE that is not recognised by insmod as GPL compatible are assumed to be proprietary.
F if any module was force loaded by insmod -f, ' ' if all modules were loaded normally.
S if the oops occurred on an SMP kernel running on hardware that hasn't been certified as safe to run multiprocessor. Currently this occurs only on various Athlons that are not SMP capable.
R if a module was force unloaded by rmmod -f, ' ' if all modules were unloaded normally.
M if any processor has reported a Machine Check Exception, ' ' if no Machine Check Exceptions have occurred.
B If a page-release function has found a bad page reference or some unexpected page flags. This indicates a hardware problem or a kernel bug; there should be other information in the log indicating why this tainting occured.
U if a user or user application specifically requested that the Tainted flag be set, ' ' otherwise.
D if the kernel has died recently, i.e. there was an OOPS or BUG.
A if an ACPI table has been overridden.
W if a warning has previously been issued by the kernel. (Though some warnings may set more specific taint flags.)
C if a staging driver has been loaded.
I if the kernel is working around a severe bug in the platform firmware (BIOS or similar).
O if an externally-built ("out-of-tree") module has been loaded.
E if an unsigned module has been loaded in a kernel supporting module signature.
L if a soft lockup has previously occurred on the system.
K if the kernel has been live patched.
X Auxiliary taint, defined for and used by Linux distributors.
T Kernel was build with the randstruct plugin, which can intentionally produce extremely unusual kernel structure layouts (even performance pathological ones), which is important to know when debugging. Set at build time.
