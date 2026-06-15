An ELF object file consists of various named sections

Some of them are basic parts of an object file, for example the .text section contains executable code that a loader loads.

To see all the sections

$ objdump --section-headers ./mod_info.ko

To see the contents of the .modinfo section:


$ objdump --section-headers --section=.modinfo --full-contents ./mod_info.ko




