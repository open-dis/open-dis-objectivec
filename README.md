# open-dis-objectivec

Implementation of the DIS protocol in Objective-C, a language popular on Apple devices, 
including MacOS, the iPad, and the iPhone.

The code looks similar to this:

~~~~
@interface  EntityID: NSObject
{
  /** The site ID */
  unsigned short site;

  /** The application ID */
  unsigned short application;

  /** the entity ID */
  unsigned short entity;

}

@property(readwrite, assign) unsigned short site;
@property(readwrite, assign) unsigned short application;
@property(readwrite, assign) unsigned short entity;

-(id)init; // Initializer
-(void)dealloc;
-(void)marshalUsingStream:(DataOutput*) dataStream;
-(void)unmarshalUsingStream:(DataInput*) dataStream;

-(int)getMarshalledSize;

@end
~~~~

The open-dis-objectivec repo uses a submodule git repository that has the XML file description of the protocol
messages, DISDescription. This lets the XML file be shared across multiple language
implementations. If you want to generate source code, as opposed to just
using it, you should pull in the git submodules. Generating source code should be a unusual event
for most users, and is of interest in a practical sense only if you're also changing
around XMLPG, which generates Objective-C source code from the XML description
file.

Pull in the git submodule with

~~~~
git submodule init
git submodule update
~~~~

This clones the repository at https://github.com/open-dis/DISDescription.git and places
it in the DISDescription directory. Once this is present you can re-generate the 
source code.

