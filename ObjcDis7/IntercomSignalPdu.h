#import "EntityID.h"
#import "OneByteChunk.h"
#import <Foundation/Foundation.h>
#import "RadioCommunicationsFamilyPdu.h"
#import "DataInput.h"
#import "DataOutput.h"


//  Actual transmission of intercome voice data. Section 7.7.5. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG

@interface IntercomSignalPdu : RadioCommunicationsFamilyPdu
{
  /** entity ID */
  EntityID *entityID; 

  /** ID of communications device */
  unsigned short communicationsDeviceID; 

  /** encoding scheme */
  unsigned short encodingScheme; 

  /** tactical data link type */
  unsigned short tdlType; 

  /** sample rate */
  unsigned int sampleRate; 

  /** data length */
  unsigned short dataLength; 

  /** samples */
  unsigned short samples; 

  /** data bytes */
  NSMutableArray *data; 

}

@property(readwrite, retain) EntityID* entityID; 
@property(readwrite, assign) unsigned short communicationsDeviceID; 
@property(readwrite, assign) unsigned short encodingScheme; 
@property(readwrite, assign) unsigned short tdlType; 
@property(readwrite, assign) unsigned int sampleRate; 
@property(readwrite, assign) unsigned short dataLength; 
@property(readwrite, assign) unsigned short samples; 
@property(readwrite, retain) NSMutableArray*data; 

-(id)init; // Initializer
-(void)dealloc;
-(void)marshalUsingStream:(DataOutput*) dataStream;
-(void)unmarshalUsingStream:(DataInput*) dataStream;

-(int)getMarshalledSize;

@end

// Copyright (c) 1995-2009 held by the author(s).  All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
//  are met:
// 
//  * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// * Neither the names of the Naval Postgraduate School (NPS)
//  Modeling Virtual Environments and Simulation (MOVES) Institute
// (http://www.nps.edu and http://www.MovesInstitute.org)
// nor the names of its contributors may be used to endorse or
//  promote products derived from this software without specific
// prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// AS IS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
