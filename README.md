# open-dis-objectivec

Implementation of the DIS protocol in Objective-C, a language popular on Apple devices, 
including MacOS, the iPad, and the iPhone.
Initially generated with [XMLPG](http://github.com/open-dis/xmlpg).

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
