Process Memory Map
=====================

struct mm_struct - contains list of process VMAs, page tables, etc.

All information related to the process address space is included in an object called the memory descriptor of type mm_struct

accessible via current-> mm


struct mm_struct {
	/* Pointer to the head of the list of memory region objects */
	struct vm_area_struct * mmap;
	
	/* Pointer to the root of the red-black tree of memory region objects
 */
	struct rb_root mm_rb;
	
	/* Pointer to the last referenced memory region object */
	struct vm_area_struct * mmap_cache;
	....
};

Linux implements a memory region by means of an object of type vm_area_struct

struct vm_area_struct {
	struct mm_struct * vm_mm;   /* Pointer to the memory descriptor that owns the region */
	unsigned long vm_start;   /* First linear address inside the region */
	unsigned long vm_end;   /* First linear address after the region */
	....
};

Each memory region descriptor identifies a linear address interval; vm_end-vm_startdenotes the length of the memory region. 

All the regions owned by a process are linked in a simple list. 

Regions appear in the list in ascending order by memory address

The vm_next field of each vm_area_structelement points to the next element in the list.



