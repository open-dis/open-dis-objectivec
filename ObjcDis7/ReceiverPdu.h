#import "EntityID.h"
#import <Foundation/Foundation.h>
#import "RadioCommunicationsFamilyPdu.h"
#import "DataInput.h"
#import "DataOutput.h"


//  Communication of a receiver state. Section 7.7.4 COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG

@interface ReceiverPdu : RadioCommunicationsFamilyPdu
{
  /** encoding scheme used, and enumeration */
  unsigned short receiverState; 

  /** padding */
  unsigned short padding1; 

  /** received power */
  float receivedPoser; 

  /** ID of transmitter */
  EntityID *transmitterEntityId; 

  /** ID of transmitting radio */
  unsigned short transmitterRadioId; 

}

@property(readwrite, assign) unsigned short receiverState; 
@property(readwrite, assign) unsigned short padding1; 
@property(readwrite, assign) float receivedPoser; 
@property(readwrite, retain) EntityID* transmitterEntityId; 
@property(readwrite, assign) unsigned short transmitterRadioId; 

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
