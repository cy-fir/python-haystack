// Generated by pdbparse v1.1 - -g -w 4 -d heap.structures.winxp.1 /home/other/outputs/pdb/WinXPSP3X86/ntdll.pdb.dll

/******* Define basic Windows types *******/

// If compiling with gcc, use -fms-extensions

#include <stdint.h>

typedef  uint8_t     UINT8;
typedef  uint8_t     UCHAR;
typedef  uint8_t      BOOL;

typedef   int8_t      CHAR;
typedef   int8_t      INT8;

typedef uint16_t     WCHAR;
typedef uint16_t    UINT16;
typedef uint16_t    USHORT;
typedef  int16_t     SHORT;

typedef uint32_t    UINT32;
typedef uint32_t     ULONG;
typedef  int32_t      LONG;

typedef uint64_t    UINT64;
typedef uint64_t ULONGLONG;
typedef  int64_t  LONGLONG;

typedef uint64_t   PVOID64, PPVOID64;
typedef uint32_t   PVOID32, PPVOID32;
typedef     void      VOID;

typedef  double     DOUBLE; // not true but -hey FIXME

#ifdef WINDOWS_USE_32_BIT_POINTERS ///////////////
// pointers occupy exactly 32 bits
typedef  UINT32     PUINT8;
typedef  UINT32     PUCHAR;
typedef  UINT32      PBOOL;

typedef  UINT32      PCHAR;
typedef  UINT32      PINT8;

typedef  UINT32    PUINT16;
typedef  UINT32    PUSHORT;
typedef  UINT32     PSHORT;

typedef  UINT32     PUINT32;
typedef  UINT32      PULONG;
typedef  UINT32       PLONG;

typedef  UINT32     PUINT64;
typedef  UINT32  PULONGLONG;
typedef  UINT32   PLONGLONG;

typedef  UINT32       PVOID, PPVOID;

#else /////////////////  !WINDOWS_USE_32_BIT_POINTERS
// pointers occupy native address width per ABI
typedef     UINT8     *PUINT8;
typedef     UCHAR     *PUCHAR;
typedef      BOOL      *PBOOL;

typedef      CHAR      *PCHAR;
typedef      INT8      *PINT8;

typedef    UINT16    *PUINT16;
typedef    USHORT    *PUSHORT;
typedef     SHORT     *PSHORT;

typedef    UINT32    *PUINT32;
typedef     ULONG     *PULONG;
typedef      LONG      *PLONG;

typedef    UINT64    *PUINT64;
typedef ULONGLONG *PULONGLONG;
typedef  LONGLONG  *PLONGLONG;

typedef      VOID      *PVOID, **PPVOID;

#endif /////////////////  WINDOWS_USE_32_BIT_POINTERS

#define P(basetype, var) ( (basetype *)(var))

/******* circular dependencies *******/
struct _HEAP;
typedef struct _HEAP HEAP;
typedef HEAP *PHEAP, **PPHEAP;

struct _HEAP_LOCK;
typedef struct _HEAP_LOCK HEAP_LOCK;
typedef HEAP_LOCK *PHEAP_LOCK, **PPHEAP_LOCK;

struct _HEAP_SEGMENT;
typedef struct _HEAP_SEGMENT HEAP_SEGMENT;
typedef HEAP_SEGMENT *PHEAP_SEGMENT, **PPHEAP_SEGMENT;

struct _RTL_CRITICAL_SECTION;
typedef struct _RTL_CRITICAL_SECTION RTL_CRITICAL_SECTION;
typedef RTL_CRITICAL_SECTION *PRTL_CRITICAL_SECTION, **PPRTL_CRITICAL_SECTION;

struct _RTL_CRITICAL_SECTION_DEBUG;
typedef struct _RTL_CRITICAL_SECTION_DEBUG RTL_CRITICAL_SECTION_DEBUG;
typedef RTL_CRITICAL_SECTION_DEBUG *PRTL_CRITICAL_SECTION_DEBUG, **PPRTL_CRITICAL_SECTION_DEBUG;

/******* Enumerations *******/
/*******  Structures  *******/
typedef struct _LIST_ENTRY { // 0x8 bytes
	struct _LIST_ENTRY*  Flink;                       // offset   0x0 size   0x4
	struct _LIST_ENTRY*  Blink;                       // offset   0x4 size   0x4

} __attribute__((packed)) LIST_ENTRY, *PLIST_ENTRY, **PPLIST_ENTRY ;

