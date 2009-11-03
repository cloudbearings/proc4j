#include "../proc4j_common.h"
#include <stdio.h>
#include <stdlib.h>
#include <Carbon/Carbon.h>

proc4j_process_list_t* proc4j_get_process_list() {
    ProcessSerialNumber process;
    process.highLongOfPSN = kNoProcess;
	process.lowLongOfPSN  = kNoProcess;

    FSSpec appFSSpec;

	ProcessInfoRec procInfo;
    procInfo.processInfoLength = sizeof(ProcessInfoRec);
//    procInfo.processName = procName;
//    procInfo.processAppSpec = &appFSSpec;
//	while (procNotFound != (osErr = GetNextProcess(&process))) {
//		if (noErr == (osErr = GetProcessInformation(&process, &procInfo))) {
//
//            //copy process name to c string
//            size = (unsigned int) procName[0];
//            memcpy(cstrProcName, procName + 1, size);
//            cstrProcName[size] = '\0';
//
//			printf(
//				"%-33s %08lx.%08lx '%c%c%c%c'  '%c%c%c%c'  %08lx %08lx %08lx %08lx %08lx.%08lx %2d/%2d/%2d %2d:%02d:%02d\n",
//				cstrProcName,
//				procInfo.processNumber.highLongOfPSN,
//				procInfo.processNumber.lowLongOfPSN,
//				((char *) &procInfo.processType)[0],
//				((char *) &procInfo.processType)[1],
//				((char *) &procInfo.processType)[2],
//				((char *) &procInfo.processType)[3],
//				((char *) &procInfo.processSignature)[0],
//				((char *) &procInfo.processSignature)[1],
//				((char *) &procInfo.processSignature)[2],
//				((char *) &procInfo.processSignature)[3],
//				procInfo.processMode,
//				(unsigned long) procInfo.processLocation,
//				procInfo.processSize,
//				procInfo.processFreeMem,
//				procInfo.processLauncher.highLongOfPSN,
//				procInfo.processLauncher.lowLongOfPSN,
//				launchDateTime.month,
//				launchDateTime.day,
//				launchDateTime.year,
//				launchDateTime.hour,
//				launchDateTime.minute,
//				launchDateTime.second
//			);
//		}
//	}

    proc4j_process_list_t *res = proc4j_new_process_list();
    proc4j_process_t internalProcess;
    internalProcess.name = "Test2";
    internalProcess.id = 1;
    proc4j_process_list_put(res, internalProcess);
    internalProcess.name = "Test3";
    internalProcess.id = 2;
    proc4j_process_list_put(res, internalProcess);
    return res;
}