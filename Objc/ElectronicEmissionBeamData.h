#import "FundamentalParameterData.h"
#import "TrackJamTarget.h"
#import <Foundation/Foundation.h>
#import "DataInput.h"
#import "DataOutput.h"


// Description of one electronic emission beam

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG

@interface  ElectronicEmissionBeamData: NSObject
{
  /** This field shall specify the length of this beams data in 32 bit words */
  unsigned char beamDataLength; 

  /** This field shall specify a unique emitter database number assigned to differentiate between otherwise similar or identical emitter beams within an emitter system. */
  unsigned char beamIDNumber; 

  /** This field shall specify a Beam Parameter Index number that shall be used by receiving entities in conjunction with the Emitter Name field to provide a pointer to the stored database parameters required to regenerate the beam.  */
  unsigned short beamParameterIndex; 

  /** Fundamental parameter data such as frequency range, beam sweep, etc. */
  FundamentalParameterData *fundamentalParameterData; 

  /** beam function of a particular beam */
  unsigned char beamFunction; 

  /** Number of track/jam targets */
  unsigned char numberOfTrackJamTargets; 

  /** wheher or not the receiving simulation apps can assume all the targets in the scan pattern are being tracked/jammed */
  unsigned char highDensityTrackJam; 

  /** padding */
  unsigned char pad4; 

  /** identify jamming techniques used */
  unsigned int jammingModeSequence; 

  /** variable length list of track/jam targets */
  NSMutableArray *trackJamTargets; 

}

@property(readwrite, assign) unsigned char beamDataLength; 
@property(readwrite, assign) unsigned char beamIDNumber; 
@property(readwrite, assign) unsigned short beamParameterIndex; 
@property(readwrite, retain) FundamentalParameterData* fundamentalParameterData; 
@property(readwrite, assign) unsigned char beamFunction; 
@property(readwrite, assign) unsigned char numberOfTrackJamTargets; 
@property(readwrite, assign) unsigned char highDensityTrackJam; 
@property(readwrite, assign) unsigned char pad4; 
@property(readwrite, assign) unsigned int jammingModeSequence; 
@property(readwrite, retain) NSMutableArray*trackJamTargets; 

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