typedef struct _HEAP_UNCOMMMTTED_RANGE { // 0x10 bytes
	struct _HEAP_UNCOMMMTTED_RANGE*  Next;            // offset   0x0 size   0x4
	ULONG Address;                                    // offset   0x4 size   0x4
	ULONG Size;                                       // offset   0x8 size   0x4
	ULONG filler;                                     // offset   0xc size   0x4

} __attribute__((packed)) HEAP_UNCOMMMTTED_RANGE, *PHEAP_UNCOMMMTTED_RANGE, **PPHEAP_UNCOMMMTTED_RANGE ;

typedef struct _HEAP_ENTRY { // 0x8 bytes
union {
	struct {
		USHORT Size;                                     // offset   0x0 size   0x2
		USHORT PreviousSize;                             // offset   0x2 size   0x2
	};
	struct {
		PVOID SubSegmentCode;                            // offset   0x0 size   0x4
		UCHAR SmallTagIndex;                             // offset   0x4 size   0x1
		UCHAR Flags;                                     // offset   0x5 size   0x1
		UCHAR UnusedBytes;                               // offset   0x6 size   0x1
		volatile UCHAR SegmentIndex;                     // offset   0x7 size   0x1
	};
};
} __attribute__((packed)) HEAP_ENTRY, *PHEAP_ENTRY, **PPHEAP_ENTRY ;

typedef struct _HEAP_TAG_ENTRY { // 0x40 bytes
	ULONG Allocs;                                     // offset   0x0 size   0x4
	ULONG Frees;                                      // offset   0x4 size   0x4
	ULONG Size;                                       // offset   0x8 size   0x4
	USHORT TagIndex;                                  // offset   0xc size   0x2
	USHORT CreatorBackTraceIndex;                     // offset   0xe size   0x2
	USHORT TagName[0x18];                             // offset  0x10 size  0x30

} __attribute__((packed)) HEAP_TAG_ENTRY, *PHEAP_TAG_ENTRY, **PPHEAP_TAG_ENTRY ;

typedef struct _OWNER_ENTRY { // 0x8 bytes
	ULONG OwnerThread;                                // offset   0x0 size   0x4
	union {
		LONG OwnerCount;                                 // offset   0x4 size   0x4
		ULONG TableSize;                                 // offset   0x4 size   0x4
	};

} __attribute__((packed)) OWNER_ENTRY, *POWNER_ENTRY, **PPOWNER_ENTRY ;

typedef struct _HEAP_PSEUDO_TAG_ENTRY { // 0xc bytes
	ULONG Allocs;                                     // offset   0x0 size   0x4
	ULONG Frees;                                      // offset   0x4 size   0x4
	ULONG Size;                                       // offset   0x8 size   0x4

} __attribute__((packed)) HEAP_PSEUDO_TAG_ENTRY, *PHEAP_PSEUDO_TAG_ENTRY, **PPHEAP_PSEUDO_TAG_ENTRY ;

typedef struct _SINGLE_LIST_ENTRY { // 0x4 bytes
	struct _SINGLE_LIST_ENTRY*  Next;                 // offset   0x0 size   0x4

} __attribute__((packed)) SINGLE_LIST_ENTRY, *PSINGLE_LIST_ENTRY, **PPSINGLE_LIST_ENTRY ;

typedef struct _HEAP_UCR_SEGMENT { // 0x10 bytes
	struct _HEAP_UCR_SEGMENT*  Next;                  // offset   0x0 size   0x4
	ULONG ReservedSize;                               // offset   0x4 size   0x4
	ULONG CommittedSize;                              // offset   0x8 size   0x4
	ULONG filler;                                     // offset   0xc size   0x4

} __attribute__((packed)) HEAP_UCR_SEGMENT, *PHEAP_UCR_SEGMENT, **PPHEAP_UCR_SEGMENT ;

typedef union _SLIST_HEADER { // 0x8 bytes
	ULONGLONG Alignment;                              // offset   0x0 size   0x8
	struct {
		SINGLE_LIST_ENTRY Next;                          // offset   0x0 size   0x4
		USHORT Depth;                                    // offset   0x4 size   0x2
		USHORT Sequence;                                 // offset   0x6 size   0x2
	};

} __attribute__((packed)) SLIST_HEADER, *PSLIST_HEADER, **PPSLIST_HEADER ;

typedef struct _DISPATCHER_HEADER { // 0x10 bytes
	UCHAR Type;                                       // offset   0x0 size   0x1
	UCHAR Absolute;                                   // offset   0x1 size   0x1
	UCHAR Size;                                       // offset   0x2 size   0x1
	UCHAR Inserted;                                   // offset   0x3 size   0x1
	LONG SignalState;                                 // offset   0x4 size   0x4
	LIST_ENTRY WaitListHead;                          // offset   0x8 size   0x8

} __attribute__((packed)) DISPATCHER_HEADER, *PDISPATCHER_HEADER, **PPDISPATCHER_HEADER ;

