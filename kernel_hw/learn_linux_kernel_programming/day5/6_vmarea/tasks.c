#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/list.h>
#include <linux/mm.h>
#include <linux/mm_types.h>
#include <linux/proc_fs.h>
#include <linux/version.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>

static unsigned int PID = 1;
module_param(PID, uint, 0400);


struct dentry* file_entry(struct file *pfile)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 19, 0)

    return pfile->f_path.dentry;

#else

    return pfile->f_dentry;

#endif

}

void print_vm_file(struct vm_area_struct *vmarea)
{
    struct file             *vmfile = NULL;
    struct dentry           *den = NULL;
	struct dentry           *pPath = NULL;


    char                    file[255];
    char                    *start = NULL, *end = NULL;

    if(vmarea->vm_file == NULL)
    {
        printk("\tit's not a file map\n");
    }
    else //  the vm_files
    {
        vmfile = vmarea->vm_file;
        den = file_entry(vmfile);
        //  i find in linux-kernel-3.16
        //  http://lxr.free-electrons.com/source/include/linux/fs.h?v=3.16#L753
        //  struct path             f_path;
        //  #define f_dentry        f_path.dentry

        //if(p->vm_file->f_path.dentry != NULL)
        if(den != NULL)
        {
		    printk(KERN_CONT"\t");
			memset(file,'\0',sizeof(file));
			//for(pPath = p->vm_file->f_path.dentry;
			for(pPath = den;
                pPath != NULL;
                pPath = pPath->d_parent)
            {

                if(strcmp(pPath->d_name.name, "/") != 0)
                {
                    strcpy(file + strlen(file), pPath->d_name.name);
				    strcpy(file + strlen(file), "/");

                    continue;

                }
                else
                {
                    break;
                }
            }

            do
            {
                end = file + strlen(file) - 1;
				for(start = end - 1; *start != '/' && start > file; start--);

                if(*start == '/')
                {
                    start++;
                }
				*end = '\0';

				printk(KERN_CONT"/%s", start);
				*start = '\0';
			} while(start > file);
		}
        printk("\n");
	}
}

void print_vmarea_node(struct vm_area_struct *vmnode)
{
	printk("0x%lx - 0x%lx\t", vmnode->vm_start, vmnode->vm_end);
	if (vmnode->vm_flags & VM_READ)
		printk(KERN_CONT"r");
	else
		printk(KERN_CONT"-");

	if (vmnode->vm_flags & VM_WRITE)
		printk(KERN_CONT"w");
	else
		printk(KERN_CONT"-");

	if (vmnode->vm_flags & VM_EXEC)
		printk(KERN_CONT"x");
	else
		printk(KERN_CONT"-");

	if (vmnode->vm_flags & VM_SHARED)
		printk(KERN_CONT"s");
	else
		printk(KERN_CONT"p");

    print_vm_file(vmnode);
}


static void print_vm_list(struct vm_area_struct *vmlist)
{
    struct vm_area_struct   *vmnode = vmlist;

    while (vmnode != NULL)
    {
        print_vmarea_node(vmnode);

        vmnode = vmnode->vm_next;
    }
}


void print_mm_struct(struct mm_struct *mm)
{
    printk("code : [0x%lx, 0x%lx]\n", mm->start_code, mm->end_code);
    printk("data : [0x%lx, 0x%lx]\n", mm->start_data, mm->end_data);

    printk("heap : [0x%lx, 0x%lx]\n", mm->start_brk, mm->brk);
    printk("stack: [0x%lx]\n",  mm->start_stack);
    print_vm_list(mm->mmap);
}

static int init_find_task(void)
{
	
	struct task_struct  *task = NULL;

	for_each_process(task) {
		if (task->pid == (pid_t)PID) {
			print_mm_struct(task->mm);
		}
	}

	return 0;
}

static void exit_find_task(void)
{
    printk("GOOD BYE:find_task!!\n");
}

module_init(init_find_task);
module_exit(exit_find_task);

MODULE_LICENSE("GPL");
