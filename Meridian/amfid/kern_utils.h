#import <stdio.h>
#import <mach/mach.h>
#import <mach/error.h>
#import <mach/message.h>
#import <CoreFoundation/CoreFoundation.h>

kern_return_t mach_vm_read(vm_map_t target_task,
						   mach_vm_address_t address,
						   mach_vm_size_t size,
						   vm_offset_t *data,
						   mach_msg_type_number_t *dataCnt);

kern_return_t mach_vm_write(vm_map_t target_task,
                            mach_vm_address_t address,
                            vm_offset_t data,
                            mach_msg_type_number_t dataCnt);

kern_return_t mach_vm_read_overwrite(vm_map_t target_task,
                                     mach_vm_address_t address,
                                     mach_vm_size_t size,
                                     mach_vm_address_t data,
                                     mach_vm_size_t *outsize);

kern_return_t mach_vm_region(vm_map_t target_task,
                             mach_vm_address_t *address,
                             mach_vm_size_t *size,
                             vm_region_flavor_t flavor,
                             vm_region_info_t info,
                             mach_msg_type_number_t *infoCnt,
                             mach_port_t *object_name);

/****** IOKit/IOKitLib.h *****/
typedef mach_port_t io_service_t;
typedef mach_port_t io_connect_t;

extern const mach_port_t kIOMasterPortDefault;
#define IO_OBJECT_NULL (0)

kern_return_t
IOConnectCallAsyncMethod(
						 mach_port_t     connection,
						 uint32_t        selector,
						 mach_port_t     wakePort,
						 uint64_t*       reference,
						 uint32_t        referenceCnt,
						 const uint64_t* input,
						 uint32_t        inputCnt,
						 const void*     inputStruct,
						 size_t          inputStructCnt,
						 uint64_t*       output,
						 uint32_t*       outputCnt,
						 void*           outputStruct,
						 size_t*         outputStructCntP);

kern_return_t
IOConnectCallMethod(
					mach_port_t     connection,
					uint32_t        selector,
					const uint64_t* input,
					uint32_t        inputCnt,
					const void*     inputStruct,
					size_t          inputStructCnt,
					uint64_t*       output,
					uint32_t*       outputCnt,
					void*           outputStruct,
					size_t*         outputStructCntP);

io_service_t
IOServiceGetMatchingService(
							mach_port_t  _masterPort,
							CFDictionaryRef  matching);

CFMutableDictionaryRef
IOServiceMatching(
				  const char* name);

kern_return_t
IOServiceOpen(
			  io_service_t  service,
			  task_port_t   owningTask,
			  uint32_t      type,
			  io_connect_t* connect );

kern_return_t IOConnectTrap6(io_connect_t connect, uint32_t index, uintptr_t p1, uintptr_t p2, uintptr_t p3, uintptr_t p4, uintptr_t p5, uintptr_t p6);
kern_return_t mach_vm_read_overwrite(vm_map_t target_task, mach_vm_address_t address, mach_vm_size_t size, mach_vm_address_t data, mach_vm_size_t *outsize);
kern_return_t mach_vm_write(vm_map_t target_task, mach_vm_address_t address, vm_offset_t data, mach_msg_type_number_t dataCnt);
kern_return_t mach_vm_allocate(vm_map_t target, mach_vm_address_t *address, mach_vm_size_t size, int flags);
kern_return_t mach_vm_deallocate(vm_map_t target, mach_vm_address_t address, mach_vm_size_t size);

extern mach_port_t tfp0;
extern uint64_t kernel_base;
extern uint64_t kernel_slide;
extern uint64_t offset_zonemap;
extern uint64_t offset_kernel_task;
extern uint64_t offset_vfs_context_current;
extern uint64_t offset_vnode_getfromfd;
extern uint64_t offset_vnode_getattr;
extern uint64_t offset_vnode_put;
extern uint64_t offset_csblob_ent_dict_set;
extern uint64_t offset_sha1_init;
extern uint64_t offset_sha1_update;
extern uint64_t offset_sha1_final;
extern uint64_t offset_add_x0_x0_0x40_ret;
extern uint64_t offset_osboolean_true;
extern uint64_t offset_osboolean_false;
extern uint64_t offset_osunserialize_xml;
extern uint64_t offset_cs_find_md;

uint64_t proc_find(int pid, int tries);
uint64_t find_port(mach_port_name_t port);