typedef struct _KEVENT { // 0x10 bytes
	DISPATCHER_HEADER Header;                         // offset   0x0 size  0x10

} __attribute__((packed)) KEVENT, *PKEVENT, **PPKEVENT ;

typedef struct _KSEMAPHORE { // 0x14 bytes
	DISPATCHER_HEADER Header;                         // offset   0x0 size  0x10
	LONG Limit;                                       // offset  0x10 size   0x4

} __attribute__((packed)) KSEMAPHORE, *PKSEMAPHORE, **PPKSEMAPHORE ;

typedef struct _HEAP_FREE_ENTRY { // 0x10 bytes
union {
	struct {
		USHORT Size;                                     // offset   0x0 size   0x2
		USHORT PreviousSize;                             // offset   0x2 size   0x2
	};
	struct {
		PVOID SubSegmentCode;                            // offset   0x0 size   0x4
		UCHAR SmallTagIndex;                             // offset   0x4 size   0x1
		UCHAR Flags;                                     // offset   0x5 size   0x1
		UCHAR UnusedBytes;                               // offset   0x6 size   0x1
		volatile UCHAR SegmentIndex;                     // offset   0x7 size   0x1
		LIST_ENTRY FreeList;                             // offset   0x8 size   0x8
	};
};
} __attribute__((packed)) HEAP_FREE_ENTRY, *PHEAP_FREE_ENTRY, **PPHEAP_FREE_ENTRY ;

typedef struct _ERESOURCE { // 0x38 bytes
	LIST_ENTRY SystemResourcesList;                   // offset   0x0 size   0x8
	POWNER_ENTRY OwnerTable;                          // offset   0x8 size   0x4
	SHORT ActiveCount;                                // offset   0xc size   0x2
	USHORT Flag;                                      // offset   0xe size   0x2
	PKSEMAPHORE SharedWaiters;                        // offset  0x10 size   0x4
	PKEVENT ExclusiveWaiters;                         // offset  0x14 size   0x4
	OWNER_ENTRY OwnerThreads[0x2];                    // offset  0x18 size  0x10
	ULONG ContentionCount;                            // offset  0x28 size   0x4
	USHORT NumberOfSharedWaiters;                     // offset  0x2c size   0x2
	USHORT NumberOfExclusiveWaiters;                  // offset  0x2e size   0x2
	union {
		PVOID Address;                                   // offset  0x30 size   0x4
		ULONG CreatorBackTraceIndex;                     // offset  0x30 size   0x4
	};
	ULONG SpinLock;                                   // offset  0x34 size   0x4

} __attribute__((packed)) ERESOURCE, *PERESOURCE, **PPERESOURCE ;

typedef struct _RTL_CRITICAL_SECTION { // 0x18 bytes
	PRTL_CRITICAL_SECTION_DEBUG DebugInfo;            // offset   0x0 size   0x4
	LONG LockCount;                                   // offset   0x4 size   0x4
	LONG RecursionCount;                              // offset   0x8 size   0x4
	PVOID OwningThread;                               // offset   0xc size   0x4
	PVOID LockSemaphore;                              // offset  0x10 size   0x4
	ULONG SpinCount;                                  // offset  0x14 size   0x4

} __attribute__((packed)) RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION, **PPRTL_CRITICAL_SECTION ;

typedef struct _HEAP_LOCK { // 0x38 bytes
	union {
	RTL_CRITICAL_SECTION CriticalSection;             // offset   0x0 size  0x18
	ERESOURCE Resource;                               // offset   0x0 size  0x38
} Lock; // offset   0x0 size  0x38

} __attribute__((packed)) HEAP_LOCK, *PHEAP_LOCK, **PPHEAP_LOCK ;

typedef struct _HEAP_SEGMENT { // 0x3c bytes
	HEAP_ENTRY Entry;                                 // offset   0x0 size   0x8
	ULONG Signature;                                  // offset   0x8 size   0x4
	ULONG Flags;                                      // offset   0xc size   0x4
	PHEAP Heap;                                       // offset  0x10 size   0x4
	ULONG LargestUnCommittedRange;                    // offset  0x14 size   0x4
	PVOID BaseAddress;                                // offset  0x18 size   0x4
	ULONG NumberOfPages;                              // offset  0x1c size   0x4
	PHEAP_ENTRY FirstEntry;                           // offset  0x20 size   0x4
	PHEAP_ENTRY LastValidEntry;                       // offset  0x24 size   0x4
	ULONG NumberOfUnCommittedPages;                   // offset  0x28 size   0x4
	ULONG NumberOfUnCommittedRanges;                  // offset  0x2c size   0x4
	PHEAP_UNCOMMMTTED_RANGE UnCommittedRanges;        // offset  0x30 size   0x4
	USHORT AllocatorBackTraceIndex;                   // offset  0x34 size   0x2
	USHORT Reserved;                                  // offset  0x36 size   0x2
	PHEAP_ENTRY LastEntryInSegment;                   // offset  0x38 size   0x4

} __attribute__((packed)) HEAP_SEGMENT, *PHEAP_SEGMENT, **PPHEAP_SEGMENT ;

