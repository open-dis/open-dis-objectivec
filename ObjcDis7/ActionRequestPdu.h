#import "EntityID.h"
#import "EntityID.h"
#import "FixedDatum.h"
#import "VariableDatum.h"
#import <Foundation/Foundation.h>
#import "SimulationManagementFamilyPdu.h"
#import "DataInput.h"
#import "DataOutput.h"


// Section 7.5.7. Request from simulation manager to a managed entity to perform a specified action. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG

@interface ActionRequestPdu : SimulationManagementFamilyPdu
{
  /** Identifier for originating entity(or simulation) */
  EntityID *originatingID; 

  /** Identifier for the receiving entity(or simulation) */
  EntityID *receivingID; 

  /** identifies the request being made by the simulaton manager */
  unsigned int requestID; 

  /** identifies the particular action being requested(see Section 7 of SISO-REF-010). */
  unsigned int actionID; 

  /** Number of fixed datum records */
  unsigned int numberOfFixedDatumRecords; 

  /** Number of variable datum records */
  unsigned int numberOfVariableDatumRecords; 

  /** variable length list of fixed datums */
  NSMutableArray *fixedDatums; 

  /** variable length list of variable length datums */
  NSMutableArray *variableDatums; 

}

@property(readwrite, retain) EntityID* originatingID; 
@property(readwrite, retain) EntityID* receivingID; 
@property(readwrite, assign) unsigned int requestID; 
@property(readwrite, assign) unsigned int actionID; 
@property(readwrite, assign) unsigned int numberOfFixedDatumRecords; 
@property(readwrite, assign) unsigned int numberOfVariableDatumRecords; 
@property(readwrite, retain) NSMutableArray*fixedDatums; 
@property(readwrite, retain) NSMutableArray*variableDatums; 

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
