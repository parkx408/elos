//
//  trace.h
//  csim
//
//  Created by Nohhyun Park on 4/30/13.
//  Copyright (c) 2013 Nohhyun Park. All rights reserved.
//

#ifndef csim_trace_h
#define csim_trace_h

// XXX: note that the structure of the trace format is not equal across tracefiles.
//      there seems to exists multiple version of seagate trace file format. Ask Dave_Anderson@Seagate for more info. 
typedef struct tr_entry_s {
    char rw;            //RW
    unsigned char dn;   //Disk number
    uint16_t sc;        //Size
    uint32_t lbal;      //Address
    uint32_t lbah;
    uint32_t stl;       //Start Time
    uint32_t sth;
    uint32_t e;         //Elapsed Time
} tr_entry_t;

#endif