typedef struct _RTL_CRITICAL_SECTION_DEBUG { // 0x20 bytes
	USHORT Type;                                      // offset   0x0 size   0x2
	USHORT CreatorBackTraceIndex;                     // offset   0x2 size   0x2
	PRTL_CRITICAL_SECTION CriticalSection;            // offset   0x4 size   0x4
	LIST_ENTRY ProcessLocksList;                      // offset   0x8 size   0x8
	ULONG EntryCount;                                 // offset  0x10 size   0x4
	ULONG ContentionCount;                            // offset  0x14 size   0x4
	ULONG Spare[0x2];                                 // offset  0x18 size   0x8

} __attribute__((packed)) RTL_CRITICAL_SECTION_DEBUG, *PRTL_CRITICAL_SECTION_DEBUG, **PPRTL_CRITICAL_SECTION_DEBUG ;

typedef struct _HEAP { // 0x588 bytes
	HEAP_ENTRY Entry;                                 // offset   0x0 size   0x8
	ULONG Signature;                                  // offset   0x8 size   0x4
	ULONG Flags;                                      // offset   0xc size   0x4
	ULONG ForceFlags;                                 // offset  0x10 size   0x4
	ULONG VirtualMemoryThreshold;                     // offset  0x14 size   0x4
	ULONG SegmentReserve;                             // offset  0x18 size   0x4
	ULONG SegmentCommit;                              // offset  0x1c size   0x4
	ULONG DeCommitFreeBlockThreshold;                 // offset  0x20 size   0x4
	ULONG DeCommitTotalFreeThreshold;                 // offset  0x24 size   0x4
	ULONG TotalFreeSize;                              // offset  0x28 size   0x4
	ULONG MaximumAllocationSize;                      // offset  0x2c size   0x4
	USHORT ProcessHeapsListIndex;                     // offset  0x30 size   0x2
	USHORT HeaderValidateLength;                      // offset  0x32 size   0x2
	PVOID HeaderValidateCopy;                         // offset  0x34 size   0x4
	USHORT NextAvailableTagIndex;                     // offset  0x38 size   0x2
	USHORT MaximumTagIndex;                           // offset  0x3a size   0x2
	PHEAP_TAG_ENTRY TagEntries;                       // offset  0x3c size   0x4
	PHEAP_UCR_SEGMENT UCRSegments;                    // offset  0x40 size   0x4
	PHEAP_UNCOMMMTTED_RANGE UnusedUnCommittedRanges;  // offset  0x44 size   0x4
	ULONG AlignRound;                                 // offset  0x48 size   0x4
	ULONG AlignMask;                                  // offset  0x4c size   0x4
	LIST_ENTRY VirtualAllocdBlocks;                   // offset  0x50 size   0x8
	PHEAP_SEGMENT Segments[0x40];                     // offset  0x58 size 0x100
	union {
	ULONG FreeListsInUseUlong[0x4];                   // offset   0x0 size  0x10
	UCHAR FreeListsInUseBytes[0x10];                  // offset   0x0 size  0x10
} u; // offset 0x158 size  0x10
	union {
	USHORT FreeListsInUseTerminate;                   // offset   0x0 size   0x2
	USHORT DecommitCount;                             // offset   0x0 size   0x2
} u2; // offset 0x168 size   0x2
	USHORT AllocatorBackTraceIndex;                   // offset 0x16a size   0x2
	ULONG NonDedicatedListLength;                     // offset 0x16c size   0x4
	PVOID LargeBlocksIndex;                           // offset 0x170 size   0x4
	PHEAP_PSEUDO_TAG_ENTRY PseudoTagEntries;          // offset 0x174 size   0x4
	LIST_ENTRY FreeLists[0x80];                       // offset 0x178 size 0x400
	PHEAP_LOCK LockVariable;                          // offset 0x578 size   0x4
	LONG (*CommitRoutine)(PVOID, PPVOID, PULONG);     // offset 0x57c size   0x4
	PVOID FrontEndHeap;                               // offset 0x580 size   0x4
	USHORT FrontHeapLockCount;                        // offset 0x584 size   0x2
	UCHAR FrontEndHeapType;                           // offset 0x586 size   0x1
	UCHAR LastSegmentIndex;                           // offset 0x587 size   0x1

} __attribute__((packed)) HEAP, *PHEAP, **PPHEAP ;


