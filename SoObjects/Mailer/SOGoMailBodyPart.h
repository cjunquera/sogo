/*
  Copyright (C) 2005-2017 Inverse inc.
  Copyright (C) 2004-2005 SKYRIX Software AG

  This file is part of SOGo.

  SOGo is free software; you can redistribute it and/or modify it under
  the terms of the GNU Lesser General Public License as published by the
  Free Software Foundation; either version 2, or (at your option) any
  later version.

  SOGo is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
  License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with SOGo; see the file COPYING.  If not, write to the
  Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA
  02111-1307, USA.
*/

#ifndef __Mailer_SOGoMailBodyPart_H__
#define __Mailer_SOGoMailBodyPart_H__

#import <Mailer/SOGoMailBaseObject.h>

/*
  SOGoMailBodyPart
    Parent object: SOGoMailObject or SOGoMailBodyPart
    Child objects: SOGoMailBodyPart's
  
  Represents a MIME part of a mail as retrieved using IMAP4 body structure
  commands in NGImap4.
*/

@class NSString, NSArray;
@class SOGoMailObject;

@interface SOGoMailBodyPart : SOGoMailBaseObject
{
  NSArray  *pathToPart;
  NSString *identifier;
  id       partInfo;
  BOOL     asAttachment;
}

/* hierarchy */

- (SOGoMailObject *) mailObject;

/* IMAP4 */

- (NSString *) bodyPartName;
- (NSArray *) bodyPartPath;
- (NSString *) bodyPartIdentifier;
- (NSString *) filename;

/* part info */

- (id) partInfo;
- (NSData *) fetchBLOB;
- (NSData *) fetchBLOBWithPeek: (BOOL) withPeek;
- (void) setAsAttachment;

/* factory */

+ (Class) bodyPartClassForKey: (NSString *) _key
		    inContext: (id) _ctx;
+ (Class) bodyPartClassForMimeType: (NSString *) mimeType
			 inContext: (id) _ctx;

@end

#endif /* __Mailer_SOGoMailBodyPart_H__ */
