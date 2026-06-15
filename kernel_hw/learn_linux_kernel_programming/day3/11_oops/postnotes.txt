Let's understand the oops message line by line

[ 1086.248952] BUG: unable to handle kernel NULL pointer dereference at 0000000000000012

The above line indicates the BUG which caused the OOPS message, in our case invalid access to memory location

[ 1086.248954] IP: [<ffffffffc03de01e>] test_oops_init+0x1e/0x30 [test]

Instruction Pointer at the time of OOPS

[ 1086.248957] Oops: 0002 [#1] SMP

The error code value (0002) is in Hex. Each bit has a significance of its own.

Bit 0:
Value:  0 -> No Page Found
Value: 1 -> Protection Fault
Bit 1: 
Value :0 -> Read
Value:1 -> Write
Bit 2:
Value:0  -> Kernel
 Value:1 -> User-Mode

[#1] is the number of times the oops occurred. Multiple oops can be triggered as a cascading effect of the first one.

We have value 0002 which is Page not found during write operation in kernel mode.

[ 1086.248959] Modules linked in: test(POE+) snd_ens1371 coretemp snd_ac97_codec gameport ac97_bus snd_pcm crct10dif_pclmul snd_seq_midi crc32_pclmul snd_seq_midi_event vmw_balloon aesni_intel aes_x86_64 lrw gf128mul glue_helper ablk_helper cryptd snd_rawmidi input_leds vmwgfx joydev serio_raw btusb ttm drm_kms_helper btrtl btbcm btintel drm snd_seq snd_seq_device snd_timer fb_sys_fops snd vmw_vmci syscopyarea sysfillrect soundcore sysimgblt i2c_piix4 shpchp nfit rfcomm bnep bluetooth nfsd auth_rpcgss nfs_acl nfs lockd grace sunrpc fscache 8250_fintek parport_pc ppdev mac_hid lp parport hid_generic usbhid hid psmouse mptspi mptscsih mptbase e1000 pata_acpi scsi_transport_spi vmw_pvscsi floppy vmxnet3 fjes

The kernel doesn't necessarily know which module to blame, so it is giving you all of them.

[ 1086.248977] CPU: 0 PID: 4442 Comm: insmod Tainted: P           OE   4.4.0-31-generic #50~14.04.1-Ubuntu

CPU 0 denotes which CPU the error occurred. Next is PID and process name causing OOPS.

The tainted flag points to 'P' here. Each flag has its own meaning. A few other flags, and their meanings, picked up from kernel/panic.c :
/**
 *  print_tainted - return a string to represent the kernel taint state.
 *
 *  'P' - Proprietary module has been loaded.
 *  'F' - Module has been forcibly loaded.
 *  'S' - SMP with CPUs not designed for SMP.
 *  'R' - User forced a module unload.
 *  'M' - System experienced a machine check exception.
 *  'B' - System has hit bad_page.
 *  'U' - Userspace-defined naughtiness.
 *  'D' - Kernel has oopsed before
 *  'A' - ACPI table overridden.
 *  'W' - Taint on warning.
 *  'C' - modules from drivers/staging are loaded.
 *  'I' - Working around severe firmware bug.
 *  'O' - Out-of-tree module has been loaded.
 *  'E' - Unsigned module has been loaded.
 *  'L' - A soft lockup has previously occurred.
 *  'K' - Kernel has been live patched.
 *
 *  The string is overwritten by the next call to print_tainted().
 */

[ 1086.248979] RIP: 0010:[<ffffffffc03de01e>]  [<ffffffffc03de01e>] test_oops_init+0x1e/0x30 [test]

RIP is the CPU register containing the address of the instruction that is getting executed. 0x0010 comes from the code segment register.  test_oops_init+0x1e/0x30 is the symbol + offset/length.


[ 1086.248981] RSP: 0018:ffff8802144e7cc0  EFLAGS: 00010292
[ 1086.248981] RAX: 0000000000000017 RBX: ffffffff81c13080 RCX: 0000000000000000
[ 1086.248982] RDX: 0000000000000001 RSI: ffff880236e0dc78 RDI: ffff880236e0dc78
[ 1086.248982] RBP: ffff8802144e7cc0 R08: 706f6f5f74736574 R09: 203a74696e695f73
[ 1086.248983] R10: 3a74696e695f7370 R11: 000000000000069a R12: ffff8800acc32760
[ 1086.248984] R13: 0000000000000000 R14: ffffffffc03de000 R15: ffff8802144e7eb0
[ 1086.248984] FS:  00007f13440e9740(0000) GS:ffff880236e00000(0000) knlGS:0000000000000000
[ 1086.248986] CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033
[ 1086.248987] CR2: 0000000000000012 CR3: 00000002255ad000 CR4: 00000000000406f0

Dump of the contents of the CPU Registers.

[ 1086.249006] Stack:
[ 1086.249007]  ffff8802144e7d38 ffffffff8100213d ffff8802144e7eb0 ffff8802144e7d10
[ 1086.249008]  0000000000000246 0000000000000002 ffffffff811dbf1d ffff880236803c00
[ 1086.249009]  ffffffff81180f87 0000000000000018 000000001136cd17 ffffffffc03e0000

The above is the stack trace

[ 1086.249011] Call Trace:
[ 1086.249019]  [<ffffffff8100213d>] do_one_initcall+0xcd/0x1f0
[ 1086.249025]  [<ffffffff811dbf1d>] ? kmem_cache_alloc_trace+0x1ad/0x220
[ 1086.249028]  [<ffffffff81180f87>] ? do_init_module+0x27/0x1d2
[ 1086.249030]  [<ffffffff81180fc0>] do_init_module+0x60/0x1d2
[ 1086.249033]  [<ffffffff8110224c>] load_module+0x141c/0x1b00
[ 1086.249034]  [<ffffffff810fea40>] ? __symbol_put+0x40/0x40
[ 1086.249037]  [<ffffffff81203551>] ? kernel_read+0x41/0x60
[ 1086.249038]  [<ffffffff81102afe>] SYSC_finit_module+0x7e/0xa0
[ 1086.249039]  [<ffffffff81102b3e>] SyS_finit_module+0xe/0x10
[ 1086.249045]  [<ffffffff817f6f36>] entry_SYSCALL_64_fastpath+0x16/0x75


The above is the call trace - list of the functions being called just before the OOPS message.

[ 1086.249046] Code: <c7> 04 25 12 00 00 00 61 00 00 00 31 c0 5d c3 0f 1f 00 0f 1f 44 00

The code is a hex-dump of the section of machine code that was being run at the time the oops occurred.

