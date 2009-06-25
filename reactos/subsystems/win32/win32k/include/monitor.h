#ifndef _WIN32K_MONITOR_H
#define _WIN32K_MONITOR_H

//struct PDEVOBJ;

/* monitor object */
typedef struct _MONITOR_OBJECT
{
	HANDLE         Handle;     /* system object handle */
	FAST_MUTEX     Lock;       /* R/W lock */

	BOOL           IsPrimary;  /* wether this is the primary monitor */
	UNICODE_STRING DeviceName; /* name of the monitor */
	PDEVOBJ     *GdiDevice;  /* pointer to the GDI device to
	                              which this monitor is attached */
	struct _MONITOR_OBJECT *Prev, *Next; /* doubly linked list */

	// This is the structure Windows uses:
//    HEAD head;
//    struct _MONITOR_OBJECT *pMonitorNext;
//    DWORD   dwMONFlags;
    RECT    rcMonitor;
    RECT    rcWork;
//    HRGN    hrgnMonitor;
//    SHORT   Spare0;
//    SHORT   cWndStack;
//    HDEV    hDev;
//    HDEV    hDevReal;
//    BYTE    DockTargets[4][7];
//    struct _MONITOR_OBJECT* Flink;
//    struct _MONITOR_OBJECT* Blink;
} MONITOR_OBJECT, *PMONITOR_OBJECT;

/* functions */
NTSTATUS InitMonitorImpl();
NTSTATUS CleanupMonitorImpl();

NTSTATUS IntAttachMonitor(PDEVOBJ *pGdiDevice, ULONG DisplayNumber);
NTSTATUS IntDetachMonitor(PDEVOBJ *pGdiDevice);
PMONITOR_OBJECT FASTCALL UserGetMonitorObject(IN HMONITOR);

#endif /* _WIN32K_MONITOR_H */

/* EOF */
